#include <cmath>
#include "Eleven.h"
//#include "СheckingСorrectness.h"
using namespace std;

const unsigned char ZERO_IN_ASCII_CODE = '0';
const unsigned char NINE_ASCII_CODE = '9';
int A_IN_ELEVEN_NUMBER = 10;
const unsigned char A_IN_ASCII = 'A';
int A_WHOL = 1;
int Osnova = 11;

Eleven :: Eleven() : size(0), numbers {nullptr} {}

Eleven :: Eleven (const size_t& size, unsigned char value) {
    //проверка данных
    this->size = size;
    this->numbers = new unsigned char [size];
    for (size_t i = 0; i < size; i++) {
        numbers[i] = value;
    }
    //cout << "kon size  " << this << " " << *this << endl;
}

Eleven :: Eleven(const initializer_list <unsigned char>& list) {
    numbers = new unsigned char[list.size()];
    size_t i = 0;
    for (unsigned char value : list){
        //проверка
        numbers[i++] = value;
    }
    size = list.size();
}

Eleven :: Eleven (const string & numbers) {
    size=numbers.size();
    this->numbers = new unsigned char [size];
    for (size_t i=0; i < size; i++) {
        //проверка, если не подходит, то size--
        this->numbers[i] = numbers[i];
    }
        //cout << "kon str  " << this << " " << *this << endl;
}

Eleven :: Eleven (const Eleven& other) { //конструктор копиования
    size = other.size;
    numbers = new unsigned char [size];
    for (size_t i = 0; i < size; i++) {
        numbers[i] = other.numbers[i];
    }
    //cout << "kon copy  " << this << " " << *this << endl;
}

Eleven :: Eleven (Eleven&& other) noexcept {
    size = other.size;
    numbers = other.numbers;
    other.size = 0;
    other.numbers = nullptr;
    //cout << "kon other  " << this << " " << *this << endl;
}

Eleven::~Eleven() noexcept {
    if (size > 0) {
       // cout << "del  " << this  << " " << *this<< endl;
        size = 0;
        delete[] numbers;
        numbers = nullptr;
    }
}

size_t Eleven :: get_size() {
    return size;
}

unsigned char* Eleven :: get_numbers() {
    return numbers;
}

int char_to_int (char number) {
    if(number == 'A') {
        return A_IN_ELEVEN_NUMBER;
    }
    int num = number - ZERO_IN_ASCII_CODE;
    return num;
}

int Eleven :: numbers_to_int ()const {
    int result = 0;
    for (size_t i = 0; i < size; i++) {
        if (numbers[i] == 'A') {
            result += A_IN_ELEVEN_NUMBER * pow(Osnova,size - i - 1);
            continue;
        }
        result +=char_to_int(numbers[i]) * pow(Osnova,size - i - 1);
        }
    return result;
}

char int_to_char (int number) {
    if(number == A_IN_ELEVEN_NUMBER) {
        return A_IN_ASCII;
    }
    char num = number + ZERO_IN_ASCII_CODE;
    return num;
}

Eleven Eleven ::operator+(const Eleven& other) {
    int max_size_numbers = max(size, other.size)+1;
    unsigned char* first = new unsigned char [max_size_numbers-1];
    unsigned char* second = new unsigned char [max_size_numbers-1];
    if (size >= other.size){
        first = numbers;
        int k = min(size, other.size);
        for (int i=max_size_numbers-1; i>=0; i--) {
            if(k>=0) {
            second[i] = other.numbers[k];
            k--;
            } else second[i] = '0';
        }
    } else {
        first = other.numbers;
        int k = min(size, other.size);
        for (int i=max_size_numbers-1; i>=0; i--) {
            if(k>=0) {
            second[i] = numbers[k];
            k--;
            } else second[i] = '0';
        }
    }
    int whol_part = 0;
    Eleven result (max_size_numbers, ZERO_IN_ASCII_CODE) ;
    for (int i = max_size_numbers-2; i>=0; i--) {
        int sum;
        sum = char_to_int( first[i]) + char_to_int(second[i]); // 5+5=10
        //cout << char_to_int( first[i]) <<'+' << char_to_int(second[i]) << '=' << sum << endl;
        if (sum==A_IN_ELEVEN_NUMBER + whol_part) { // 10=10
            if (!whol_part) {
                result.numbers[i+1] = A_IN_ASCII;
                //cout << result.numbers[i+1] << " "<<i <<endl;
            } else {
                result.numbers[i+1] = int_to_char(whol_part);
                whol_part=A_WHOL;
               // cout << result.numbers<< endl;
            }
        } else {//if (sum < A_IN_ELEVEN_NUMBER) {
            sum +=whol_part;
            result.numbers[i+1] = int_to_char(sum%11);
            whol_part =  sum/11;
            //cout << result.numbers<<" "<< whol_part<< endl;
        }
    }
    if (result.numbers[0] == '0') {
        Eleven res(--result.size, ZERO_IN_ASCII_CODE);
        for (size_t i = 0; i< res.size; i++) {
            res.numbers[i] = result.numbers[i+1];
        }
        return res;
    }
return result;
}

ostream& operator<<(ostream &out, const Eleven &eleven) {
   for (size_t i = 0; i < eleven.size; ++i) {
      out << eleven.numbers[i];
   }
   return out;
}

istream& operator>>(istream &in, const Eleven &eleven) {
    cout << "Введите сначала количество символов в числе, затем - само число:\n";
    size_t size;
    in >> size;
    unsigned char* numbers = new unsigned char [size];
    for (size_t i = 0; i < size; i++) {
        in >> numbers[i];
    }
    return in;
}

Eleven Eleven ::operator-(const Eleven& other) {
    if (this->numbers_to_int() < other.numbers_to_int()) {
        cout << "Беззнаковые одннадцатирияные числа не могут хранить отрицательное значение" << endl;
        return -1;
    }
    int max_size_numbers = max(size, other.size);
    int null = 0;
    unsigned char* first = new unsigned char [max_size_numbers];
    unsigned char* second = new unsigned char [max_size_numbers];
    first = numbers;
    int k = min(size, other.size);
    for (int i=max_size_numbers; i>=0; i--) {
        if(k>=0) {
        second[i] = other.numbers[k];
        k--;
        } else second[i] = '0';
    }
    int whol_part = 0;
    //cout << second << endl;
    Eleven result (max_size_numbers, ZERO_IN_ASCII_CODE) ;
    for(int i=max_size_numbers-1; i>=0; i--) {
        if(char_to_int(first[i]) - whol_part >= char_to_int(second[i])){
            //cout << " 1 "<<first[i] << " " <<whol_part << " " << second[i] << endl;
            result.numbers[i] = int_to_char(char_to_int(first[i]) - whol_part - char_to_int(second[i]));
            /*
            if (result.numbers[i] == '0') {
                null++;
            } else null = 0;
            */
           whol_part = 0;
            //cout << " 2 "<<int_to_char (char_to_int(first[i]) - char_to_int(second[i]) )<< endl;
        } else {
            //cout << " 3 "<< first[i] << " " << whol_part << " " << second[i]  << " O"<< endl;
            result.numbers[i] = int_to_char(char_to_int(first[i]) - whol_part + Osnova - char_to_int(second[i]));
            //cout << " 4  "<< result.numbers[i] << endl;
            /*
            if (result.numbers[i] == '0') {
                null++;
            } else null = 0;
            */
            whol_part = 1;
        }
    }
    for(int i = 0; i < max_size_numbers; i++) {
        if (result.numbers[i] == '0') {
            null++;
        } else null = 0;
    }
    Eleven new_result(result.size - null, ZERO_IN_ASCII_CODE);
    for (size_t i = 0; i < new_result.size; i++) {
        new_result.numbers[i] = result.numbers[i+null];
    }
    return new_result;
}

bool Eleven :: operator<(const Eleven& other) const {
    if (this->numbers_to_int() < other.numbers_to_int()) {
        return true;
    }
    return false;
}

bool Eleven :: operator>(const Eleven& other) const {
    if (*this == other){
        return false;
    }
    return !(*this<other);
}

bool Eleven :: operator==(const Eleven& other) const {
    if (this->numbers_to_int() == other.numbers_to_int()) {
        return true;
    }
    return false;
}

bool Eleven :: operator!=(const Eleven& other) const{
    return !(*this == other);
}

Eleven Eleven :: operator=(const Eleven& other) {
    size = other.size;
    numbers = new unsigned char [size];
    for (size_t i=0; i<size; i++) {
        numbers[i] = other.numbers[i];
    }
    return *this;
}
