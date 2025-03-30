cmake_minimum_required(VERSION 3.10.0)
project(test LANGUAGES Fortran)

find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)

add_executable(test main.f90)
target_link_libraries(test PRIVATE BLAS PkgConfig::GTK4)

target_include_directories(test PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_directories(test PRIVATE ${GTK4_LIBRARY_DIRS})
target_link_libraries(test PRIVATE ${GTK4_LIBRARIES})
target_compile_definitions(test PRIVATE ${GTK4_CFLAGS_OTHER})

target_include_directories(test PRIVATE "/usr/local/include/gtk-4-fortran")

message(STATUS "GTK4_INCLUDE_DIRS: ${GTK4_INCLUDE_DIRS}")