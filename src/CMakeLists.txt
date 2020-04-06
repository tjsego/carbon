# LLVM compile options
#add_definitions(${LLVM_LDFLAGS})


message(STATUS "numpy: ${NUMPY_INCLUDE_DIR}")

set(SRC
  CObject.cpp
  CType.cpp
  CDescrObject.cpp
  CListWrap.cpp
  CEvent.cpp
#  c_error.cpp
#  c_moduledef.cpp
#  c_callable.cpp
#  c_float.cpp
#  c_import.cpp
#  c_port.cpp
#  c_string.cpp
#  c_abstract.cpp
#  c_eval.cpp
#  c_floatobject.cpp
#  c_int.cpp
#  c_number.cpp
#  c_runtime.cpp
#  c_ast.cpp
#  c_expr.cpp
#  c_function.cpp
#  MxList.cpp
#  MxObject.cpp
#  c_stmt.cpp
#  c_tupleobject.cpp
#  CModule.cpp
#  CType.cpp
#  CSystem.cpp
#  CSymbol.cpp
#  MxExpression.cpp
  )


set(HEADERS
  ${CARBON_PUBLIC_HEADERS}
  CObject.hpp
  CType.hpp
  CEvent.hpp
  # c_error.h
  # MxDebug.h
  # carbon_llvm.h
  # carbon_private.h
  # MxObject.h
  # MxMeshCore.h
  # MxMesh.h
  # MxPolygon.h
  # MxModule.h
  # MxSimulator.h
  # MxTestCube.h
  # MxTestParticles.h
  # MxType.h
  # MxTestMDCoreParticles.h
  # MxModule.h
  # MxModel.h
  # MxSystem.h
  # MxSymbol.h
  # MxPropagator.h
  # MxParticle.h
  # MxCompositeParticle.h
  # MxController.h
  # MxView.h
  # MxLattice.h
  # MxLatticeCluster.h
  # MxCell.h
  # MxMeshRenderer.h
  # MxMeshShaderProgram.h
  # MeshPropagator.h
  # MxMeshPottsPropagator.h
  # MxExecutionContext.h
  # MxForceFunction.h
  # LangevinPropagator.h
  # ScalarField.h
  # MeshRelationships.h
  # MeshOperations.h
  # stochastic_rk.h
  # MxEdge.h
  # MxExpression.h
  # MeshIO.h
  # MxTesselator.h
  # MxColumnarCell.h
  # SymmetricEigen.h
  # GteSymmetricEigensolver3x3.h
  # MxConstraints.h
  # MxForces.h
  # MxPolygonSurfaceTensionForce.h
  # MxPolygonAreaConstraint.h
  # MxCellVolumeConstraint.h
  # MxRenderTarget.h
  # MxWindowView.h
  # MxImageView.h
  # ArcBallInteractor.h
  # MxUI.h
  # MxTestView.h
  # MxWindowless.h
  # MxApplication.h
  # MxGlfwApplication.h
  # MxWindowlessApplication.h
  # MxSurfaceSimulator.h
  # MxImageConverters.h
  # MxCylinderModel.h
  # MxUniverse.h
  )




# For development, for the time being, we won't build the object library
# because it takes longer to build if we're only building one library,
# and won't build the py version for a while.

# build all the source as a CMake 'OBJECT' lib, this gets
# linked into the real libraries below.
#add_library(carbon_OBJECTS OBJECT ${SRC} ${HEADERS})

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

target_compile_features(carbon_obj PUBLIC cxx_std_17)

# set_target_properties(carbon PROPERTIES POSITION_INDEPENDENT_CODE ON)

# temporarily add add these includes until we get a stable public API
target_include_directories(carbon_obj PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  #${PYTHON_INCLUDE_DIRS}
  #${NUMPY_INCLUDE_DIR}
  #$<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
)


target_link_libraries(carbon_obj
  Python::Python
  )


source_group("Public Header Files" FILES ${CARBON_PUBLIC_HEADERS})

#message("CARBON_PUBLIC_HEADERS: ${CARBON_PUBLIC_HEADERS}")

#message("CARBON_SRC: ${SRC}")


# Link against LLVM libraries
#link_directories(${LLVM_LIBRARY_DIRS})
#target_link_libraries(carbon ${LLVM_LIBRARIES})


# shared libraries need PIC
set_property(TARGET carbon_obj PROPERTY POSITION_INDEPENDENT_CODE 1)


# shared and static libraries built from the same object files
add_library(carbon_shared SHARED
  $<TARGET_OBJECTS:carbon_obj>
  carbon.cpp
  )

set_target_properties(carbon_shared PROPERTIES OUTPUT_NAME carbon)

target_include_directories(carbon_shared PUBLIC
  ${PROJECT_BINARY_DIR}/include
  ${PROJECT_SOURCE_DIR}/include
)




add_library(carbon_static STATIC
  $<TARGET_OBJECTS:carbon_obj>
  carbon.cpp
  )

set_target_properties(carbon_static PROPERTIES OUTPUT_NAME carbon)

target_include_directories(carbon_static PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  #${PYTHON_INCLUDE_DIRS}
  #${NUMPY_INCLUDE_DIR}
  #$<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
  )

target_link_libraries(carbon_static
  Python::Python
  )

# shared and static libraries built from the same object files
add_library(carbon_py SHARED
  $<TARGET_OBJECTS:carbon_obj>
  carbon.cpp
  )

target_include_directories(carbon_py PRIVATE
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  #${PYTHON_INCLUDE_DIRS}
  #${NUMPY_INCLUDE_DIR}
  #$<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
)



target_link_libraries(carbon_py
  Python::Python
  )

set_target_properties(carbon_py PROPERTIES PREFIX "")
set_target_properties(carbon_py PROPERTIES OUTPUT_NAME "_carbon")
set_target_properties(carbon_py PROPERTIES SUFFIX ".so")


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

target_link_libraries(carbon_shared
  Python::Python
  )


add_library(carbon ALIAS carbon_shared)
add_library(Carbon::Carbon ALIAS carbon_shared)
add_library(Carbon::Static ALIAS carbon_static)
add_library(Carbon::Shared ALIAS carbon_shared)
