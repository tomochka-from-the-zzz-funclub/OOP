#include "triangle.h"
using namespace std;

bool triangle::validate(const point& a, const point& b, const point& c) noexcept {
  if ((a == b) && (b == c) ) {
      return false;
  }

  double inaccuracy = 1e-6;

  double len_ab = dist(a, b);
  double len_bc = dist(b, c);
  double len_ac = dist(a,c);

  if (len_ab + len_ac - len_bc<= inaccuracy &&  len_ab + len_bc - len_ac<= inaccuracy && len_ac + len_bc - len_ab <= inaccuracy) {
    return false; 
  }
  return true;
}

triangle::triangle() : A(0.0, 0.0), B(2.0, 0.0), C(1.0, 2.0){}

triangle::triangle(const point& a, const point& b, const point& c) {
  bool is_triangle = validate(a, b, c);
  if (is_triangle) {
    A = a;
    B = b;
    C = c;
  } else {
    cout << "points not defined triagle" << endl;
    triangle();
  }
}

triangle::triangle(triangle& other){
  this->A = other.A;
  this->B = other.B;
  this->C = other.C;
}


std::ostream& operator<<(std::ostream& os, triangle& tri) {
    os << tri.A << " " << tri.B << " "<< tri.C;
  return os;
}

std::istream& operator>>(std::istream& is, triangle& tri) {
  point a, b, c;
    is >> a >> b >> c; 
    bool check_triangle = triangle::validate(a, c, b);
    if(check_triangle){
        tri = triangle (a, b, c);
    } else {
        cout << "points not defined triangle" << endl;
        tri = triangle();
    }
    return is;
}

point triangle::geometric_centre(){
  double x_centre = (A.get_x()+B.get_x() + C.get_x()) / 3;
  double y_centre = (A.get_y()+B.get_y() + C.get_y()) / 3;
  point centre(x_centre, y_centre);
  return centre;
}

triangle::operator double() const {
return abs(0.5 * ((A.get_x() - C.get_x()) * (B.get_y() - C.get_y()) - (A.get_y() - C.get_y()) * (B.get_x() - C.get_x())));
}

bool operator==(triangle& one_tri, triangle& two_tri){
  point* coordinates_one_tri = new point [3];
  point* coordinates_two_tri = new point [3];
  coordinates_one_tri[0] = one_tri.A;
  coordinates_one_tri[1] = one_tri.B;
  coordinates_one_tri[2] = one_tri.C;
  coordinates_two_tri[0] = two_tri.A;
  coordinates_two_tri[1] = two_tri.B;
  coordinates_two_tri[2] = two_tri.C;
  bool flag = false;
  for (int i = 0; i < 3; i++) {
    flag = false;
    for (int j = 0; j < 3; j++) {
        if (coordinates_one_tri[i] == coordinates_two_tri[j]) {
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