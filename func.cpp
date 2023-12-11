#include "func.h"

using namespace std;

void print_everyone_area(figure** fig, int n){
    for(int i = 0; i < n; i++) {
        double area = *(fig[i]);
        cout << "Area = " <<  area << endl;
    }
}

double calculate_all_areas(figure** fig, int n){
    double area = 0;
    for(int i = 0; i < n; i++) {
        area += *(fig[i]);
    }
    return area;
}

void print_everyone_centres(figure** fig, int n){
    for(int i = 0; i < n; i++) {
        cout << "Geometric center = " << (*(fig[i])).geometric_centre() << endl;
    }
}

void delete_elem (figure*** fig, int n, int k){
    figure** test = new figure* [n-1];
    bool find = false;
    for(int i = 0; i < n; i++){
        if (i == k) {
            find = true;
            //delete **fig[i];
            continue;
        }
        cout << *(*fig)[i] << endl;
        if (find) {
            *test[i-1] = *((*fig)[i]);
        } else {
            *test[i] = *(*fig)[i];
        }
    }
    //delete **fig;
    *fig = test;
    //delete test;
}
