cmake_minimum_required(VERSION 3.10)

project(test_tokenizer)
add_executable(test_tokenizer main.cpp)

find_package(Torch REQUIRED)
target_include_directories(test_tokenizer PRIVATE ${TORCH_INCLUDE_DIRS})
target_link_libraries(test_tokenizer PRIVATE ${TORCH_LIBRARIES})