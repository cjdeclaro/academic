#include <iostream>

using namespace std;

int main() {
    int startingStation = 2;
    int destinationStation = 10;
    
    int fare = 0;
    
    if(startingStation <= destinationStation) {
        while(startingStation <= destinationStation){
            cout << startingStation << "\n";
            startingStation = startingStation + 1;
            fare += 5;
        }
    }  else {
        while(startingStation >= destinationStation){
            cout << startingStation << "\n";
            startingStation = startingStation - 1;
            fare += 5;
        }
    }
    
    cout << "Fare: " << fare;
    
    return 0;
}
