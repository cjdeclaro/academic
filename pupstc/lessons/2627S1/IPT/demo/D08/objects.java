class Animal {
    String name;
    String species;
    String status = "hungry";

    // constructor
    Animal(String n, String s) {
        name = n;
        species = s;
    }

    public void eat(){
        System.out.println(name + " ate");
        status = "full";
    }

    public void checkStatus() {
        System.out.println(name + " is " + status);
    }

    public void makeSound(){
        System.out.println(name + " the " + species + " made a sound");
    }
}

class Person { // class
    String firstName;
    String lastName;
    int age;
    Animal pet;
    int money = 0;

    //constructor
    Person(String f, String l, int a){
        firstName = f;
        lastName = l;
        age = a;
    }

    void sayHelloTo(Person p){
        System.out.println(firstName + ": Hello " + p.firstName + "!");
    }

    void adopt(Animal a) {
        pet = a;
        System.out.println(firstName + " adopted " + a.name);
    }

    void pay(Person p, int cash) {
        System.out.println(firstName + " paid " + p.firstName + " PHP" + cash + ".00");
        p.money += cash;
    }

    void checkBalance() {
        System.out.println(firstName + " balance: " + money);
    }
}

class Main {
    public static void main(String[] args) {
        // creating an instance of a class creates an object
        Person john = new Person("John", "Doe", 23); //object
        Person jane = new Person("Jane", "Air", 24); //object
        Person steve = new Person("Steve", "Jobs", 25); //object

        Animal browny = new Animal("Browny", "fish");
        Animal whitey = new Animal("Whitey", "dog");

        john.sayHelloTo(jane);
        jane.sayHelloTo(steve);
        steve.sayHelloTo(john);

        jane.adopt(browny);
        jane.pet.makeSound();

        john.adopt(whitey);
        john.pet.makeSound();

        whitey.checkStatus();
        whitey.eat();
        whitey.checkStatus();

        jane.checkBalance();
        john.pay(jane,50);
        jane.checkBalance();
        steve.pay(jane,100);
        jane.checkBalance();
    }
}