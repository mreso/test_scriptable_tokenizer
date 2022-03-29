cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(torchtext_kernels)
find_package(Torch REQUIRED PATHS /home/ubuntu/test_scriptable_tokenizer/libtorch)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_library(torchtext SHARED IMPORTED)
set_property(TARGET torchtext PROPERTY IMPORTED_LOCATION /home/ubuntu/text/build/torchtext/csrc/libtorchtext.so)

add_executable(torchtext_kernels main.cpp)

target_link_libraries(torchtext_kernels  "${TORCH_LIBRARIES}" "-Wl,--no-as-needed -Wl,--whole-archive" torchtext "-Wl,--as-needed -Wl,--no-whole-archive")
