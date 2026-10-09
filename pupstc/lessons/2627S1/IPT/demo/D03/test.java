class Main {
    public static void main(String[] args) {
        int money = 20000;
        int age = 18;

        boolean hasEnoughMoney = money > 10000;
        boolean isLegalAge = age >= 18;

        if(hasEnoughMoney && isLegalAge){
            System.out.println("Allowed");
        } else {
            System.out.println("Denied");
        }
    }
}