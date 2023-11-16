#include "square.h"

using namespace std;
int main() {
    square A;
    cin >> A;
    cout << A << " " << double(A) << " " << A.geometric_center() << endl;
}