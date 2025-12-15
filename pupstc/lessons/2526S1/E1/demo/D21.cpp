using namespace std;
#include <iostream>

int main() {
    int a = 5;
    int b = 4;
    int c = 3;
    int d = 2;
    int f = 1;

    d = (a+b)-(d-f);
    a = d;
    f = (a - d) + (c * b);
    b = f - (d + a);
    a = (b * 2) - c;
    c = b * 2;
    a = a + 1;
    c = b * 3;

    return 0;
}
