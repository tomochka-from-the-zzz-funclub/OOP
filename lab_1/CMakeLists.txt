cmake_minimum_required(VERSION 3.13)

project(lab_1)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall") # включаем все ворнинги 

# исполняемые 
add_executable(main lab_1_main.cpp lab_1_separation.cpp)

# Добавляем цель для сборки и запуска тестов
add_executable(tests lab_1_separation.cpp lab_1_test.cpp)
target_link_libraries(tests gtest)

# Кастомные цели для запуска main и тестов
add_custom_target(start_main
    COMMAND ./main
    DEPENDS main
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(start_test
    COMMAND ./tests
    DEPENDS tests
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)


# Кастомная цель тестов и main
add_custom_target(start
    DEPENDS start_main start_test clean_out
)