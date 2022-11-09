cmake_minimum_required(VERSION 3.0.0)
project(serialize_json VERSION 0.1.0)

# include(CTest)
# enable_testing()

find_package(nlohmann_json CONFIG REQUIRED)
find_package(msgpack CONFIG REQUIRED)

add_executable(serialize_json main.cpp)
target_link_libraries(serialize_json PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(serialize_json PRIVATE msgpackc msgpackc-cxx)

add_executable(ex_server ex_server.cpp)
target_link_libraries(ex_server PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(ex_server PRIVATE msgpackc msgpackc-cxx)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
