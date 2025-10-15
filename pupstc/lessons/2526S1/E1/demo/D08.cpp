#include <iostream>

using namespace std;

int main() {
    int rows = 20;
    int rowsCopy = rows - 1;
    for(int i = 1; i <= rows; i++) {
        for(int k = 1; k <= rowsCopy; k++){
            cout << " ";
        }
        rowsCopy--;
        
        for(int j = 1; j <= i + (i - 1); j++){
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
