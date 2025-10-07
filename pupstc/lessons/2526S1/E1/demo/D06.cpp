#include <iostream>

using namespace std;

int main() {
    int hp = 7;
    
    for(int i = 1; i <= 20; i++){
        if(i <= hp) {
            cout << "|";
        } else {
            cout << "-";
        }
    }
    
    if(hp < 5) {
        cout << " !";
    }
    
    return 0;
}
