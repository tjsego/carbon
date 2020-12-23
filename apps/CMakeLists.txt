add_executable(
  c-pyrun
  c-pyrun.cpp
  )

target_link_libraries(c-pyrun
  LibSBML::LibSBML 
  Carbon::Object
  Python::Python
  ${Python_LIBRARIES}
  )
