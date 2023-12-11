#include <iostream>
#include "point.h"
#include "square.h"
using namespace std;

//template class point<int>;

int main() {
    point<int> a (0, 0);
    point<int> d (5, 0);
    square<int> fi(a, d, a, d);
    cin >> fi;
    fi.geometric_centre();
    //square<int> se(fi);
    cout << dist(a, d);
    cout << fi << "\n" << endl;
    return 0;
}