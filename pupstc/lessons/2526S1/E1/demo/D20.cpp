using namespace std;
#include <iostream>

string getAddress(string val){
    string address[][2] = {
        {"ST", "Sto Tomas City"},
        {"CL", "Calamba City"},
        {"TN", "Tanauan City"}
    };
    
    string equi = "";
    
    for(int i = 0; i < 3; i++){
        if(address[i][0] == val){
            equi = address[i][1];
        }
    }
    
    return equi;
}

int main() {
    string users[][5] = {
        {"John", "Doe", "23", "TN", "Developer"},
        {"Jane", "Air", "25", "ST", "QA"},
        {"Bill", "Gates", "28", "CL", "Designer"},
        {"Ada", "Lovelace", "32", "ST", "Project Manager"}
    };
    
    int userId = 0;
    cout << "Show user info:";
    cin >> userId;
    
    userId -= 1;
    
    cout << "\nFirst name: " << users[userId][0];
    cout << "\nLast name: " << users[userId][1];
    cout << "\nAddress: " << getAddress(users[userId][3]);

    return 0;
}
