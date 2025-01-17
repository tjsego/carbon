function(download_file url filename hash_type hash)

if(NOT EXISTS ${filename})
  file(DOWNLOAD ${url} ${filename}
       TIMEOUT 60  # seconds
       EXPECTED_HASH ${hash_type}=${hash}
       TLS_VERIFY ON)
endif()

endfunction(download_file)

set(LIBSBML_WINDEP_URL "https://github.com/AndySomogyi/libsbml-windows-dependencies/releases/download/1.0/libsbml-windep-vs2019-x64-rel.zip")

set(LIBSBML_WINDEP_ZIPNAME "${CMAKE_BINARY_DIR}/libsbml-windep-vs2019-x64-rel.zip")

set(LIBSBML_WINDEP_DIR "${CMAKE_BINARY_DIR}/libsbml-windep-vs2019-x64-rel")


if(WIN32)
  if(NOT EXISTS ${LIBSBML_WINDEP_DIR})
    message("downloading libsbml windows dependencies ...")

    file(DOWNLOAD  ${LIBSBML_WINDEP_URL} ${LIBSBML_WINDEP_ZIPNAME}
      SHOW_PROGRESS
      TIMEOUT 60  # seconds
      )

    # this is OS-agnostic, unzip the file
    if(CMAKE_VERSION VERSION_LESS 3.18)
      execute_process(COMMAND ${CMAKE_COMMAND} -E tar -xf ${LIBSBML_WINDEP_ZIPNAME}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
    else()
      file(ARCHIVE_EXTRACT INPUT ${LIBSBML_WINDEP_ZIPNAME} DESTINATION ${CMAKE_BINARY_DIR})
    endif()

    # rename to sane pathname without spaces
    # file(RENAME ${LIBSBML_WINDEP_UNZIPNAME} ${LIBSBML_WINDEP_DIR})
  else()
    message("libsbml windows dependencies already exists")
  endif()

  set(LIBSBML_DEPENDENCY_DIR ${LIBSBML_WINDEP_DIR} CACHE PATH
    "Directory of windows libraries that libSBML depends upon.")

endif(WIN32)


set(LIBSBML_SHARED_VERSION OFF CACHE BOOL "dont build shared libsbml")

set(WITH_CPP_NAMESPACE ON CACHE BOOL "Use a C++ namespace for libSBML.")

set(WITH_PYTHON OFF CACHE BOOL
    "Generate the Python language interface for libSBML." )

add_subdirectory(libSBML-5.18.0-Source)

# create an interface target for libsbml as a modern cmake target

add_library(libsbml-static-interface INTERFACE)

# libsbml names libs differently, why???
if(UNIX OR CYGWIN)
  set(LIBSBML_LIBRARY sbml)
else()
  if(MINGW)
    set(LIBSBML_LIBRARY sbml)
  else()
    set(LIBSBML_LIBRARY libsbml)
  endif()
endif()

target_link_libraries(libsbml-static-interface INTERFACE ${LIBSBML_LIBRARY}-static)

target_compile_definitions(libsbml-static-interface INTERFACE LIBSBML_STATIC)

target_include_directories(libsbml-static-interface INTERFACE "$<TARGET_PROPERTY:${LIBSBML_LIBRARY}-static,INCLUDE_DIRECTORIES>")

add_library(LibSBML::LibSBML ALIAS libsbml-static-interface)
