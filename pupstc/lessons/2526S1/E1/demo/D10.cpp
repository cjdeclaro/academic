#include <iostream>

using namespace std;

int main() {
    string firstNames[10] = {
        "John", "Jane", "Bill", "Alice", "Mark",
        "Sophia", "Luke", "Emma", "Ryan", "Olivia"
    };

    string lastNames[10] = {
        "Doeee", "Airrr", "Gates", "Smith", "Brown",
        "Johnson", "White", "Taylor", "Miller", "Clark"
    };

    int ages[10] = {21, 32, 0, 29, 27, 35, 22, 31, 26, 28};
    
    cout << "ID\tLName\tFName\n\n";
    for(int i = 0; i < 10; i++){
        cout << i << "\t" << lastNames[i] << "\t" << firstNames[i] << "\n";
    }
    
    int id = 0;
    cout << "\n\nPerson ID: ";
    cin >> id;
    
    cout << "\n\n" << "Full Name: " << firstNames[id] + " " + lastNames[id];
    cout << "\n" << "Age: " << ages[id];
}
