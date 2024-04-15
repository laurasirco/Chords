cmake_minimum_required (VERSION 3.8)

find_package(Poco REQUIRED Data Foundation DataSQLite )

# Add source to this project's executable.
add_executable (poco01 "poco01.cpp" "poco01.h")

set(POCO_PREFIX      "/usr/local") # the directory containing "include" and "lib"
set(POCO_INCLUDE_DIR "${POCO_PREFIX}/include")
set(POCO_LIB_DIR     "${POCO_PREFIX}/lib")

target_include_directories(poco01 PRIVATE "${POCO_INCLUDE_DIR}")

target_link_libraries(poco01 Poco::Foundation Poco::Data Poco::DataSQLite)

code-block
