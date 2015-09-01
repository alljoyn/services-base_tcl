import os
import platform
import re

def IsBuildingBinaries():
    if BUILD_TARGETS == []:
        return True
    for t in BUILD_TARGETS:
        if t.startswith('dist/lib') or t.startswith('dist/bin'):
            return True
    return False

#######################################################
# Custom Configure functions
#######################################################
def CheckCommand(context, cmd):
    context.Message('Checking for %s command...' % cmd)
    r = WhereIs(cmd)
    context.Result(r is not None)
    return r

def CheckAJLib(context, ajlib, ajheader, sconsvarname, ajdistpath):
    prog = "#include <%s>\nint main(void) { return 0; }" % ajheader
    context.Message('Checking for AllJoyn library %s...' % ajlib)

    prevLIBS = list(context.env.get('LIBS', []))
    prevLIBPATH = list(context.env.get('LIBPATH', []))
    prevCPPPATH = list(context.env.get('CPPPATH', []))

    # Check if library is in standard system locations
    context.env.Prepend(LIBS = [ajlib])
    defpath = ''  # default path is a system directory
    if not context.TryLink(prog, '.c'):
        # Check if library is in project default location
        context.env.Append(LIBPATH = ajdistpath + '/lib', CPPPATH = ajdistpath + '/include')
        if context.TryLink(prog, '.c'):
            defpath = ajdistpath  # default path is the dist directory
        # Remove project default location from LIBPATH and CPPPATH
        context.env.Replace(LIBPATH = prevLIBPATH, CPPPATH = prevCPPPATH)

    vars = Variables()
    vars.Add(PathVariable(sconsvarname,
                          'Path to %s dist directory' % ajlib,
                          os.environ.get('AJ_%s' % sconsvarname, defpath),
                          lambda k, v, e : v == '' or PathVariable.PathIsDir(k, v, e)))
    vars.Update(context.env)
    Help(vars.GenerateHelpText(context.env))

    # Get the actual library path to use ('' == system path, may be same as ajdistpath)
    libpath = env.get(sconsvarname, '')
    if libpath is not '':
        libpath = str(context.env.Dir(libpath))
        # Add the user specified (or ajdistpath) to LIBPATH and CPPPATH
        context.env.Append(LIBPATH = libpath + '/lib', CPPPATH = libpath + '/include')

    # The real test for the library
    r = context.TryLink(prog, '.c')
    if not r:
        context.env.Replace(LIBS = prevLIBS, LIBPATH = prevLIBPATH, CPPPATH = prevCPPPATH)
    context.Result(r)
    return r

#######################################################
# Initialize our build environment
#######################################################
env = Environment()
Export('env')

#######################################################
# Default target platform
#######################################################
if platform.system() == 'Linux':
    default_target = 'linux'
elif platform.system() == 'Windows':
    default_target = 'win32'
elif platform.system() == 'Darwin':
    default_target = 'darwin'

#######################################################
# Build variables
#######################################################
target_options = [ t.split('.')[-1] for t in os.listdir('.') if re.match('^SConscript\.target\.[-_0-9A-Za-z]+$', t) ]

vars = Variables()
vars.Add(BoolVariable('V',                  'Build verbosity',            False))
vars.Add(EnumVariable('TARG',               'Target platform variant',    os.environ.get('AJ_TARG',               default_target),     allowed_values = target_options))
vars.Add(EnumVariable('VARIANT',            'Build variant',              os.environ.get('AJ_VARIANT',            'debug'),            allowed_values = ('debug', 'release')))
vars.Add(BoolVariable('TIME_SERVICE',       'Enable Time Service',        False))
vars.Add('CC',  'C Compiler override')
vars.Add('CXX', 'C++ Compiler override')
vars.Add(EnumVariable('NDEBUG', 'Override NDEBUG default for release variant', 'defined', allowed_values=('defined', 'undefined')))
vars.Update(env)
Help(vars.GenerateHelpText(env))

#######################################################
# Setup non-verbose output
#######################################################
if not env['V']:
    env.Replace( CCCOMSTR =     '\t[CC]      $SOURCE',
                 SHCCCOMSTR =   '\t[CC-SH]   $SOURCE',
                 CXXCOMSTR =    '\t[CXX]     $SOURCE',
                 SHCXXCOMSTR =  '\t[CXX-SH]  $SOURCE',
                 LINKCOMSTR =   '\t[LINK]    $TARGET',
                 SHLINKCOMSTR = '\t[LINK-SH] $TARGET',
                 JAVACCOMSTR =  '\t[JAVAC]   $SOURCE',
                 JARCOMSTR =    '\t[JAR]     $TARGET',
                 ARCOMSTR =     '\t[AR]      $TARGET',
                 ASCOMSTR =     '\t[AS]      $TARGET',
                 RANLIBCOMSTR = '\t[RANLIB]  $TARGET',
                 INSTALLSTR =   '\t[INSTALL] $TARGET',
                 WSCOMSTR =     '\t[WS]      $WS' )

#######################################################
# Load target setup
#######################################################
env['build'] = True
env['build_shared'] = False
env['build_unit_tests'] = True

env.SConscript('SConscript.target.$TARG')

#######################################################
# Check dependencies
#######################################################
config = Configure(env, custom_tests = { 'CheckCommand' : CheckCommand,
                                         'CheckAJLib' : CheckAJLib })
found_ws = config.CheckCommand('uncrustify')
dep_libs = [
    config.CheckAJLib('ajtcl', 'ajtcl/aj_bus.h', 'AJTCL_DIST', '../../core/ajtcl/dist')
]
env['enable_onboarding'] = config.CheckFunc('AJ_EnableSoftAP', 'aj_wifi_ctrl.h', 'c')
env = config.Finish()

#######################################################
# Compilation defines
#######################################################
env.Append(CPPDEFINES = [ 'CONFIG_SERVICE',
                          'CONTROLPANEL_SERVICE',
                          'NOTIFICATION_SERVICE_PRODUCER'
                          ])
if env['TIME_SERVICE']:
    env.Append(CPPDEFINES = [ 'TIME_SERVICE_CLIENT',
                              'TIME_SERVICE_SERVER' ])

if env['VARIANT'] == 'release' and env['NDEBUG'] == 'defined':
    env.Append(CPPDEFINES = [ 'NDEBUG' ])
if env['enable_onboarding']:
    env.Append(CPPDEFINES = 'ONBOARDING_SERVICE')


#######################################################
# Include path
#######################################################
env.Append(CPPPATH = [ '#dist/include' ])

#######################################################
# Process commandline defines
#######################################################
env.Append(CPPDEFINES = [ v for k, v in ARGLIST if k.lower() == 'define' ])

#######################################################
# Install header files
#######################################################
env.Install('#dist/include/ajtcl/services', env.Glob('inc/*.h'))
env.Install('#dist/include/ajtcl/services/Common', env.Glob('inc/Common/*.h'))
env.Install('#dist/include/ajtcl/services/Widgets', env.Glob('inc/Widgets/*.h'))
# Need to force a dpendency here because SCons can't follow nested
# #include dependencies otherwise
env.Depends('#build/$VARIANT', '#dist/include')

#######################################################
# Build the various parts
#######################################################
if env['build'] and all(dep_libs):
    env.SConscript('src/SConscript',     variant_dir='#build/$VARIANT/src',     duplicate = 0)
    env.SConscript('samples/SConscript', variant_dir='#build/$VARIANT/samples', duplicate = 0)
    env.SConscript('test/SConscript',    variant_dir='#build/$VARIANT/test',    duplicate = 0)


if not env.GetOption('help') and not all(dep_libs) and IsBuildingBinaries():
    print 'Missing required external libraries'
    Exit(1)

#######################################################
# Run the whitespace checker
#######################################################
# Set the location of the uncrustify config file
if found_ws:
    import sys
    sys.path.append(os.getcwd() + '/tools')
    import whitespace

    def wsbuild(target, source, env):
        return whitespace.main([ env['WS'], os.getcwd() + '/tools/ajuncrustify.cfg' ])

    vars = Variables()
    vars.Add(EnumVariable('WS', 'Whitespace Policy Checker', os.environ.get('AJ_WS', 'check'), allowed_values = ('check', 'detail', 'fix', 'off')))

    vars.Update(config.env)
    Help(vars.GenerateHelpText(config.env))

    if env.get('WS', 'off') != 'off':
        env.Command('#ws_ajtcl', '#dist', Action(wsbuild, '$WSCOMSTR'))
