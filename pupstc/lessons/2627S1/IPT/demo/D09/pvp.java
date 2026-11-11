import java.util.Scanner;

class Item {
    String name;
    int hpChange;
    int damageChange;
    int damageReduction;
    int price;

    public Item(String n, int h, int dC, int dR, int p) {
        name = n;
        hpChange = h;
        damageChange = dC;
        damageReduction = dR;
        price = p;
    }
}

class Player {
    int gold = 0;
    int hp = 100;
    int maxItems = 3;
    int armor = 0;
    int damage = 10;
    int itemCounter = 0;
}

class Main {
    public static int rollDice(int maxNumber) {
        return (int)(Math.random()*maxNumber) + 1;
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        Item potion = new Item("potion", 20, 0, 0, 30);
        Item knife = new Item("knife", 0, 10, 0, 20);
        Item shield = new Item("shield", 0, 0, 10, 20);

        Item elixir = new Item("elixir", 40, 0, 0, 50);
        Item sword = new Item("sword", 0, 20, 0, 30);
        Item armor = new Item("shield", 0, 0, 20, 30);

        Item[] store = { potion, knife, shield, elixir, sword, armor };

        Player p1 = new Player();
        Player p2 = new Player();

        // Every turn, a player gets 10 gold
        // Every turn, a player can buy 1 item
        // Every turn, a player can choose if they will buy or attack

        int turnCounter = 0;
        String answer;
        Player currentPlayer = p1;
        Player opponent = p2;
        int currentPlayerNumber = 1;
        int opponentNumber = 2;
        int itemNumber = 0;
        Item chosenItem;

        while(opponent.hp > 0 || currentPlayer.hp > 0) {
            turnCounter += 1;
            System.out.println("\n\nTurn " + turnCounter);
            System.out.println("Player: Player " + currentPlayerNumber);

            //Gameplay
            currentPlayer.gold += 10;
            System.out.println("\nGold: " + currentPlayer.gold);
            System.out.println("HP: " + currentPlayer.hp);
            System.out.println("Damage: " + currentPlayer.damage);
            System.out.println("Armor: " + currentPlayer.armor);

            System.out.print("\nDo you want to attack or buy? [a/b]: ");
            answer = scanner.nextLine();

            if(answer.equals("a")) { //attack mode
                System.out.println("\nPlayer" + currentPlayerNumber + " attacked Player " + opponentNumber + "! -" + currentPlayer.damage);

                opponent.armor -= currentPlayer.damage;
                if(opponent.armor < 0) {
                    opponent.hp += opponent.armor;
                    opponent.armor = 0;
                }
                
                System.out.println("Player " + opponentNumber + " armor: " + opponent.armor);
                System.out.println("Player " + opponentNumber + " HP: " + opponent.hp);
            } else {
                System.out.println("\nStore:\n");
                System.out.println("1: Potion (30)");
                System.out.println("2: Knife (20)");
                System.out.println("3: Shield (20)");
                System.out.println("4: Elixir (50)");
                System.out.println("5: Sword (30)");
                System.out.println("6: Armor (30)");

                System.out.print("What will you buy? ");
                itemNumber = scanner.nextInt();
                scanner.nextLine();

                chosenItem = store[itemNumber - 1];
                System.out.println("You have chosen " + chosenItem.name);

                if(currentPlayer.gold >= chosenItem.price) {
                    currentPlayer.hp += chosenItem.hpChange;
                    if(currentPlayer.hp > 100) {
                        currentPlayer.hp = 100;
                    }
                    currentPlayer.damage += chosenItem.damageChange;
                    currentPlayer.armor += chosenItem.damageReduction;
                } else {
                    System.out.println("Not enough gold!");
                }
            }

            // Switch player
            if(currentPlayer == p1) {
                currentPlayerNumber = 2;
                opponentNumber = 1;
                currentPlayer = p2;
                opponent = p1;
            } else {
                currentPlayerNumber = 1;
                opponentNumber = 2;
                currentPlayer = p1;
                opponent = p2;
            }
        }
    }
}