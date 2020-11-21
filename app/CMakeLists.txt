add_executable(app main.cpp)

target_compile_features(app PRIVATE cxx_std_17)
set_target_properties(app PROPERTIES CXX_EXTENSIONS OFF)

target_link_libraries(app PRIVATE renderer)