class Main {
    public static void main(String[] args) {
        String[] firstNames = {"John", "Steve", "Bill", "Ada", "Jane"};
        String[] lastNames = {"Doe", "Jobs", "Gates", "Lovelace", "Air"};
        int[] ages = {25, 26, 27, 28, 29};

        System.out.println("PEOPLE\n");
        for(int i = 0; i < firstNames.length; i++) {
            System.out.println("Full Name: " + firstNames[i] + " " + lastNames[i]);
            System.out.println("Age: " + ages[i] + "\n");
        }
    }
}