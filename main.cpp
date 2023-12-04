#include <cmath>
#include "Eleven.h"
using namespace std;

int main() {
    Eleven a(4,'1');
    Eleven b("12A");
    Eleven res;
    cout << a.get_numbers()<< endl;
    cout << b.get_numbers()<< endl;
    res = a + b;
    cout << res << endl;
    return 0;
}