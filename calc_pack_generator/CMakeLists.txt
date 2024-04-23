cmake_minimum_required(VERSION 3.22)

project(Calculator VERSION 1.0 LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(CPACK_OUTPUT_FILE_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/../installer")
set(CPACK_PACKAGE_NAME calculator)
set(CPACK_PACKAGE_VENDOR "NGLYD")
set(CPACK_PACKAGE_CONTACT "xfignam00@stud.fit.vutbr.cz")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A simple calculator application created as project for subject IVS")
set(CPACK_PACKAGE_VERSION "1.0")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/../LICENSE")




set(CPACK_GENERATOR DEB)
set(ICON_FILE "${CMAKE_CURRENT_SOURCE_DIR}/linux/calculator_icon.xpm")
install(FILES ${ICON_FILE} DESTINATION "/usr/share/icons/")
install(DIRECTORY deployment/ DESTINATION /opt/${PROJECT_NAME})
install(FILES linux/calculator.desktop DESTINATION share/applications)
set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/linux/postinst;")
include(CPack)