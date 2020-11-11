add_executable(
  c-pyrun
  c-pyrun.cpp
  )

target_link_libraries(c-pyrun
  Carbon::Shared
  Python::Python
  ${Python_LIBRARIES}
  )



