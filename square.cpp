#include "square.h"

using namespace std;

bool square::validate(const point& a, const point& b, const point& c, const point& d) noexcept {
    if ((a == b) && (b == c) && (c == d)) {
        return false;
    }
    double x_center = (a.get_x() + b.get_x() + c.get_x() + d.get_x()) / 4.0;
    double y_center = (a.get_y() + b.get_y() + c.get_y() + d.get_y()) / 4.0;
    point center(x_center, y_center);

    double fault = 1e-10;

    // side len
    double len_ab = dist(a, b);
    double len_ad = dist(a, d);
    double len_bc = dist(b, c);
    double len_cd = dist(c, d);

    // straight lines from center to corner
    double len_to_a = dist(center, a);
    double len_to_b = dist(center, b);
    double len_to_c = dist(center, c);
    double len_to_d = dist(center, d);

    if (abs(len_ab - len_ad) < fault && abs(len_ab - len_bc) < fault && abs(len_ab - len_cd) < fault) {
        if (abs(len_to_a - len_to_b) < fault && abs(len_to_b - len_to_c) < fault && abs(len_to_c - len_to_d) < fault) {
            return true;
        }
    }
    return false;
}

square::square() : A(0.0, 0.0), B(1.0, 0.0), C(1.0, 1.0), D(0.0, 1.0){}

square::square(point a, point b, point c, point d) {
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

square::square(square& other) : A(other.A), B(other.B), C(other.C), D(other.D) {}

point square::get_a() const{
    return this->A;
}

point square::get_b() const{
    return this->B;
}

point square::get_c() const{
    return this->C;
}

point square::get_d() const{
    return this->D;
}

void square::set_a(point a){
    this->A = a;
}

void square::set_b(point b){
    this->B = b;
}

void square::set_c(point c){
    this->C = c;
}

void square::set_d(point d){
    this->D = d;
}

point square::geometric_centre(){
    double x_centre = (A.get_x() + B.get_x() + C.get_x() + D.get_x()) / 4.0;
    double y_centre = (A.get_y() + B.get_y() + C.get_y() + D.get_y()) / 4.0;
    point centre(x_centre, y_centre);
    return centre;
}

square :: operator double() const {
    return 0.5 * dist(A,C) * dist(A,C);
}

bool operator==(square& one_sq, square& two_sq) {
    point coordinates_one_sq [4] {one_sq.get_a(), one_sq.get_b(), one_sq.get_c(), one_sq.get_d()};
    point coordinates_two_sq [4] {two_sq.get_a(), two_sq.get_b(), two_sq.get_c(), two_sq.get_d()}; 

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
    delete coordinates_one_sq;
    delete coordinates_two_sq; 
    return true;
}

std::istream& operator>>(std::istream& is, square& s) {
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
                bool check_square = square::validate(a, c, b, d);
                if(check_square){
                    s = square (a, c, b, d);
                } else {
                    cout << "points not defined square" << endl;
                }
            }
            if(i == 1){
                bool check_square = square::validate(a, b, c, d);
                if(check_square){
                    s = square (a, b, c, d);
                } else {
                    cout << "points not defined square" << endl;
                }
            }
            if(i == 2){
                bool check_square = square::validate(a, c, d, b);
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

std::ostream& operator<<(std::ostream& os, square& s) {
    os << s.A << s.B << s.C << s.D;
    return os;
}


