# Задать третью минимальную версию CMake:
cmake_minimum_required(VERSION 3.0)

# Задать характеристики проекта "CMakeTest":
project(WxTestDialog VERSION 0.1 LANGUAGES CXX)

# It was noticed that when using MinGW gcc it is essential that 'core' is mentioned before 'base'.
find_package(wxWidgets COMPONENTS adv core base adv REQUIRED)
 
# wxWidgets include (this will do all the magic to configure everything)
include( "${wxWidgets_USE_FILE}" )

# For convenience we define the sources as a variable. You can add 
# header files and cpp/c files and CMake will sort them out
set(
  SRCS
  WxTestApp.cpp
  WxTestFrame.cpp
  WxTestDialog.cpp
  WxTestDialog2.cpp 
  GODialogCloser.cpp 
  GOSimpleDialog.cpp 
  GOTabbedDialog.cpp 
  MySimpleDialog.cpp 
  help/GOHelpRequestor.cpp
)

add_executable(WxTestDialog ${SRCS})

target_link_libraries(WxTestDialog ${wxWidgets_LIBRARIES})

IF (APPLE)
  set(BININSTDIR "${PROJECT_NAME}.app/Contents/MacOS")
  SET(RPATH_PREFIX "@executable_path")
ELSE()
  set(BININSTDIR "bin")
  IF (WIN32)
    SET(LIBINSTDIR "bin")
  ELSE ()
    SET(LIBINSTDIR "lib" CACHE STRING "library directory")
  ENDIF ()
ENDIF()

install(TARGETS WxTestDialog DESTINATION "${BININSTDIR}")

set(CPACK_STRIP_FILES ON)
set(CPACK_PACKAGE_CONTACT "osamarin68@gmail.com")

if (APPLE)
  set (CPACK_GENERATOR DragNDrop)
elseif (WIN32)
  set (CPACK_GENERATOR ZIP NSIS)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  set(CPACK_GENERATOR TGZ RPM DEB)
endif()

include(CPack)
