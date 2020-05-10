add_executable(${PROJECT_NAME} main.cpp)

include_directories(../src)
target_link_libraries(${PROJECT_NAME} src)