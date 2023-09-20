#include <gtest/gtest.h>
#include "lab_1_separation.h"
#include <iostream>
#include <string>

using namespace std;

int main () {
    string input_string, answer_number;
    cout << "Введите строку, состоящую из цифр и букв, перемешанных между собой:";
    cin >> input_string;
    answer_number = filter_numbers(input_string);
    cout << " Числа, найденные в строке: " << answer_number << endl;
    return 0;
}