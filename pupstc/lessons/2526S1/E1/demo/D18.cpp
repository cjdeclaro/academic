using namespace std;
#include <iostream>

int numberOfPlayable = 5;

class GameCharacter { // class (blueprint)
    public:
        string name; // attributes
        int hp;
};

void showList(GameCharacter cp[]){
    for(int i = 0; i<numberOfPlayable; i++){
         cout << i+1 << " " << cp[i].name << "\n";
    }
}

int main() {
    GameCharacter a, b, c, d, e;

    a.name = "Nana";
    b.name = "Harith";
    c.name = "Estes";
    d.name = "Belerick";
    e.name = "Akai";
    
    GameCharacter characterPool[numberOfPlayable] = {
        a, b, c, e, d
    };

    cout << "Pick a hero:\n";
    
    showList(characterPool);

    return 0;
}
