#cmake_minimum_required(VERSION 3.10)

#project(test_tokenizer)
#add_executable(test_tokenizer main.cpp)

#find_package(Torch REQUIRED)
#find_package(PythonLibs REQUIRED)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

#add_library(_torchtext SHARED IMPORTED)
#set_property(TARGET _torchtext PROPERTY IMPORTED_LOCATION /home/ubuntu/ScriptableTokenizers/venv/lib/python3.8/site-packages/torchtext/_torchtext.so)

#target_include_directories(test_tokenizer PRIVATE ${TORCH_INCLUDE_DIRS})
#target_link_libraries(test_tokenizer PRIVATE _torchtext ${PYTHON_LIBRARIES} ${TORCH_LIBRARIES})


cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(torchtext_kernels)
find_package(Torch REQUIRED)
find_package(PythonLibs REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_library(_torchtext SHARED IMPORTED)
set_property(TARGET _torchtext PROPERTY IMPORTED_LOCATION /home/ubuntu/ScriptableTokenizers/venv/lib/python3.8/site-packages/torchtext/_torchtext.so)

add_executable(torchtext_kernels main.cpp)

target_link_libraries(torchtext_kernels _torchtext ${PYTHON_LIBRARIES} "${TORCH_LIBRARIES}")