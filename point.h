#ifndef POINT_H
#define POINT_H

#include <iostream>

class point {
protected:
  double X;
  double Y;
public:
  point();
  //point(std::istream &is);
  point(double x, double y);
  point(point& other);
  point(const point& other);

  double get_x() const;
  double get_y() const;
  
  friend std::istream& operator>>(std::istream& is, point& p);
  friend std::ostream& operator<<(std::ostream& os, const point& p);
  friend bool operator==(const point& one, const point& two);
};
  double dist(point one, point twe);
#endif 