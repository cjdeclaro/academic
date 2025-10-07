#include <iostream>

using namespace std;

int main() {
    int time = 12;
    
    //say good morning if 0 - 11
    // say good day if 12
    // say good afternoon 13 - 18
    // say good evening 19 - 23
    // wrong input if < 0 || > 23
    
    if(time < 0 || time > 23){
        cout << "Wrong input";
    } else {
        cout << "Good ";
        
        if(time <= 11){
            cout << "Morning!";
        } else if (time == 12){
            cout << "Day!";
        } else if (time <= 18) {
            cout << "Afternoon!";
        } else {
            cout << "Evening!";
        }
    }
    
    if(time >= 0 && time <= 23){
        cout << "Good ";
        
        if(time <= 11){
            cout << "Morning!";
        } else if (time == 12){
            cout << "Day!";
        } else if (time <= 18) {
            cout << "Afternoon!";
        } else {
            cout << "Evening!";
        }
    } else {
        cout << "Wrong input";
    }
    
    return 0;
}
