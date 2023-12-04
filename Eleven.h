#ifndef Eleven_H
#define Eleven_H

#include <string>
#include <iostream>

class Eleven { 
private:
    size_t size;
    unsigned char *numbers;
public:
    Eleven();
    Eleven(const size_t & n, unsigned char t = 0);
    Eleven(const std::initializer_list <unsigned char> &t);
    Eleven(const std::string &t);
    Eleven(const Eleven& other);
    Eleven(Eleven&& other) noexcept;      
   
    size_t get_size();
    unsigned char* get_numbers();
    int numbers_to_int () const;

    Eleven operator+(const Eleven &other);
    Eleven operator-(const Eleven & other);
    bool operator==(const Eleven& other) const;
    bool operator!=(const Eleven& other) const;
    bool operator<(const Eleven& other) const;
    bool operator>(const Eleven& other) const;
    Eleven operator=(const Eleven& other);

    friend std::ostream &operator<<(std::ostream &os, const Eleven &eleven);
    friend std::istream& operator>>(std::istream& in, const Eleven& eleven);

    virtual ~Eleven() noexcept;

};

int char_to_int (char number);

#endif