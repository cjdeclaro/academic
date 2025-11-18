#include <iostream>

using namespace std;

int getSum(int a, int b){ //parameters
    int sum = a + b;
    return sum;
}

int main() {
    int a;
    int b;
    
    cout << "CALCULATE 2 VALUES\n\n";
    
    cout << "1st value:";
    cin >> a;
    cout << "2nd value:";
    cin >> b;
    
    cout << "SUM: " << getSum(a, b);
    
    return 0;
}
