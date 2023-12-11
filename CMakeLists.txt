cmake_minimum_required(VERSION 3.13)

project(lab_3)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall") # включаем все ворнинги 

# исполняемые 
#add_executable(main lab_1_main.cpp lab_1_separation.cpp)

# Добавляем цель для сборки и запуска тестов
add_executable(test_point point.cpp test_point.cpp)
target_link_libraries(test_point gtest)

add_executable(test_rectangle rectangle.cpp point.cpp test_rectangle.cpp)
target_link_libraries(test_rectangle gtest)

add_executable(test_square square.cpp point.cpp test_square.cpp)
target_link_libraries(test_square gtest)

add_executable(test_triangle triangle.cpp point.cpp test_triangle.cpp)
target_link_libraries(test_triangle gtest)

add_executable(main rectangle.cpp point.cpp main.cpp)
# Кастомные цели для запуска main и тестов

add_custom_target(start_test_point
    COMMAND ./test_point
    DEPENDS test_point
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(start_test_rectangle
    COMMAND ./test_rectangle
    DEPENDS test_rectangle
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(start_test_square
    COMMAND ./test_square
    DEPENDS test_square
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(start_test_triangle
    COMMAND ./test_triangle
    DEPENDS test_triangle
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(start_main
    COMMAND ./main
    DEPENDS main
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)




# Кастомная цель тестов и main
#add_custom_target(start DEPENDS start_main start_test )