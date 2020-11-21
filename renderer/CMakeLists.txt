add_library(renderer STATIC)

target_compile_features(renderer PUBLIC cxx_std_17)
set_target_properties(renderer PROPERTIES CXX_EXTENSIONS OFF)

target_include_directories(renderer PUBLIC include)
target_sources(renderer PRIVATE
    src/vec.cpp
)