#include <gtest/gtest.h>
#include "lab_1_separation.h"
#include <iostream>
#include <string>

using namespace std;

int main () {
    string string_with_letters_and_numbers, answer_number;
    cout << "Введите строку, состоящую из цифр и букв, перемешанных между собой:";
    cin >> string_with_letters_and_numbers;
    answer_number = separation_of_letters_and_numbers(string_with_letters_and_numbers);
    cout << " Числа, найденные в строке: " << answer_number << endl;
    return 0;
}