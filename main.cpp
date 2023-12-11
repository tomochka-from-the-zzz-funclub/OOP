#include "func.h"
#include "square.h"
#include "rectangle.h"
#include "triangle.h"


using namespace std;
int main() {
    /*

    int go;
    figure** a = new figure* [6];
    for (int i = 0; i < 6; i++){
        cin >> go;
            if (go == 1) {
            square t;
            cin >> t;
            a[i] = new square(t);
        }
        if (go == 2) {
            rectangle test;
            cin >> test;
            a[i] = new rectangle (test);
        }
        if (go == 3) {
            triangle test;
            cin >> test;
            a[i] = new triangle(test);
        }
        
    }
    //print_everyone_area(a, 6);
    delete_elem(&a, 6, 0);
    // print_everyone_area(a, 6);
    
    figure** a = new figure* [1];
    rectangle test;
    cin >> test;
    a[0] = new rectangle (test);
    print_everyone_area(a, 1);
    */
    rectangle test1(point(1, 1), point(1, 3), point(5, 3), point(5, 1));
    rectangle test2(point(0, 0), point(0, 3), point(5, 3), point(5, 0));

    if(test1 == test2){
        cout << "y\n";
    }else {
        cout << "n\n";
    }
}