add_library(mogumogu STATIC)

target_compile_features(mogumogu PUBLIC cxx_std_17)
set_target_properties(mogumogu PROPERTIES CXX_EXTENSIONS OFF)

target_include_directories(mogumogu PUBLIC include)
target_sources(mogumogu PRIVATE
    include/mogumogu/core/vec2.hpp
    include/mogumogu/core/vec3.hpp
    include/mogumogu/core/ray.hpp
    include/mogumogu/core/intersect-info.hpp
    include/mogumogu/camera/film.hpp
    src/camera/film.cpp
    include/mogumogu/camera/camera.hpp
    include/mogumogu/camera/pinhole.hpp
    include/mogumogu/shape/shape.hpp
    include/mogumogu/shape/sphere.hpp
)

option(MOGUMOGU_TEST "Build the tests" ON)
if(MOGUMOGU_TEST)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()