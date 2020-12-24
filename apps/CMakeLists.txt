add_executable(
  c-pyrun
  c-pyrun.cpp
  )

target_compile_definitions(c-pyrun PRIVATE C_BUILDING_DLL)

target_link_libraries(c-pyrun
  Carbon::Object
  Python::Python
  LibSBML::LibSBML
  ${Python_LIBRARIES}
  )



