add_library(mogumogu STATIC)

target_compile_features(mogumogu PUBLIC cxx_std_17)
set_target_properties(mogumogu PROPERTIES CXX_EXTENSIONS OFF)

target_include_directories(mogumogu PUBLIC include)
target_sources(mogumogu PRIVATE
    include/mogumogu/type.hpp
    include/mogumogu/vec.hpp
    src/vec.cpp
    include/mogumogu/ray.hpp
)