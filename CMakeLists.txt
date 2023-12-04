cmake_minimum_required(VERSION 3.13)

project(lab_2)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall") # включаем все ворнинги 

# исполняемые 
#add_executable(main lab_1_main.cpp lab_1_separation.cpp)

# Добавляем цель для сборки и запуска тестов
add_executable(test_Eleven Eleven.cpp test_Eleven.cpp)
target_link_libraries(test_Eleven gtest)

add_executable(main Eleven.cpp main.cpp)

# Кастомные цели для запуска main и тестов

add_custom_target(start_test
    COMMAND ./test_Eleven
    DEPENDS test_Eleven
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(start_main
    COMMAND ./main
    DEPENDS main
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)