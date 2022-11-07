cmake_minimum_required(VERSION 3.0.0)
project(serialize_json VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(nlohmann_json CONFIG REQUIRED)
add_executable(serialize_json main.cpp)

target_link_libraries(serialize_json PRIVATE nlohmann_json::nlohmann_json)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
