#ifndef FUNC_H
#define FUNC_H

#include "square.h"
#include "rectangle.h"
#include "triangle.h"

void print_everyone_area(figure** fig, int n);

double calculate_all_areas(figure** fig, int n);

void print_everyone_centres(figure** fig, int n);

void delete_elem (figure*** fig, int n, int k);

#endif