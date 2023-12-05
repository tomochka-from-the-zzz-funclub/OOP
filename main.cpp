#include <iostream>
#include "point.h"
using namespace std;

template class point<int>;

int main() {
    point<int> a (0, 0);
    point<int> d (5, 0);
    cout << dist(a, d);
    return 0;
}