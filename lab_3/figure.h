#ifndef FIGURE_H
#define FIGURE_H

#include "point.h"

class figure {
public:
  point geometric_center();
  friend std::istream& operator>>(std::istream& is, figure& fug);
  friend std::ostream& operator<<(std::ostream& os, figure& fug);
  operator int() const; // находим площадь
  virtual ~figure() {};
};

#endif // FIGURE_H