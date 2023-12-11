#include "rectangle.h"

using namespace std;

rectangle::rectangle() : A(0.0, 0.0), B(2.0, 0.0), C(2.0, 1.0), D(0.0, 1.0){}

rectangle::rectangle(point a, point b, point c, point d) {
    double permutation [3] {dist(a, b), dist(a, c), dist(a, d)};
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

rectangle::rectangle(rectangle& other) : A(other.A), B(other.B), C(other.C), D(other.D) {}

point rectangle::get_a() const{
    return this->A;
}

point rectangle::get_b() const{
    return this->B;
}

point rectangle::get_c() const{
    return this->C;
}

point rectangle::get_d() const{
    return this->D;
}

void rectangle::set_a(point a){
    this->A = a;
}

void rectangle::set_b(point b){
    this->B = b;
}

void rectangle::set_c(point c){
    this->C = c;
}

void rectangle::set_d(point d){
    this->D = d;
}

point rectangle::geometric_centre(){
    double x_centre = (A.get_x() + B.get_x() + C.get_x() + D.get_x()) / 4.0;
    double y_centre = (A.get_y() + B.get_y() + C.get_y() + D.get_y()) / 4.0;
    point centre(x_centre, y_centre);
    return centre;
}

rectangle::operator double() const {
    double area = dist(A, B) * dist(B, C);
    return area;
}

bool operator==(rectangle& one_rec, rectangle& two_rec) {
    point coordinates_one_rec [4] {one_rec.get_a(), one_rec.get_b(), one_rec.get_c(), one_rec.get_d()};
    point coordinates_two_rec [4] {two_rec.get_a(), two_rec.get_b(), two_rec.get_c(), two_rec.get_d()};    
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

std::istream& operator>>(std::istream& is, rectangle& s) {
    point a, b, c, d;
    is >> a >> b >> c >> d; 
    double permutation [3] {dist(a, b), dist(a, c), dist(a, d)};
    double diag = 0;
    for (int i = 0; i < 3; i++){
        if(permutation[i] > diag) {
            diag = permutation[i];
        }
    }
    for(int i = 0; i < 3; i++){
        if(permutation[i] == diag) {
            if(i == 0){
                bool check_rectangle = rectangle::validate(a, c, b, d);
                if(check_rectangle){
                    s = rectangle(a, c, b, d);
                } else {
                    cout << "points not defined rectangle" << endl;
                }
            }
            if(i == 1){
                bool check_rectangle = rectangle::validate(a, b, c, d);
                if(check_rectangle){
                    s = rectangle(a, b, c, d);
                } else {
                    cout << "points not defined rectangle" << endl;
                }
            }
            if(i == 2){
                bool check_rectangle= rectangle::validate(a, b, d, c);
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

std::ostream& operator<<(std::ostream& os, rectangle& s) {
    os << s.A << s.B << s.C << s.D;
    return os;
}

bool rectangle::validate(const point& a, const point& b, const point& c, const point& d) noexcept {
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
