cmake_minimum_required(VERSION 3.14)

project(Carbon)

option(CARBON_DEBUG "Debug build" OFF)
option(CARBON_OPT "Enable platform-specific optimisations" OFF)
option(CARBON_VERBOSE "Enable verbose output" ON)
option(CARBON_PYTHON_MODULE "Build Carbon Python module" ON)
option(CARBON_BUILD_TESTS "Build unit tests" OFF)
option(CARBON_STATIC_PYTHON "link statically with the Python lib, only do this if only using the Carbon C lib")
option(CARBON_DISPTOOLS_COVERAGE "Measure code coverage" OFF)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# sets the target types
if(UNIX)
  # Both APPLE and UNIX are defined on OSX
  if(APPLE)
    set(CARBON_APPLE 1)
  else()
    set(CARBON_LINUX 1)
  endif()
    set(CARBON_UNIX 1)
elseif(WIN32)
    set(CARBON_WINDOWS 1)
endif()

if(MX_APPLE AND DEFINED CMAKE_ECLIPSE_VERSION)
  # hack to get eclipse C++ indexer to pick up python headers
  message("setting eclipse include dirs")
  include_directories(/usr/local/Cellar/python/3.7.0/Frameworks/Python.framework/Versions/3.7/include/python3.7m)
endif()

# using magnum, so whole project needs C++11
set(CMAKE_CXX_STANDARD 11)


message("CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
message("CMAKE_OSX_DEPLOYMENT_TARGET: ${CMAKE_OSX_DEPLOYMENT_TARGET}")
message("MACOSX_DEPLOYMENT_TARGET: ${MACOSX_DEPLOYMENT_TARGET}")
message("CMAKE_OSX_SYSROOT: ${CMAKE_OSX_SYSROOT}")
message("XCODE_VERSION: ${XCODE_VERSION}")
message("CMAKE_GENERATOR: ${CMAKE_GENERATOR}")
message("CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")
message("CMAKE_CXX_COMPILER_VERSION: ${CMAKE_CXX_COMPILER_VERSION}")

find_package (Python 3.5 REQUIRED COMPONENTS Development)

message("Python_FOUND: ${Python_FOUND}")
message("Python_Interpeter_FOUND: ${Python_Interpeter_FOUND}")
message("Python_VERSION: ${Python_VERSION}")
message("Python_Development_FOUND: ${Python_Development_FOUND}")
message("Python_Development_FOUND: ${Python_Development_FOUND}")
message("Python_INCLUDE_DIRS: ${Python_INCLUDE_DIRS}")
message("Python_LIBRARIES: ${Python_LIBRARIES}")
message("Python_LIBRARY_DIRS: ${Python_LIBRARY_DIRS}")
message("Python_RUNTIME_LIBRARY_DIRS: ${Python_RUNTIME_LIBRARY_DIRS}")


if(Python_Development_FOUND)
  get_target_property(TMP Python::Python IMPORTED_LOCATION_DEBUG)
  message("Python IMPORTED_LOCATION_DEBUG: ${TMP}")

  get_target_property(TMP Python::Python IMPORTED_LOCATION_RELEASE)
  message("Python IMPORTED_LOCATION_RELEASE: ${TMP}")
endif()

if(MX_APPLE AND DEFINED CMAKE_ECLIPSE_VERSION)
  # hack to get eclipse C++ indexer to pick up python headers
  message("setting eclipse include dirs: ${Python_INCLUDE_DIRS}")
  include_directories(${Python_INCLUDE_DIRS})
endif()


find_package(NumPy)
message("NUMPY_FOUND: ${NUMPY_FOUND}") # - was NumPy found
message("NUMPY_VERSION: ${NUMPY_VERSION}") # - the version of NumPy found as a string
message("NUMPY_VERSION_MAJOR: ${NUMPY_VERSION_MAJOR}") # - the major version number of NumPy
message("NUMPY_VERSION_MINOR: ${NUMPY_VERSION_MINOR}") # - the minor version number of NumPy
message("NUMPY_VERSION_PATCH: ${NUMPY_VERSION_PATCH}") # - the patch version number of NumPy
message("NUMPY_VERSION_DECIMAL: ${NUMPY_VERSION_DECIMAL}") # - e.g. version 1.6.1 is 10601
message("NUMPY_INCLUDE_DIR: ${NUMPY_INCLUDE_DIR}") # - path to the NumPy include files



# CMake policies: enable MACOSX_RPATH by default
if(POLICY CMP0042)
    cmake_policy(SET CMP0042 NEW)
endif()
# Don't treat imported targets with :: as files
if(POLICY CMP0028)
    cmake_policy(SET CMP0028 NEW)
endif()

add_subdirectory(include)
add_subdirectory(src)
