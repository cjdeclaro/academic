#include <iostream>

using namespace std;

// Function overloading
float getSum(double a, int b, int c){
    return a + b + c;
}

int getSum(int a, int b, int c){
    return a + b + c;
}

int getSum(int a, int b){
    return a + b;
}

// Error handling
string getSum(int a){
    return "Too few arguments";
}

string getSum(){
    return "No arguments";
}

int main() {
    cout << getSum(5);
    
    return 0;
}
