add_library(mogumogu STATIC)

target_compile_features(mogumogu PUBLIC cxx_std_17)
set_target_properties(mogumogu PROPERTIES CXX_EXTENSIONS OFF)

target_include_directories(mogumogu PUBLIC include)
target_sources(mogumogu PRIVATE
    include/mogumogu/core/vec2.hpp
    include/mogumogu/core/vec3.hpp
    include/mogumogu/core/ray.hpp
    include/mogumogu/core/intersect-info.hpp
    include/mogumogu/core/constant.hpp

    include/mogumogu/camera/film.hpp
    src/camera/film.cpp
    include/mogumogu/camera/camera.hpp
    src/camera/camera.cpp
    include/mogumogu/camera/pinhole.hpp
    src/camera/pinhole.cpp

    include/mogumogu/shape/shape.hpp
    include/mogumogu/shape/sphere.hpp
    src/shape/sphere.cpp
    include/mogumogu/shape/plane.hpp
    src/shape/plane.cpp

    include/mogumogu/material/material.hpp
    include/mogumogu/material/lambert.hpp
    src/material/lambert.cpp

    include/mogumogu/core/primitive.hpp
    src/core/primitive.cpp

    include/mogumogu/accel/accel.hpp
    src/accel/accel.cpp
    include/mogumogu/accel/linear.hpp
    src/accel/linear.cpp

    include/mogumogu/sampler/rng.hpp
    src/sampler/rng.cpp
)

option(MOGUMOGU_TEST "Build the tests" ON)
if(MOGUMOGU_TEST)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()