#include "square.h"

using namespace std;

template <typename T>
bool validate( point<T>& a,  point<T>& b,  point<T>& c,  point<T>& d) noexcept {
    if ((a == b) && (b == c) && (c == d)) {
        return false;
    }
    T x_center = (a.get_x() + b.get_x() + c.get_x() + d.get_x()) / 4.0;
    T y_center = (a.get_y() + b.get_y() + c.get_y() + d.get_y()) / 4.0;
    point<T> center(x_center, y_center);

    double fault = 1e-10;

    // side len
    T len_ab = dist(a, b);
    T len_ad = dist(a, d);
    T len_bc = dist(b, c);
    T len_cd = dist(c, d);

    // straight lines from center to corner
    T len_to_a = dist(center, a);
    T len_to_b = dist(center, b);
    T len_to_c = dist(center, c);
    T len_to_d = dist(center, d);

    if (abs(len_ab - len_ad) < fault && abs(len_ab - len_bc) < fault && abs(len_ab - len_cd) < fault) {
        if (abs(len_to_a - len_to_b) < fault && abs(len_to_b - len_to_c) < fault && abs(len_to_c - len_to_d) < fault) {
            return true;
        }
    }
    return false;
}

template <typename T>
square<T>::square() : A(0.0, 0.0), B(1.0, 0.0), C(1.0, 1.0), D(0.0, 1.0){}

template <typename T>
square<T>::square(point<T> a, point<T> b, point<T> c, point<T> d) {
    T permutation [3] {dist(a, b), dist(a, c), dist(a, d)};

    double diag = 0;
    for (int i = 0; i < 3; i++){
        if(permutation[i] > diag) {
            diag = permutation[i];
        }
    }
    for(int i = 0; i < 3; i++){
        if(permutation[i] == diag) {
            if(i == 0){
                bool check_square = validate(a, c, b, d);
                if(check_square){
                    A = a;
                    B = c;
                    C = b;
                    D = d;
                } else {
                    cout << "points not defined square" << endl;
                    square();
                }
            }
            if(i == 1){
                bool check_square = validate(a, b, c, d);
                if(check_square){
                    A = a;
                    B = b;
                    C = c;
                    D = d;
                } else {
                    cout << "points not defined square" << endl;
                   
                    square();
                }
            }
            if(i == 2){
                bool check_square = validate(a, c, d, b);
                if(check_square){
                    A = a;
                    B = c;
                    C = d;
                    D = b;
                } else {
                    cout << "points not defined square" << endl;
                    square();
                }
            }
        }
    } 
}

template <typename T>
square<T>::square(square<T>& other) : A(other.get_a()), B(other.get_b()), C(other.get_c()), D(other.get_d()) {}

template <typename T>
point<T> square<T>::get_a() const{
    return this->A;
}

template <typename T>
point<T> square<T>::get_b() const{
    return this->B;
}

template <typename T>
point<T> square<T>::get_c() const{
    return this->C;
}

template <typename T>
point<T> square<T>::get_d() const{
    return this->D;
}

template <typename T>
void square<T>::set_a(point<T> a){
    this->A = a;
}

template <typename T>
void square<T>::set_b(point<T> b){
    this->B = b;
}

template <typename T>
void square<T>::set_c(point<T> c){
    this->C = c;
}

template <typename T>
void square<T>::set_d(point<T> d){
    this->D = d;
}


template <typename T>
point<T> square<T>::geometric_centre(){
    T x_centre = (A.get_x() + B.get_x() + C.get_x() + D.get_x()) / 4.0;
    T y_centre = (A.get_y() + B.get_y() + C.get_y() + D.get_y()) / 4.0;
    point<T> centre(x_centre, y_centre);
    return centre;
}

template <typename T>
square<T> :: operator double() const {
    return 0.5 * dist(this->get_a(),this->get_c()) * dist(this->get_a(),this->get_c());
}

template <typename T>
bool operator==(square<T>& one_sq, square<T>& two_sq) {
    point<T> coordinates_one_sq [4] {one_sq.get_a(), one_sq.get_b(), one_sq.get_c(), one_sq.get_d()};
    point<T> coordinates_one_sq [4] {two_sq.get_a(), two_sq.get_b(), two_sq.get_c(), two_sq.get_d()};
    bool flag = false;
    for (int i = 0; i < 4; i++) {
        flag = false;
        for (int j = 0; j < 4; j++) {
            if (coordinates_one_sq[i] == coordinates_two_sq[j]) {
                flag = true;
                continue;
            }
        }
        if (!flag) {
            delete coordinates_one_sq; 
            delete coordinates_two_sq;
            return false;
        }
    }
    delete coordinates_one_sq; 
    delete coordinates_two_sq;
    return true;
}

template <typename T>
std::istream& operator>>(std::istream& is, square<T>& s) {
    point<T> a, b, c, d;
    is >> a >> b >> c >> d; 
    T* permutation = new T [3] {dist(a, b), dist(a, c), dist(a, d)};

    double diag = 0;
    for (int i = 0; i < 3; i++){
        if(permutation[i] > diag) {
            diag = permutation[i];
        }
    }
    for(int i = 0; i < 3; i++){
        if(permutation[i] == diag) {
            if(i == 0){
                bool check_square = validate(a, c, b, d);
                if(check_square){
                    s = square (a, c, b, d);
                } else {
                    cout << "points not defined square" << endl;
                }
            }
            if(i == 1){
                bool check_square = validate(a, b, c, d);
                if(check_square){
                    s = square (a, b, c, d);
                } else {
                    cout << "points not defined square" << endl;
                }
            }
            if(i == 2){
                bool check_square = validate(a, c, d, b);
                if(check_square){
                    s = square (a, c, d, b);
                } else {
                    cout << "points not defined square" << endl;
                }
            }
        }
    } 
    return is;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, square<T>& s) {
    os << s.get_a() << s.get_b() << s.get_c() << s.get_d();
    return os;
}
