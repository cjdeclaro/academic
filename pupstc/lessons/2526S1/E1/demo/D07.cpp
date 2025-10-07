#include <iostream>

using namespace std;

int main() {
    srand(time(0));
    int dice = 0;
    for (int i = 0; i<3; i++){
        dice = (rand() % 6) + 1; // 1 - 6
        
        switch(dice){
            case 1:
                cout << "Yellow\n";
                break;
            case 2:
                cout << "White\n";
                break;
            case 3:
                cout << "Blue\n";
                break;
            case 4:
                cout << "Pink\n";
                break;
            case 5:
                cout << "Red\n";
                break;
            case 6:
                cout << "Green\n";
                break;
        }
    }
    
    return 0;
}
