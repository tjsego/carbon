# LLVM compile options
#add_definitions(${LLVM_LDFLAGS})

set(SRC
  CObject.cpp
  CType.cpp
  CDescrObject.cpp
  CListWrap.cpp
  CEvent.cpp
  CConvert.cpp
  CError.cpp
  CSpecies.cpp
  CSpeciesList.cpp
  CSpeciesValue.cpp
  CStateVector.cpp
  CLogger.cpp

  c_model.cpp
  c_compartment.cpp
  c_kineticlaw.cpp
  c_reaction.cpp
  c_speciesreference.cpp
  c_list.cpp
  c_util.cpp
  )


set(HEADERS
  ${CARBON_PUBLIC_HEADERS}
  CObject.hpp
  CType.hpp
  CEvent.hpp
  CConvert.hpp

  CSpecies.hpp
  CSpeciesList.hpp
  CSpeciesValue.hpp
  CStateVector.hpp

  c_compartment.hpp
  c_kineticlaw.hpp
  c_speciesreference.hpp
  CSymbol.hpp
  c_model.hpp
  carbon.hpp
  CType.hpp
  c_reaction.hpp
  c_list.hpp
  )


# For development, for the time being, we won't build the object library
# because it takes longer to build if we're only building one library,
# and won't build the py version for a while.

# get the include directories of the dependencies that the carbon objects use
# really goofy design decision in design of CMake OBJECT libraries -- no transitive includes
#target_include_directories(carbon_OBJECTS PRIVATE $<TARGET_PROPERTY:mdcore_single,INTERFACE_INCLUDE_DIRECTORIES>)
#target_include_directories(carbon_OBJECTS PRIVATE $<TARGET_PROPERTY:voro++,INTERFACE_INCLUDE_DIRECTORIES> )
#target_include_directories(carbon_OBJECTS PRIVATE $<TARGET_PROPERTY:Magnum::Magnum,INTERFACE_INCLUDE_DIRECTORIES>)
#target_include_directories(carbon_OBJECTS PRIVATE "${PROJECT_SOURCE_DIR}/include")
#target_include_directories(carbon_OBJECTS PRIVATE ${NUMPY_INCLUDE_DIR})


add_compile_options(-DMX_STRICT)

# TODO, do we need this?
include_directories(PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${GLM_INCLUDE_DIRS})


# this is the "object library" target: compiles the sources only once
# need at least one src file in a project for xcode to build it, xcode
# won't work if any product *only* has an object src
add_library(carbon_obj
  OBJECT
  ${SRC}
  ${HEADERS}
  )

target_compile_definitions(carbon_obj PRIVATE C_BUILDING_DLL)

set_target_properties(carbon_obj PROPERTIES
  CXX_VISIBILITY_PRESET hidden
  VISIBILITY_INLINES_HIDDEN 1
  )


# set_target_properties(carbon PROPERTIES POSITION_INDEPENDENT_CODE ON)

# temporarily add add these includes until we get a stable public API
target_include_directories(carbon_obj PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  ${Python_INCLUDE_DIRS}
  )

target_link_libraries(carbon_obj PRIVATE LibSBML::LibSBML)

source_group("Public Header Files" FILES ${CARBON_PUBLIC_HEADERS})

message("added python include: ${Python_INCLUDE_DIRS}")

# Link against LLVM libraries
#link_directories(${LLVM_LIBRARY_DIRS})
#target_link_libraries(carbon ${LLVM_LIBRARIES})


# shared libraries need PIC
set_property(TARGET carbon_obj PROPERTY POSITION_INDEPENDENT_CODE 1)

add_library(carbon_object OBJECT
  $<TARGET_OBJECTS:carbon_obj>
  carbon.cpp
  )

set_property(TARGET carbon_object PROPERTY POSITION_INDEPENDENT_CODE 1)

target_include_directories(carbon_object PUBLIC
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    ${Python_INCLUDE_DIRS}
    )

target_compile_definitions(carbon_object PRIVATE C_BUILDING_DLL)



##########################################################################

# shared and static libraries built from the same object files
add_library(carbon_static STATIC
  $<TARGET_OBJECTS:carbon_obj>
  carbon.cpp
  )

target_compile_definitions(carbon_static PRIVATE C_BUILDING_DLL)

set_target_properties(carbon_static PROPERTIES
  CXX_VISIBILITY_PRESET hidden
  VISIBILITY_INLINES_HIDDEN 1
  )

target_include_directories(carbon_static PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  ${Python_INCLUDE_DIRS}
  #$<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
  )

target_link_libraries(carbon_static PRIVATE LibSBML::LibSBML)

#########################################################


if(CARBON_SHARED)

  add_library(carbon_shared SHARED
    $<TARGET_OBJECTS:carbon_obj>
    carbon.cpp
    )

  target_compile_definitions(carbon_shared PRIVATE C_BUILDING_DLL)


  set_target_properties(carbon_shared PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN 1
    )

  target_include_directories(carbon_shared PUBLIC
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    ${Python_INCLUDE_DIRS}
    #$<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
    )

  set_target_properties(carbon_shared PROPERTIES OUTPUT_NAME "carbon")

  target_link_libraries(carbon_shared PRIVATE LibSBML::LibSBML)

  if(WIN32 OR CYGWIN)
    # Link against the Python shared library on Windows

    # weird bug with CMake / clang on windows, need to add link dir here
    target_link_directories(carbon_shared PUBLIC ${Python_LIBRARY_DIRS})

    # Link against the Python shared library on Windows
    target_link_libraries(carbon_shared PRIVATE ${Python_LIBRARY_RELEASE})

  elseif(APPLE)
    # It's quite common to have multiple copies of the same Python version
    # installed on one's system. E.g.: one copy from the OS and another copy
    # that's statically linked into an application like Blender or Maya.
    # If we link our plugin library against the OS Python here and import it
    # into Blender or Maya later on, this will cause segfaults when multiple
    # conflicting Python instances are active at the same time (even when they
    # are of the same version).

    # Windows is not affected by this issue since it handles DLL imports
    # differently. The solution for Linux and Mac OS is simple: we just don't
    # link against the Python library. The resulting shared library will have
    # missing symbols, but that's perfectly fine -- they will be resolved at
    # import time.

    target_link_libraries(carbon_shared PRIVATE "-undefined dynamic_lookup")

  endif()

  add_library(carbon ALIAS carbon_shared)
  add_library(Carbon::Shared ALIAS carbon_shared)

endif()


#################################################################


if(CARBON_PY)

  # shared and static libraries built from the same object files
  add_library(carbon_py SHARED
    $<TARGET_OBJECTS:carbon_obj>
    carbon.cpp
    )

  target_compile_definitions(carbon_py PRIVATE C_BUILDING_DLL)

  set_target_properties(carbon_py PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN 1
    )

  target_include_directories(carbon_py PRIVATE
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    ${Python_INCLUDE_DIRS}
    #$<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
    )

  set_target_properties(carbon_py PROPERTIES PREFIX "")
  set_target_properties(carbon_py PROPERTIES OUTPUT_NAME "_carbon")

  target_link_libraries(carbon_py PRIVATE LibSBML::LibSBML)



  if(WIN32)
    set_target_properties(carbon_py PROPERTIES SUFFIX ".pyd")
  else()
    set_target_properties(carbon_py PROPERTIES SUFFIX ".so")
  endif()


  


  if(WIN32 OR CYGWIN)
    # Link against the Python shared library on Windows

    # weird bug with CMake / clang on windows, need to add link dir here
    target_link_directories(carbon_py PUBLIC ${Python_LIBRARY_DIRS})

    # Link against the Python shared library on Windows
    target_link_libraries(carbon_py PRIVATE ${Python_LIBRARY_RELEASE})

  elseif(APPLE)
    # It's quite common to have multiple copies of the same Python version
    # installed on one's system. E.g.: one copy from the OS and another copy
    # that's statically linked into an application like Blender or Maya.
    # If we link our plugin library against the OS Python here and import it
    # into Blender or Maya later on, this will cause segfaults when multiple
    # conflicting Python instances are active at the same time (even when they
    # are of the same version).

    # Windows is not affected by this issue since it handles DLL imports
    # differently. The solution for Linux and Mac OS is simple: we just don't
    # link against the Python library. The resulting shared library will have
    # missing symbols, but that's perfectly fine -- they will be resolved at
    # import time.

    target_link_libraries(carbon_py PRIVATE "-undefined dynamic_lookup")

    if(ARG_SHARED)
      # Suppress CMake >= 3.0 warning for shared libraries
      set_target_properties(carbon_py PROPERTIES MACOSX_RPATH ON)
    endif()
  endif()


  message("CARBON_PYTHON:  ${Python_LIBRARY_RELEASE}")

  #add_custom_command(
  #  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/carbon.py"
  #  POST_BUILD
  #  COMMAND ${CMAKE_COMMAND} -E copy
  #  ${CMAKE_CURRENT_SRC_DIR}/carbon.py
  #  ${CMAKE_CURRENT_BINARY_DIR}/carbon.py
  #  DEPENDS carbon.py)


  #add_custom_command(
  # TARGET ${destination} POST_BUILD
  # COMMAND ${CMAKE_COMMAND} -E copy ${source} ${destination}
  # DEPENDS ${source}
  # COMMENT "symbolic link resources folder from ${source} => ${destination}"
  # )

  #add_custom_target(carbon.py
  #  DEPENDS carbon.py)

  add_custom_command(
    TARGET carbon_py
    DEPENDS carbon.py
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy  ${CMAKE_CURRENT_SOURCE_DIR}/carbon.py ${CMAKE_CURRENT_BINARY_DIR}/carbon.py
    )


endif()

add_library(Carbon::Carbon ALIAS carbon_static)
add_library(Carbon::Static ALIAS carbon_static)
add_library(Carbon::Object ALIAS carbon_object)
