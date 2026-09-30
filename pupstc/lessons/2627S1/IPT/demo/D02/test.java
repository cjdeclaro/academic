class GameCharacter {
    String name;
    int hp;
    int damage;

    void attack(GameCharacter enemy){
        enemy.hp = enemy.hp - damage;
        System.out.println(name + " attacked " + enemy.name);
        System.out.println(enemy.name + " hp: " + enemy.hp);
    }

    void heal(){
        hp += 10;
        System.out.println(name + " healed!");
        System.out.println(name + " hp: " + hp);
    }
}

class Main {
    public static void main(String[] args) {
        GameCharacter pikachu = new GameCharacter();
        pikachu.name = "Pikachu";
        pikachu.hp = 300;
        pikachu.damage = 50;

        GameCharacter onix = new GameCharacter();
        onix.name = "Onix";
        onix.hp = 600;
        onix.damage = 15;

        pikachu.attack(onix);
        pikachu.attack(onix);
        pikachu.attack(onix);
        onix.attack(pikachu);
        onix.attack(pikachu);
        pikachu.attack(onix);
        pikachu.heal();
        pikachu.heal();
        pikachu.heal();
    }
}