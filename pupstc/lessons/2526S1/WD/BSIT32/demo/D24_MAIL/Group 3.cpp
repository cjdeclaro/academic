// ====================== CONVERSION CALCULATOR PROJECT ======================
// Group Number: 3
// BSIT 2-1
// Group Members: Mark Justin Tria, Carl Anthony Pena, 
// Chaste Anthony Lomibao, Seito Tachibana, Denzel Domino 


#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// =========== PART 1: ALL CONSTANTS ===========
// Metric to Imperial conversion factors
const double MM_TO_INCH = 0.03937;      // Millimeter to Inch
const double M_TO_FEET = 3.28084;       // Meter to Feet
const double KG_TO_POUND = 2.20462;     // Kilogram to Pound
const double L_TO_GALLON = 0.264172;    // Liter to Gallon
const double KM_TO_MILE = 0.6214;       // Kilometer to Mile

// Imperial to Metric conversion factors  
const double INCH_TO_MM = 25.4;         // Inch to Millimeter
const double FEET_TO_M = 0.3048;        // Feet to Meter
const double POUND_TO_KG = 0.453592;    // Pound to Kilogram
const double GALLON_TO_L = 3.78541;     // Gallon to Liter
const double MILE_TO_KM = 1.60934;      // Mile to Kilometer

// ANSI color codes
const string BOLD = "\033[1m";
const string RESET = "\033[0m";
const string UNDERLINE = "\033[4m";

// =========== PART 2: SINGLE CONVERSION FUNCTION ===========
double multiplyConvert(double value, double factor) { //Global since multiplication process lang lahat
    return value * factor;
}

// =========== PART 3: MAIN CLASS ===========
class Measurements {
public:
    string name;
    
    // Error Handling Function for Menu Function
    int getValidatedInt(int min, int max, const string &errorMessage) {
        int value;
        cin >> value;
    
        while (cin.fail() || value < min || value > max) {
            cout << errorMessage;
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> value;
        }
        return value;
    }
    
    //Menu Related funtions
    int showConversionMode() {
        cout << BOLD << "=== CONVERSION DIRECTION ===" << RESET << endl;
        cout << "1. Metric to Imperial" << endl;
        cout << "2. Imperial to Metric" << endl;
        cout << "Enter your choice: ";
        int choice = getValidatedInt(1, 2, "Invalid! Please enter 1 or 2: ");
        cout << "============================\n" << endl;
        return choice;
    }
    
    int showMetricMenu() {
        cout << BOLD << "=== METRIC TO IMPERIAL ===" << RESET << endl;
        cout << "0. Exit" << endl;
        cout << "1. Millimeter to Inch" << endl;
        cout << "2. Meter to Feet" << endl;
        cout << "3. Kilogram to Pound" << endl;
        cout << "4. Liter to Gallon" << endl;
        cout << "5. Kilometer to Mile" << endl;
        cout << "Enter your choice: ";
        int choice = getValidatedInt(0, 5, "Invalid! Please choose 0-5: ");
        cout << "============================\n" << endl;
        return choice;
    }
    
    int showImperialToMetricMenu() {
        cout << BOLD << "=== IMPERIAL TO METRIC ===" << RESET << endl;
        cout << "0. Exit" << endl;
        cout << "1. Inch to Millimeter" << endl;
        cout << "2. Feet to Meter" << endl;
        cout << "3. Pound to Kilogram" << endl;
        cout << "4. Gallon to Liter" << endl;
        cout << "5. Mile to Kilometer" << endl;
        cout << "Enter your choice: ";
        int choice = getValidatedInt(0, 5, "Invalid! Please choose 0-5: ");
        cout << "============================\n" << endl;
        return choice;
    }

    // =========== PART 4: INPUT FUNCTIONS ===========
    //INPUT FUNCTION 1
    double getInput(const string &prompt) { //To print and get input for each
        double value;
        cout << prompt;
        cin >> value;

        while (cin.fail() || value < 0) {
            cout << "Invalid! Please enter a positive number: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> value;
        }
        return value;
    }

    // =========== PART 5: DISPLAY FUNCTION ===========
    void displayResult(double input, double output,
                       const string &fromUnit,
                       const string &toUnit) {
        cout << UNDERLINE <<"You converted " << input << " " << fromUnit
             << " to " << output << " " << toUnit << RESET << endl;
    }

    //GREETING FUNCTION
    void greet() {
        cout << "\nHello " << name << "! Welcome to our Imperial and Metric Unit Converter.\n\n";
    }
    //CONTINUE FUNCTION
    bool askToContinue() {
        string choice;
    
        while (true) {
            cout << "\nConvert again? (Yes/No): ";
            cin >> choice;
            
            // para hindi sya case sensitive
            for (char &c : choice) {
                c = tolower(c);
            }
    
            if (choice == "yes") {
                return true;
            }
            else if (choice == "no") {
                return false;
            }
            else {
                cout << "Invalid input! Please enter Yes or No only.\n";
            }
        }
    }
   
    //CONVERSION LOGIC 1
    void runMetricToImperial() {
        int choice = showMetricMenu();
        
        if (choice == 0) return;
        
        double inputValue;
        string fromUnit, toUnit;
        double result = 0;
        
        switch (choice) {
            case 1: 
                inputValue = getInput("Enter millimeters: ");
                fromUnit = "mm"; toUnit = "inches";
                result = multiplyConvert(inputValue, MM_TO_INCH);
                break;
            case 2:
                inputValue = getInput("Enter meters: ");
                fromUnit = "m"; toUnit = "feet";
                result = multiplyConvert(inputValue, M_TO_FEET);
                break;
            case 3:
                inputValue = getInput("Enter kilograms: ");
                fromUnit = "kg"; toUnit = "pounds";
                result = multiplyConvert(inputValue, KG_TO_POUND);
                break;
            case 4:
                inputValue = getInput("Enter liters: ");
                fromUnit = "L"; toUnit = "gallons";
                result = multiplyConvert(inputValue, L_TO_GALLON);
                break;
            case 5:
                inputValue = getInput("Enter kilometers: ");
                fromUnit = "km"; toUnit = "miles";
                result = multiplyConvert(inputValue, KM_TO_MILE);
                break;
        }
        
        displayResult(inputValue, result, fromUnit, toUnit);
    }

    //CONVERSION LOGIC 2
    void runImperialToMetric() {
        int choice = showImperialToMetricMenu();
        
        if (choice == 0) return;
        
        double inputValue; //input function
        string fromUnit, toUnit;
        double result = 0;
        
        switch (choice) {
            case 1:
                inputValue = getInput("Enter inches: ");
                fromUnit = "inches"; toUnit = "mm";
                result = multiplyConvert(inputValue, INCH_TO_MM);
                break;
            case 2:
                inputValue = getInput("Enter feet: ");
                fromUnit = "feet"; toUnit = "m";
                result = multiplyConvert(inputValue, FEET_TO_M);
                break;
            case 3:
                inputValue = getInput("Enter pounds: ");
                fromUnit = "pounds"; toUnit = "kg";
                result = multiplyConvert(inputValue, POUND_TO_KG);
                break;
            case 4:
                inputValue = getInput("Enter gallons: ");
                fromUnit = "gallons"; toUnit = "L";
                result = multiplyConvert(inputValue, GALLON_TO_L);
                break;
            case 5:
                inputValue = getInput("Enter miles: ");
                fromUnit = "miles"; toUnit = "km";
                result = multiplyConvert(inputValue, MILE_TO_KM);
                break;
        }
        
        displayResult(inputValue, result, fromUnit, toUnit);
    }
};

// =========== PART 6: MAIN FUNCTION ===========
int main() {
    Measurements user;
    bool continueProgram = true;

    cout << "Please enter your name: ";
    cin >> user.name;
    user.greet();

    while (continueProgram) {
        int mode = user.showConversionMode();
        
        if (mode == 1) {
            user.runMetricToImperial();
        } else {
            user.runImperialToMetric();
        }
        
        continueProgram = user.askToContinue();
    }
    
    cout << "Thank you for using our Imperial and Metric Unit Converter, " << user.name << "!" << endl;
    return 0;
}