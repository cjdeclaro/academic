#include <iostream>

using namespace std;
int getRemainder(int a, int b){
    return a % b;
}

float getQuotient(float a, float b){
    return a / b;
}

int getProduct(int a, int b){
    return a * b;
}

int getDifference(int a, int b){
    return a - b;
}

int getSum(int a, int b){
    return a + b;
}

int main() {
    int a;
    int b;
    int choice;
    
    cout << "CALCULATE 2 VALUES\n\n";
    
    cout << "1st value:";
    cin >> a;
    cout << "2nd value:";
    cin >> b;
    
    cout << "\n\nPick Operation:";
    cout << "\n1 Addition";
    cout << "\n2 Subtraction";
    cout << "\n3 Multiplication";
    cout << "\n4 Division";
    
    cout << "\n\nChoice:";
    cin >> choice;
    
    switch(choice){
        case 1:
            cout << a << " + " << b << " = " << getSum(a, b);
            break;
        case 2:
            cout << a << " - " << b << " = " << getDifference(a, b);
            break;
        case 3:
            cout << a << " x " << b << " = " << getProduct(a, b);
            break;
        case 4:
            cout << a << " / " << b << " = " << getQuotient(a, b);
            break;
        default:
            cout << "Invalid Input";
    }
    
    return 0;
}
