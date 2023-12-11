#ifndef FIGURE_H
#define FIGURE_H

#include "point.h"

class figure {
public:
  virtual point geometric_centre() = 0;
  virtual operator double() const = 0; // находим площадь

  virtual ~figure() {};
};

#endif 