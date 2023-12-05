cmake_minimum_required(VERSION 3.13)

project(lab_3)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall") # включаем все ворнинги 

# исполняемые 
#add_executable(main lab_1_main.cpp lab_1_separation.cpp)

# Добавляем цель для сборки и запуска тестов
add_executable(test_point test_point.cpp)
target_link_libraries(test_point gtest)

# Кастомные цели для запуска main и тестов

add_custom_target(start_test_point
    COMMAND ./test_point
    DEPENDS test_point
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)