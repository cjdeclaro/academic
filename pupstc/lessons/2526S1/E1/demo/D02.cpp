#include <iostream>
using namespace std;

string getFullName(string f, string l){
    string fn = l + ", " + f + "\n";
    return fn;
}

int main() {
    string first_name = "John";
    string last_name = "Doe";
    cout << getFullName(first_name, last_name);
    
    first_name = "Jane";
    last_name = "Air";
    cout << getFullName(first_name, last_name);
    
    first_name = "Jane";
    last_name = "Air";
    cout << getFullName(first_name, last_name);
    
    first_name = "Jane";
    last_name = "Air";
    cout << getFullName(first_name, last_name);
    
    first_name = "Jane";
    last_name = "Air";
    cout << getFullName(first_name, last_name);
    
    first_name = "Jane";
    last_name = "Air";
    cout << getFullName(first_name, last_name);
    
    first_name = "Jane";
    last_name = "Air";
    cout << getFullName(first_name, last_name);
    
    first_name = "Jane";
    last_name = "Air";
    cout << getFullName(first_name, last_name);
    
    return 0;
}
