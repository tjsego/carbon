add_executable(
  c-pyrun
  c-pyrun.cpp
  )

target_link_libraries(c-pyrun
  Carbon::Static
  Python::Python
  ${Python_LIBRARIES}
  )



