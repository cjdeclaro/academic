#include <iostream>

using namespace std;

int main() {
    int id = 0;
    
    cout << "Person ID: ";
    cin >> id;
    cout << "\n\n";
    
    string firstNames[10] = {
        "John", "Jane", "Bill", "Alice", "Mark",
        "Sophia", "Luke", "Emma", "Ryan", "Olivia"
    };

    string lastNames[10] = {
        "Doe", "Air", "Gates", "Smith", "Brown",
        "Johnson", "White", "Taylor", "Miller", "Clark"
    };

    int ages[10] = {21, 32, 0, 29, 27, 35, 22, 31, 26, 28};
    
    cout << "Full Name: " + firstNames[id] + " " + lastNames[id] + "\n";
    if(ages[id] > 0){
        cout << "Age: " << ages[id];
    }
}
