#include <iostream>

using namespace std;

int main() {
    srand(time(0)); // To randomize every ms
    int dice = 0;
    string colors[6] = {
        "Yellow", "White", "Blue", "Pink", "Red", "Green"
    };

    for (int i = 0; i<3; i++){
        dice = rand() % 6;
        cout << colors[dice] << "\n";
    }
    return 0;
}
