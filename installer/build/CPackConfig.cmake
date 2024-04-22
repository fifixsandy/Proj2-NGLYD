# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "/root/znovu/Proj2-NGLYD/installer;/root/znovu/Proj2-NGLYD/installer/build")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "/root/znovu/Proj2-NGLYD/installer/linux/postinst;")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/usr/share/cmake-3.22/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "Calculator built using CMake")
set(CPACK_GENERATOR "DEB")
set(CPACK_INSTALL_CMAKE_PROJECTS "/root/znovu/Proj2-NGLYD/installer/build;Calculator;ALL;/")
set(CPACK_INSTALL_PREFIX "/usr/local")
set(CPACK_MODULE_PATH "/usr/lib/x86_64-linux-gnu/cmake/Qt6;/usr/lib/x86_64-linux-gnu/cmake/Qt6/3rdparty/extra-cmake-modules/find-modules;/usr/lib/x86_64-linux-gnu/cmake/Qt6/3rdparty/kwin;/usr/lib/x86_64-linux-gnu/cmake/Qt6;/usr/lib/x86_64-linux-gnu/cmake/Qt6/3rdparty/extra-cmake-modules/find-modules;/usr/lib/x86_64-linux-gnu/cmake/Qt6/3rdparty/kwin;/usr/lib/x86_64-linux-gnu/cmake/Qt6;/usr/lib/x86_64-linux-gnu/cmake/Qt6/3rdparty/extra-cmake-modules/find-modules;/usr/lib/x86_64-linux-gnu/cmake/Qt6/3rdparty/kwin;/usr/lib/x86_64-linux-gnu/cmake/Qt6;/usr/lib/x86_64-linux-gnu/cmake/Qt6/3rdparty/extra-cmake-modules/find-modules;/usr/lib/x86_64-linux-gnu/cmake/Qt6/3rdparty/kwin;/usr/lib/x86_64-linux-gnu/cmake/Qt6;/usr/lib/x86_64-linux-gnu/cmake/Qt6/3rdparty/extra-cmake-modules/find-modules;/usr/lib/x86_64-linux-gnu/cmake/Qt6/3rdparty/kwin;/usr/lib/x86_64-linux-gnu/cmake/Qt6;/usr/lib/x86_64-linux-gnu/cmake/Qt6/3rdparty/extra-cmake-modules/find-modules;/usr/lib/x86_64-linux-gnu/cmake/Qt6/3rdparty/kwin")
set(CPACK_NSIS_DISPLAY_NAME "calculator 1.0")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "calculator 1.0")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OUTPUT_CONFIG_FILE "/root/znovu/Proj2-NGLYD/installer/build/CPackConfig.cmake")
set(CPACK_OUTPUT_FILE_PREFIX "/root/znovu/Proj2-NGLYD/installer")
set(CPACK_PACKAGE_CONTACT "xfignam00@stud.fit.vutbr.cz")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/usr/share/cmake-3.22/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A simple calculator application created as project for subject IVS")
set(CPACK_PACKAGE_FILE_NAME "calculator-1.0-Linux")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "calculator 1.0")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "calculator 1.0")
set(CPACK_PACKAGE_NAME "calculator")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "NGLYD")
set(CPACK_PACKAGE_VERSION "1.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_RESOURCE_FILE_LICENSE "/root/znovu/Proj2-NGLYD/installer/../LICENSE")
set(CPACK_RESOURCE_FILE_README "/usr/share/cmake-3.22/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "/usr/share/cmake-3.22/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_GENERATOR "TBZ2;TGZ;TXZ;TZ")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/root/znovu/Proj2-NGLYD/installer/build/CPackSourceConfig.cmake")
set(CPACK_SOURCE_RPM "OFF")
set(CPACK_SOURCE_TBZ2 "ON")
set(CPACK_SOURCE_TGZ "ON")
set(CPACK_SOURCE_TXZ "ON")
set(CPACK_SOURCE_TZ "ON")
set(CPACK_SOURCE_ZIP "OFF")
set(CPACK_SYSTEM_NAME "Linux")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "Linux")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/root/znovu/Proj2-NGLYD/installer/build/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
