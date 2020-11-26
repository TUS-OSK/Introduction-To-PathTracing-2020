add_library(mogumogu STATIC)

target_compile_features(mogumogu PUBLIC cxx_std_17)
set_target_properties(mogumogu PROPERTIES CXX_EXTENSIONS OFF)

target_include_directories(mogumogu PUBLIC include)
target_sources(mogumogu PRIVATE
    include/mogumogu/vec3.hpp
    include/mogumogu/ray.hpp
    include/mogumogu/intersect-info.hpp
    include/mogumogu/film.hpp
    src/film.cpp
    include/mogumogu/camera/camera.hpp
    include/mogumogu/shape/shape.hpp
    include/mogumogu/shape/sphere.hpp
)

option(MOGUMOGU_TEST "Build the tests" ON)
if(MOGUMOGU_TEST)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()