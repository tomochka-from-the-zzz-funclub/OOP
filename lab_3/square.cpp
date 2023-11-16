#include "square.h"

using namespace std;

square::square() : A(0.0, 0.0), B(1.0, 0.0), C(1.0, 1.0), D(0.0, 1.0){}

square::square(point a, point b, point c, point d) : A(a), B(b), C(c), D(d){}

square::square(square& other) : A(other.A), B(other.B), C(other.C), D(other.D) {}

square::square(std::istream &is) {
  is >> A >> B >> C >> D;
}

point square::geometric_center(){
    double x_center = (A.get_x() + B.get_x() + C.get_x() + D.get_x()) / 4;
    double y_center = (A.get_y() + B.get_y() + C.get_y() + D.get_y()) / 4;
    point center(x_center, y_center);
    return center;
}

square :: operator double() const {
    double area;
    double* permutation = new double [6];
    permutation[0] = dist(A, B);
    permutation[1] = dist(A, C);
    permutation[2] = dist(A, D);
    permutation[3] = dist(B, C);
    permutation[4] = dist(B, D);
    permutation[5] = dist(C,D);
    double diag = 0;
    for (int i = 0; i < 6; i++){
        if(permutation[i] > diag) {
            diag = permutation[i];
        }
    }
    area = 0.5 * diag * diag;
    return area;
}

std::istream& operator>>(std::istream& is, square& s) {
    is >> s.A >> s.B >> s.C >> s.D; 
    return is;
}

std::ostream& operator<<(std::ostream& os, square& s) {
    os << s.A << s.B << s.C << s.D;
    return os;
}
/*
square check_point(point a, point b, point c, point d){
    double* permutation = new double [6];
    permutation[0] = dist(a, b);
    permutation[1] = dist(a, c);
    permutation[2] = dist(a, d);
    permutation[3] = dist(b, c);
    permutation[4] = dist(b, d);
    permutation[5] = dist(c, d);
    double max = 0;
    for (int i = 0; i < 6; i++){
        if(permutation[i] > max) {
            max = permutation[i];
        }
    }
    double line;
    for(int i = 0; i < 6; i++){
        if(permutation[i] != max) {
            line = permutation[i];
            break;
        }
    } 
    delete permutation;
    return square()

}
*/