#include "lab_1_separation.h"
#include <string>

using namespace std;

bool check_for_number (char simbol) {
    if ((simbol <= '9') && (simbol >= '0')) {
        return true;
    }
    return false;
}

string separation_of_letters_and_numbers (string string_with_letters_and_numbers) {
    string numbers = "";
    bool probel = false;
    bool start_of_answer = false;
    for (int i = 0; i < string_with_letters_and_numbers.size(); i++) {
        if (check_for_number(string_with_letters_and_numbers[i])) {
            numbers += string_with_letters_and_numbers[i];
            probel = false;
            start_of_answer = true;
        } else if ((probel == false) && (start_of_answer)) {
            numbers += " ";
            probel = true;
        }
    }
    return numbers;
}