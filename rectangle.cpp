#include "rectangle.h"

using namespace std;

template <typename T>
rectangle<T>::rectangle() : A(0.0, 0.0), B(2.0, 0.0), C(2.0, 1.0), D(0.0, 1.0){}

template <typename T>
rectangle<T>::rectangle(point<T> a, point<T> b, point<T> c, point<T> d) {
    double permutation [3] {dist(a, b), dist(a, c), dist(a, d) };
    double diag = 0;
    for (int i = 0; i < 3; i++){
        if(permutation[i] > diag) {
            diag = permutation[i];
        }
    }
    for(int i = 0; i < 3; i++){
        if(permutation[i] == diag) {
            if(i == 0){
                bool check_rectangle = validate(a, c, b, d);
                if(check_rectangle){
                    A = a;
                    B = c;
                    C = b;
                    D = d;
                } else {
                    cout << "points not defined rectangle" << endl;
                    rectangle();
                }
            }
            if(i == 1){
                bool check_rectangle = validate(a, b, c, d);
                if(check_rectangle){
                    A = a;
                    B = b;
                    C = c;
                    D = d;
                } else {
                    cout << "points not defined rectangle" << endl;
                    rectangle();
                }
            }
            if(i == 2){
                bool check_rectangle = validate(a, c, d, b);
                if(check_rectangle){
                    A = a;
                    B = c;
                    C = d;
                    D = b;
                } else {
                    cout << "points not defined rectangle" << endl;
                    rectangle();
                }
            }
        }
    } 
}

template <typename T>
rectangle<T>::rectangle(rectangle<T>& other) : A(other.A), B(other.B), C(other.C), D(other.D) {}

template <typename T>
point<T> rectangle<T>::get_a() const{
    return this->A;
}

template <typename T>
point<T> rectangle<T>::get_b() const{
    return this->B;
}

template <typename T>
point<T> rectangle<T>::get_c() const{
    return this->C;
}

template <typename T>
point<T> rectangle<T>::get_d() const{
    return this->D;
}

template <typename T>
void rectangle<T>::set_a(point<T> a){
    this->A = a;
}

template <typename T>
void rectangle<T>::set_b(point<T> b){
    this->B = b;
}

template <typename T>
void rectangle<T>::set_c(point<T> c){
    this->C = c;
}

template <typename T>
void rectangle<T>::set_d(point<T> d){
    this->D = d;
}

template <typename T>
point<T> rectangle<T>::geometric_centre(){
    double x_centre = (A.get_x() + B.get_x() + C.get_x() + D.get_x()) / 4.0;
    double y_centre = (A.get_y() + B.get_y() + C.get_y() + D.get_y()) / 4.0;
    point<T> centre(x_centre, y_centre);
    return centre;
}

template <typename T>
rectangle<T>::operator double() const {
    double area = dist(A, B) * dist(B, C);
    return area;
}

template <typename T>
bool operator==(rectangle<T>& one_rec, rectangle<T>& two_rec) {
    point<T> coordinates_one_rec [4]{one_rec.get_a(), one_rec.get_b(), one_rec.get_c(), one_rec.get_d()};
    point<T> coordinates_two_rec [4]{two_rec.get_a(), two_rec.get_b(), two_rec.get_c(), two_rec.get_d()};    
    bool flag = false;
    for (int i = 0; i < 4; i++) {
        flag = false;
        for (int j = 0; j < 4; j++) {
        if (coordinates_one_rec[i] == coordinates_two_rec[j]) {
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
std::istream& operator>>(std::istream& is, rectangle<T>& s) {
    point<T> a, b, c, d;
    is >> a >> b >> c >> d; 
    double permutation [3] {dist(a, b), dist(a, c), dist(a, d) };
    double diag = 0;
    for (int i = 0; i < 3; i++){
        if(permutation[i] > diag) {
            diag = permutation[i];
        }
    }
    for(int i = 0; i < 3; i++){
        if(permutation[i] == diag) {
            if(i == 0){
                bool check_rectangle = validate(a, c, b, d);
                if(check_rectangle){
                    s = rectangle(a, c, b, d);
                } else {
                    cout << "points not defined rectangle" << endl;
                }
            }
            if(i == 1){
                bool check_rectangle = validate(a, b, c, d);
                if(check_rectangle){
                    s = rectangle(a, b, c, d);
                } else {
                    cout << "points not defined rectangle" << endl;
                }
            }
            if(i == 2){
                bool check_rectangle = validate(a, b, d, c);
                if(check_rectangle){
                    s = rectangle(a, b, d, c);
                } else {
                    cout << "points not defined rectangle" << endl;
                }
            }
        }
    } 
    return is;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, rectangle<T>& s) {
    os << s.get_a() << s.get_b() << s.get_c() << s.get_d();
    return os;
}

template <typename T>
bool validate(const point<T>& a, const point<T>& b, const point<T>& c, const point<T>& d) noexcept {
    if ((a == b) && (b == c) && (c == d)) {
        return false;
    }
    double len_ab = dist(a, b);
    double len_ad = dist(a, d);
    double len_bc = dist(b, c);
    double len_cd = dist(c, d);
    double diag_ac = dist(a, c);
    double fault = 1e-6;
    if((len_ab == len_cd) && (len_bc == len_ad)) {
        if(len_ab * len_ab + len_bc * len_bc - diag_ac * diag_ac <= fault) {
            return true;
        }
    }
    return false;
}
