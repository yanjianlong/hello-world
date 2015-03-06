# version
cmake_minimum_required (VERSION 2.8)
set(LIB_NAME test_py)
set(PYTHON_INCLUDE_DIR /usr/include/python2.7)
# set(PYTHON_LIBRARIES /usr/lib/python2.7/config-x86_64-linux-gnu/libpython2.7.so)

# search the all dirs

include_directories(${PYTHON_INCLUDE_DIR})
aux_source_directory(. DIR_SRCS)


find_package(PythonInterp 2.7 REQUIRED)
find_package(PythonLibs 2.7 REQUIRED)


# create lib
add_library(${LIB_NAME} SHARED test.cpp test_py.cc)
target_link_libraries(${LIB_NAME} libpython2.7.so libboost_python.so)
