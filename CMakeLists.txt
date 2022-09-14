cmake_minimum_required(VERSION 3.0.0)
project(train VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(train main.cpp)

find_package (Boost COMPONENTS unit_test_framework REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(train PRIVATE nlohmann_json::nlohmann_json)

enable_testing()

add_test(NAME Test1 COMMAND train)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
