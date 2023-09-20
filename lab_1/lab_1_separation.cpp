#include "lab_1_separation.h"
#include <string>

using namespace std;

bool is_number(char simbol) {
    return ((simbol <= '9') && (simbol >= '0'));
}

string filter_numbers(string input_string) {
    string numbers = "";
    bool space = false;
    bool start_of_answer = false;
    for (size_t i = 0; i < input_string.size(); i++) {
        if (is_number(input_string[i])) {
            numbers += input_string[i];
            space = false;
            start_of_answer = true;
        } else if ((space == false) && (start_of_answer)) {
            numbers += " ";
            space = true;
        }
    }
    return numbers;
}