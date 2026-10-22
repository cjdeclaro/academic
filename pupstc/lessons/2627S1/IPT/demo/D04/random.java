class Main {
    public static void main(String[] args) {
        int maxNumber = 6;
        int dice1 = (int)(Math.random()*maxNumber);
        int dice2 = (int)(Math.random()*maxNumber);
        int dice3 = (int)(Math.random()*maxNumber);

        String[] colors = {"white", "pink", "blue", "red", "yellow", "green"};

        System.out.println(colors[dice1]);
        System.out.println(colors[dice2]);
        System.out.println(colors[dice3]);
    }
}