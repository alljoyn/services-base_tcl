import os
import platform

default_ajtcl_dist = '../../core/ajtcl/dist'
exclude_onboarding = False

if platform.system() == 'Linux':
    default_target = 'linux'
    root = os.environ.get('STAGING_DIR', '/')
    if os.path.exists(root + 'usr/lib/libajtcl.so'):
        default_ajtcl_dist = ''
    exclude_onboarding = True
elif platform.system() == 'Windows':
    default_target = 'win32'
elif platform.system() == 'Darwin':
    default_target = 'darwin'

#######################################################
# Build variables
#######################################################
target_options = [ t.split('.')[1] for t in os.listdir('.') if t.startswith('SConscript.') ]
vars = Variables()
vars.Add(BoolVariable('V',                  'Build verbosity',            False))
vars.Add(EnumVariable('TARG',               'Target platform variant',    os.environ.get('AJ_TARG',               default_target),     allowed_values = target_options))
vars.Add(EnumVariable('VARIANT',            'Build variant',              os.environ.get('AJ_VARIANT',            'debug'),            allowed_values = ('debug', 'release')))
vars.Add(EnumVariable('WS',                 'Whitespace Policy Checker',  os.environ.get('AJ_WS',                 'check'),            allowed_values = ('check', 'detail', 'fix', 'off')))
vars.Add(BoolVariable('EXCLUDE_ONBOARDING', 'Exclude Onboarding support', os.environ.get('AJ_EXCLUDE_ONBOARDING', exclude_onboarding)))
vars.Add(PathVariable('AJTCL_DIST',         'Path to AJTCL',              os.environ.get('AJ_AJTCL_DIST',         default_ajtcl_dist), PathVariable.PathIsDir))
vars.Add('CC',  'C Compiler override')
vars.Add('CXX', 'C++ Compiler override')

#######################################################
# Initialize our build environment
#######################################################
env = Environment(variables = vars)
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
                 RANLIBCOMSTR = '\t[RANLIB]  $TARGET',
                 INSTALLSTR =   '\t[INSTALL] $TARGET',
                 WSCOMSTR =     '\t[WS]      $WS' )

#######################################################
# Compilation defines
#######################################################
env.Append(CPPDEFINES = [ 'CONFIG_SERVICE',
                          'CONTROLPANEL_SERVICE',
                          'NOTIFICATION_SERVICE_PRODUCER',
                          'TIME_SERVICE_CLIENT',
                          'TIME_SERVICE_SERVER' ])
if env['VARIANT'] == 'release':
    env.Append(CPPDEFINES = [ 'NDEBUG' ])
if not env['EXCLUDE_ONBOARDING']:
    env.Append(CPPDEFINES = 'ONBOARDING_SERVICE')


#######################################################
# Setup references to dependent projects
#######################################################
if env.has_key('AJTCL_DIST'):
    env.Append(CPPPATH = [ Dir(env['AJTCL_DIST'] + '/include') ])
    env.Append(LIBPATH = [ Dir(env['AJTCL_DIST'] + '/lib') ])

#######################################################
# Additional libraries
#######################################################
env.Append(LIBS = [ 'ajtcl'])

#######################################################
# Include path
#######################################################
env.Append(CPPPATH = [ '#dist/include' ])

#######################################################
# Process commandline defines
#######################################################
env.Append(CPPDEFINES = [ v for k, v in ARGLIST if k.lower() == 'define' ])

#######################################################
# Whitespace checker
#######################################################
# Set the location of the uncrustify config file
import sys
sys.path.append(os.getcwd() + '/tools')
import whitespace

def wsbuild(target, source, env):
    return whitespace.main([ env['WS'], os.getcwd() + '/tools/ajuncrustify.cfg' ])

if env['WS'] != 'off':
    env.Command('#ws_ajtcl', '#dist', Action(wsbuild, '$WSCOMSTR'))

#######################################################
# Install header files
#######################################################
env.Install('#dist/include/ajtcl/services', env.Glob('inc/*.h'))
env.Install('#dist/include/ajtcl/services/Common', env.Glob('inc/Common/*.h'))
env.Install('#dist/include/ajtcl/services/Widgets', env.Glob('inc/Widgets/*.h'))

#######################################################
# Build the various parts and setup target specific options
#######################################################
env['build'] = True
env['build_shared'] = False
Export('env')
env.SConscript('SConscript.$TARG')
if env['build']:
    env.SConscript('src/SConscript',     variant_dir='#build/$VARIANT',         duplicate = 0)
    env.SConscript('samples/SConscript', variant_dir='#build/$VARIANT/samples', duplicate = 0)
    env.SConscript('test/SConscript',    variant_dir='#build/$VARIANT/test',    duplicate = 0)
