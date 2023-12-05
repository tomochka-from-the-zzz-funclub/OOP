#include "square.h"

using namespace std;

template <typename T>
bool square<T>::validate(const point<T>& a, const point<T>& b, const point<T>& c, const point<T>& d) noexcept {
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
    auto permutation {make_shared<T[]>(3)}; 
    permutation[0] = dist(a, b);
    permutation[1] = dist(a, c);
    permutation[2] = dist(a, d);
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
                    delete permutation;
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
                    delete permutation;
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
                    delete permutation;
                    square();
                }
            }
        }
    } 
}

template <typename T>
square<T>::square(square& other) : A(other.A), B(other.B), C(other.C), D(other.D) {}

template <typename T>
point<T> square<T>::geometric_centre(){
    T x_centre = (A.get_x() + B.get_x() + C.get_x() + D.get_x()) / 4.0;
    T y_centre = (A.get_y() + B.get_y() + C.get_y() + D.get_y()) / 4.0;
    point<T> centre(x_centre, y_centre);
    return centre;
}

template <typename T>
square<T> :: operator double() const {
    return 0.5 * dist(A,C) * dist(A,C);
}

template <typename T>
bool operator==(square<T>& one_sq, square<T>& two_sq) {
    auto coordinates_one_sq {make_shared<point<T>[]>(4)};
    auto coordinates_two_sq {make_shared<point<T>[]>(4)};
    coordinates_one_sq[0] = one_sq.A;
    coordinates_one_sq[1] = one_sq.B;
    coordinates_one_sq[2] = one_sq.C;
    coordinates_one_sq[3] = one_sq.D;
    coordinates_two_sq[0] = two_sq.A;
    coordinates_two_sq[1] = two_sq.B;
    coordinates_two_sq[2] = two_sq.C;
    coordinates_two_sq[3] = two_sq.D;
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
            return false;
        }
    }
    return true;
}

template <typename T>
std::istream& operator>>(std::istream& is, square<T>& s) {
    point<T> a, b, c, d;
    is >> a >> b >> c >> d; 
    auto permutation {make_shared<T[]>(3)};
    permutation[0] = dist(a, b);
    permutation[1] = dist(a, c);
    permutation[2] = dist(a, d);
    double diag = 0;
    for (int i = 0; i < 3; i++){
        if(permutation[i] > diag) {
            diag = permutation[i];
        }
    }
    for(int i = 0; i < 3; i++){
        if(permutation[i] == diag) {
            if(i == 0){
                bool check_square = square<T>::validate(a, c, b, d);
                if(check_square){
                    s = square (a, c, b, d);
                } else {
                    cout << "points not defined square" << endl;
                }
            }
            if(i == 1){
                bool check_square = square<T>::validate(a, b, c, d);
                if(check_square){
                    s = square (a, b, c, d);
                } else {
                    cout << "points not defined square" << endl;
                }
            }
            if(i == 2){
                bool check_square = square<T>::validate(a, c, d, b);
                if(check_square){
                    s = square (a, c, d, b);
                } else {
                    cout << "points not defined square" << endl;
                }
            }
        }
    } 
    delete permutation;
    return is;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, square<T>& s) {
    os << s.A << s.B << s.C << s.D;
    return os;
}


