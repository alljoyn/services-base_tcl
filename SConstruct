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

def SetupDistEnvironment(config, ajlib, ajheader, sconsvarname, ajdistpath):
    prog = "#include <%s>\nint main(void) { return 0; }" % ajheader
    # Check if library is in standard system locations
    config.env.Prepend(LIBS = [ajlib])
    defpath = ''  # default path is a system directory
    if not config.TryLink(prog, '.c'):
        # Check if library is in project default location
        old_env = config.env
        config.env = config.env.Clone()
        config.env.MergeFlags({ 'CPPPATH' : [ ajdistpath + '/include' ], 'LIBPATH' : [ ajdistpath + '/lib' ] })
        if config.TryLink(prog, '.c'):
            defpath = ajdistpath  # default path is the dist directory
        config.env = old_env
    vars = Variables()
    vars.Add(PathVariable(sconsvarname,
                          'Path to %s dist directory' % ajlib,
                          os.environ.get('AJ_%s' % sconsvarname, defpath),
                          lambda k, v, e : v == '' or PathVariable.PathIsDir(k, v, e)))
    vars.Update(config.env)
    Help(vars.GenerateHelpText(config.env))

def CheckAJLib(context, ajlib, ajheader, sconsvarname):
    prog = "#include <%s>\nint main(void) { return 0; }" % ajheader
    context.Message('Checking for AllJoyn library %s...' % ajlib)
    context.env.Prepend(LIBS = [ajlib])

    # Get the actual library path to use ('' == system path, may be same as ajdistpath)
    distpath = context.env.get(sconsvarname, '')
    if distpath is not '':
        distpath = str(context.env.Dir(distpath))
        # Add the user specified (or ajdistpath) to LIBPATH and CPPPATH
        flags = { 'CPPPATH' : [  distpath + '/include' ], 'LIBPATH' : [ distpath + '/lib' ] }
        context.env.MergeFlags(flags)

    # The real test for the library
    r = context.TryLink(prog, '.c')
    context.Result(r)
    return r

def CheckAJFuncWithArgs(context, function_name, function_args, header = None, language = None):
    # Lifted from official scons code - see: http://www.scons.org/doc/2.4.0/HTML/scons-api/
    if context.headerfilename:
        includetext = '#include "%s"' % context.headerfilename
    else:
        includetext = ''
    if not header:
        header = """
#ifdef __cplusplus
extern "C"
#endif
char %s();""" % function_name

    lang = "C"
    suffix = ".c"
    text = """
%(include)s
#include <assert.h>
%(hdr)s

int main() {
#if defined (__stub_%(name)s) || defined (__stub___%(name)s)
fail fail fail
#else
%(name)s(%(args)s);
#endif

return 0;
}
""" % { 'name': function_name,
        'args': function_args if function_args is not None else '',
        'include': includetext,
        'hdr': header }

    context.Display("Checking for %s function %s()... " % (lang, function_name))
    ret = not context.BuildProg(text, suffix)
    context.Result(ret)
    return ret

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
# Compilation defines
#######################################################
if env['VARIANT'] == 'release' and env['NDEBUG'] == 'defined':
    env.Append(CPPDEFINES = [ 'NDEBUG' ])

#######################################################
# Include path
#######################################################
env.Append(CPPPATH = [ '#dist/include' ])

#######################################################
# Process commandline defines
#######################################################
env.Append(CPPDEFINES = [ v for k, v in ARGLIST if k.lower() == 'define' ])

#######################################################
# Check dependencies
#######################################################
found_ws = False
dep_libs = []
enable_onboarding = True

if not env.GetOption('clean'):
    config = Configure(env)
    SetupDistEnvironment(config, 'ajtcl', 'ajtcl/aj_bus.h', 'AJTCL_DIST', '../../core/ajtcl/dist')
    config.AddTests({
         'CheckCommand' : CheckCommand,
         'CheckAJFuncWithArgs' : CheckAJFuncWithArgs,
         'CheckAJLib' : CheckAJLib
    })
    found_ws = config.CheckCommand('uncrustify')
    dep_libs = [
        config.CheckAJLib('ajtcl', 'ajtcl/aj_bus.h', 'AJTCL_DIST'),
    ]
    enable_onboarding = config.CheckAJFuncWithArgs('AJ_EnableSoftAP', 'NULL, 0, NULL, 0', '#include <ajtcl/aj_wifi_ctrl.h>\n', 'c')
    env = config.Finish()

env['enable_onboarding'] = enable_onboarding

if env['enable_onboarding']:
    env.Append(CPPDEFINES = 'ONBOARDING_SERVICE')

#######################################################
# Install header files
#######################################################
notification_hdrs = [
    'inc/NotificationCommon.h',
    'inc/NotificationProducer.h',
    'inc/NotificationConsumer.h'
]
onboarding_hdrs = [
    'inc/OnboardingControllerAPI.h',
    'inc/OnboardingManager.h',
    'inc/OnboardingService.h'
]
controlpanel_hdrs = [
    'inc/ControlPanelService.h',
    'inc/ControlPanelInterfaces.h',
    'inc/Definitions.h'
]
other_hdrs = [
    'inc/PropertyStore.h',
    'inc/ServicesCommon.h',
    'inc/ServicesHandlers.h'
]
common_hdrs = [
    'inc/Common/AllJoynLogo.h',
    # for controllee
    'inc/Common/BaseWidget.h',
    'inc/Common/ConstraintList.h',
    'inc/Common/ConstraintRange.h',
    'inc/Common/ControlMarshalUtil.h',
    'inc/Common/DateTimeUtil.h',
    'inc/Common/HttpControl.h'
]
env.Install('#dist/include/ajtcl/services', notification_hdrs + controlpanel_hdrs + other_hdrs)
env.Install('#dist/include/ajtcl/services/Widgets', env.Glob('inc/Widgets/*.h'))
if env['enable_onboarding']:
    env.Install('#dist/include/ajtcl/services', onboarding_hdrs)
env.Install('#dist/include/ajtcl/services/Common', common_hdrs)
# Need to force a dpendency here because SCons can't follow nested
# #include dependencies otherwise
env.Depends('#build/$VARIANT', '#dist/include')

#######################################################
# Build the various parts
#######################################################
if env['build'] and all(dep_libs):
    env.SConscript('src/SConscript',     variant_dir='#build/$VARIANT/src',     duplicate = 0)
    env.SConscript('samples/SConscript', variant_dir='#build/$VARIANT/samples', duplicate = 0)
    # disable tests for now - core seems to have broken it again
    #env.SConscript('test/SConscript',    variant_dir='#build/$VARIANT/test',    duplicate = 0)


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
