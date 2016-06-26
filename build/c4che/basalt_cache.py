AR = 'arm-none-eabi-ar'
ARFLAGS = 'rcs'
AS = 'arm-none-eabi-gcc'
BINDIR = '/usr/local/bin'
BLOCK_MESSAGE_KEYS = []
BUILD_DIR = 'basalt'
BUILD_TYPE = 'app'
BUNDLE_BIN_DIR = 'basalt'
BUNDLE_NAME = 'OnePlus Life.pbw'
CC = ['arm-none-eabi-gcc']
CCLNK_SRC_F = []
CCLNK_TGT_F = ['-o']
CC_NAME = 'gcc'
CC_SRC_F = []
CC_TGT_F = ['-c', '-o']
CC_VERSION = ('4', '7', '2')
CFLAGS = ['-std=c99', '-mcpu=cortex-m3', '-mthumb', '-ffunction-sections', '-fdata-sections', '-g', '-fPIE', '-Os', '-D_TIME_H_', '-Wall', '-Wextra', '-Werror', '-Wno-unused-parameter', '-Wno-error=unused-function', '-Wno-error=unused-variable']
CFLAGS_MACBUNDLE = ['-fPIC']
CFLAGS_cshlib = ['-fPIC']
CPPPATH_ST = '-I%s'
DEFINES = ['RELEASE', 'PBL_PLATFORM_BASALT', 'PBL_COLOR', 'PBL_RECT', 'PBL_MICROPHONE', 'PBL_SMARTSTRAP', 'PBL_HEALTH', 'PBL_SDK_3']
DEFINES_ST = '-D%s'
DEST_BINFMT = 'elf'
DEST_CPU = 'arm'
DEST_OS = 'darwin'
INCLUDES = ['basalt']
LD = 'arm-none-eabi-ld'
LIBDIR = '/usr/local/lib'
LIBPATH_ST = '-L%s'
LIB_DIR = 'node_modules'
LIB_JSON = [{u'gitHead': u'f0c44c57199a4d3eed523ce779bf1076b67f14bd', u'_location': u'/pebble-clay', u'dist': {u'tarball': u'https://registry.npmjs.org/pebble-clay/-/pebble-clay-1.0.1.tgz', u'shasum': u'098c3a6f027cb7fe47fb984bea1da2b6216460c0'}, u'_spec': u'pebble-clay', u'_npmOperationalInternal': {u'tmp': u'tmp/pebble-clay-1.0.1.tgz_1466209134487_0.1218364320229739', u'host': u'packages-16-east.internal.npmjs.com'}, u'keywords': [u'pebble', u'config', u'configuration', u'pebble-package'], u'devDependencies': {u'chai': u'^3.4.1', u'mocha': u'^2.3.4', u'through': u'^2.3.8', u'gulp-inline': u'0.0.15', u'karma-source-map-support': u'^1.1.0', u'deepcopy': u'^0.6.1', u'eslint-plugin-standard': u'^1.3.1', u'stringify': u'^3.2.0', u'gulp-insert': u'^0.5.0', u'gulp': u'^3.9.0', u'gulp-htmlmin': u'^1.3.0', u'deamdify': u'^0.2.0', u'bourbon': u'^4.2.6', u'eslint-config-pebble': u'^1.2.0', u'eslint': u'^1.5.1', u'karma-coverage': u'^0.5.3', u'watchify': u'^3.7.0', u'require-from-string': u'^1.1.0', u'gulp-sourcemaps': u'^1.6.0', u'karma-mocha': u'^0.2.1', u'sinon': u'^1.17.3', u'joi': u'^6.10.1', u'browserify': u'^13.0.0', u'sassify': u'^0.9.1', u'gulp-autoprefixer': u'^3.1.0', u'karma-mocha-reporter': u'^1.1.5', u'autoprefixer': u'^6.3.1', u'browserify-istanbul': u'^0.2.1', u'karma-threshold-reporter': u'^0.1.15', u'gulp-sass': u'^2.1.1', u'vinyl-source-stream': u'^1.1.0', u'gulp-uglify': u'^1.5.2', u'karma-chrome-launcher': u'^0.2.2', u'vinyl-buffer': u'^1.0.0', u'del': u'^2.0.2', u'karma': u'^0.13.19', u'karma-browserify': u'^5.0.1', u'tosource': u'^1.0.0', u'postcss': u'^5.0.14'}, u'_from': u'pebble-clay@latest', u'pebble': {u'sdkVersion': u'3', u'projectType': u'package', u'targetPlatforms': [u'aplite', u'basalt', u'chalk', u'diorite', u'emery'], u'resources': {u'media': []}}, u'_inCache': True, u'_phantomChildren': {}, u'_args': [[{u'name': u'pebble-clay', u'rawSpec': u'', u'raw': u'pebble-clay', u'scope': None, u'type': u'tag', u'spec': u'latest'}, u'/Users/obakesan/CloudStation/Projects/OnePlus Life']], u'_nodeVersion': u'6.2.1', u'version': u'1.0.1', u'_resolved': u'https://registry.npmjs.org/pebble-clay/-/pebble-clay-1.0.1.tgz', u'readme': u'ERROR: No README data found!', u'homepage': u'https://github.com/pebble/clay#readme', u'_npmVersion': u'3.9.3', u'_requested': {u'name': u'pebble-clay', u'rawSpec': u'', u'raw': u'pebble-clay', u'scope': None, u'type': u'tag', u'spec': u'latest'}, u'description': u'Pebble Config Framework', u'repository': {u'url': u'git+https://github.com/pebble/clay.git', u'type': u'git'}, u'optionalDependencies': {}, u'_requiredBy': [u'/'], u'maintainers': [{u'email': u'webteam@getpebble.com', u'name': u'pebble-tech'}], u'dependencies': {}, u'scripts': {u'pebble-publish': u'npm run pebble-clean && npm run build && pebble build && pebble package publish && npm run pebble-clean', u'test-travis': u'gulp && ./node_modules/.bin/karma start ./test/karma.conf.js --single-run --browsers chromeTravisCI && ./node_modules/.bin/eslint ./', u'pebble-build': u'npm run build && pebble build', u'test-debug': u'(export DEBUG=true && ./node_modules/.bin/gulp && ./node_modules/.bin/karma start ./test/karma.conf.js --no-single-run)', u'lint': u'eslint ./', u'dev': u'gulp dev', u'build': u'gulp', u'test': u'gulp && ./node_modules/.bin/karma start ./test/karma.conf.js --single-run', u'pebble-clean': u'rm -rf tmp src/js/index.js && pebble clean'}, 'path': 'node_modules/pebble-clay/dist', u'_installable': True, u'_shrinkwrap': None, u'name': u'pebble-clay', u'license': u'MIT', u'directories': {}, u'author': {u'name': u'Pebble Technology'}, u'bugs': {u'url': u'https://github.com/pebble/clay/issues'}, u'_npmUser': {u'email': u'webteam@getpebble.com', u'name': u'pebble-tech'}, 'js_paths': ['node_modules/pebble-clay/dist/js/index.js'], u'_where': u'/Users/obakesan/CloudStation/Projects/OnePlus Life', u'_id': u'pebble-clay@1.0.1', u'_shasum': u'098c3a6f027cb7fe47fb984bea1da2b6216460c0'}]
LIB_RESOURCES_JSON = {u'pebble-clay': {}}
LIB_ST = '-l%s'
LINKFLAGS = ['-mcpu=cortex-m3', '-mthumb', '-Wl,--gc-sections', '-Wl,--warn-common', '-fPIE', '-Os']
LINKFLAGS_MACBUNDLE = ['-bundle', '-undefined', 'dynamic_lookup']
LINKFLAGS_cshlib = ['-shared']
LINKFLAGS_cstlib = ['-Wl,-Bstatic']
LINK_CC = ['arm-none-eabi-gcc']
MESSAGE_KEYS = {u'ColourTheme': 10000, u'EnableSayings': 10001}
MESSAGE_KEYS_DEFINITION = '/Users/obakesan/CloudStation/Projects/OnePlus Life/build/src/message_keys.auto.c'
MESSAGE_KEYS_HEADER = '/Users/obakesan/CloudStation/Projects/OnePlus Life/build/include/message_keys.auto.h'
MESSAGE_KEYS_JSON = '/Users/obakesan/CloudStation/Projects/OnePlus Life/build/js/message_keys.json'
PEBBLE_SDK_COMMON = '/Users/obakesan/Library/Application Support/Pebble SDK/SDKs/current/sdk-core/pebble/common'
PEBBLE_SDK_PLATFORM = '/Users/obakesan/Library/Application Support/Pebble SDK/SDKs/current/sdk-core/pebble/basalt'
PEBBLE_SDK_ROOT = '/Users/obakesan/Library/Application Support/Pebble SDK/SDKs/current/sdk-core/pebble'
PLATFORM = {'TAGS': ['basalt', 'color', 'rect'], 'ADDITIONAL_TEXT_LINES_FOR_PEBBLE_H': [], 'MAX_APP_BINARY_SIZE': 65536, 'MAX_RESOURCES_SIZE': 1048576, 'MAX_APP_MEMORY_SIZE': 65536, 'MAX_WORKER_MEMORY_SIZE': 10240, 'NAME': 'basalt', 'BUNDLE_BIN_DIR': 'basalt', 'BUILD_DIR': 'basalt', 'MAX_RESOURCES_SIZE_APPSTORE': 262144, 'DEFINES': ['PBL_PLATFORM_BASALT', 'PBL_COLOR', 'PBL_RECT', 'PBL_MICROPHONE', 'PBL_SMARTSTRAP', 'PBL_HEALTH']}
PLATFORM_NAME = 'basalt'
PREFIX = '/usr/local'
PROJECT_INFO = {'appKeys': {u'ColourTheme': 10000, u'EnableSayings': 10001}, u'watchapp': {u'watchface': True}, u'displayName': u'OnePlus Life', u'uuid': u'e71435f5-87fe-4e67-9ec3-d78b5cf8349c', u'messageKeys': {u'ColourTheme': 10000, u'EnableSayings': 10001}, 'companyName': u'Tor Harrington', u'enableMultiJS': True, u'sdkVersion': u'3', 'versionLabel': u'1.1', u'targetPlatforms': [u'aplite', u'basalt', u'chalk'], 'longName': u'OnePlus Life', 'shortName': u'OnePlus Life', u'resources': {u'media': [{u'type': u'font', u'name': u'LATO_BLACK_24', u'file': u'fonts/Lato-Black.ttf'}, {u'type': u'font', u'name': u'ROKKITT_BOLD_64', u'file': u'fonts/Rokkitt-Bold.ttf'}, {u'menuIcon': True, u'type': u'bitmap', u'name': u'IMAGE_MENU_ICON', u'file': u'menu_icon.png'}]}, 'name': u'OnePlusLife'}
REQUESTED_PLATFORMS = [u'aplite', u'basalt', u'chalk']
RESOURCES_JSON = [{u'type': u'font', u'name': u'LATO_BLACK_24', u'file': u'fonts/Lato-Black.ttf'}, {u'type': u'font', u'name': u'ROKKITT_BOLD_64', u'file': u'fonts/Rokkitt-Bold.ttf'}, {u'menuIcon': True, u'type': u'bitmap', u'name': u'IMAGE_MENU_ICON', u'file': u'menu_icon.png'}]
RPATH_ST = '-Wl,-rpath,%s'
SDK_VERSION_MAJOR = 5
SDK_VERSION_MINOR = 78
SHLIB_MARKER = None
SIZE = 'arm-none-eabi-size'
SONAME_ST = '-Wl,-h,%s'
STLIBPATH_ST = '-L%s'
STLIB_MARKER = None
STLIB_ST = '-l%s'
SUPPORTED_PLATFORMS = ['aplite', 'basalt', 'chalk']
TARGET_PLATFORMS = ['chalk', 'basalt', 'aplite']
TIMESTAMP = 1466975842
cprogram_PATTERN = '%s'
cshlib_PATTERN = 'lib%s.so'
cstlib_PATTERN = 'lib%s.a'
macbundle_PATTERN = '%s.bundle'
