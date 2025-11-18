using namespace std;
#include <iostream>

class GameCharacter {
    public:
        string name;
        string type;
        string cryUrl;
        int hp;
        int damage;
        int healPoints = 0;
        bool isFainted = false;
        
        int attack(GameCharacter kalaban){
            cout << "\n" << name << " attacked " << kalaban.name;
            kalaban.hp -= damage;
            cout << "\n" << kalaban.name << " hp: " << kalaban.hp;

            if(kalaban.hp <= 0){
                isFainted = true;
                cout << "\n" << kalaban.name << " fainted";
            }

            return kalaban.hp;
        }  

        int heal(GameCharacter kakampi){
            cout << "\n" << name << " healed " << kakampi.name;
            kakampi.hp += healPoints;
            cout << "\n" << kakampi.name << " hp: " << kakampi.hp; 

            return kakampi.hp;
        }     
};

int main() {
    GameCharacter pikachu; //object
    GameCharacter eevee; //object
    GameCharacter chansey; //object
    
    pikachu.name = "Pikachu";
    pikachu.hp = 100;
    pikachu.damage = 20;
    
    eevee.name = "Eevee";
    eevee.hp = 200;
    eevee.damage = 10;

    chansey.name = "Chansey";
    chansey.hp = 500;
    chansey.damage = 1;
    chansey.healPoints = 5;
    
    pikachu.hp = eevee.attack(pikachu);
    pikachu.hp = eevee.attack(pikachu);
    pikachu.hp = eevee.attack(pikachu);
    pikachu.hp = eevee.attack(pikachu);
    pikachu.hp = eevee.attack(pikachu);

    pikachu.hp = chansey.heal(pikachu);
    
    return 0;
}
