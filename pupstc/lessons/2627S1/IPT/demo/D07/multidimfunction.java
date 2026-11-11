class Main {
    static String getFullName(String fname, String lname) {
        return fname + " " + lname;
    }
    
    public static void main(String[] args) {
        String[][] people = {
            {"John", "Doe", "Tanauan"},
            {"Jane", "Air", "Calamba"},
            {"Bill", "Gates", "Sto Tomas"},
            {"Steve", "Jobs", "Lipa"},
            {"Ada", "Lovelace", "San Pedro"}
        };
        
        System.out.println("PEOPLE DATABASE\n");
    
        for(int i = 0; i < people.length; i++){
            System.out.println("Full Name: " + getFullName(people[i][0],people[i][1]));
            System.out.println("Address: " + people[i][2]);
            System.out.println("\n");
        }
    }
}