#include <iostream>
#include <string>
using namespace std;

// --- CLASSES ---
class Length {
public:
    double meterToKilometer(double m) { return m / 1000; }
    double kilometerToMeter(double km) { return km * 1000; }
    double cmToInches(double cm) { return cm / 2.54; }
    double inchesToCm(double in) { return in * 2.54; }
};

class Temperature {
public:
    double celsiusToFahrenheit(double c) { return (c * 9.0 / 5) + 32; }
    double fahrenheitToCelsius(double f) { return (f - 32) * 5.0 / 9; }
};

class Weight {
public:
    double kgToLbs(double kg) { return kg * 2.20462; }
    double lbsToKg(double lb) { return lb * 0.453592; }
};

class Volume {
public:
    double lToMl(double l) { return l * 1000; }
    double mlToL(double ml) { return ml / 1000; }
};

class Speed {
public:
    double calcSpeed(double d, double t) { return (t == 0) ? 0 : d / t; }
    double msToKmh(double ms) { return ms * 3.6; }
    double kmhToMs(double kmh) { return kmh / 3.6; }
};

// --- VALIDATION FUNCTION ---
double getVal(string label) {
    double input;
    while (true) {
        cout << "Enter " << label << ": ";
        if (cin >> input) {
            return input;
        } else {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input! Please enter a number.\n\n";
        }
    }
}

int main() {
    Length convertLength;
    Temperature convertTemperature;
    Weight convertWeight;
    Volume convertVolume;
    Speed convertSpeed;

    int choice;

    while (true) {
        cout << "\n--- MEASUREMENT CONVERSION ---\n";
        cout << "1. Meter to Kilometer\n2. Kilometer to Meter\n3. Centimeter to Inches\n4. Inches to Centimeter\n";
        cout << "5. Celsius to Fahrenheit\n6. Fahrenheit to Celsius\n7. Kilogram to Pounds\n8. Pounds to Kilogram\n";
        cout << "9. Liters to Milliliters\n10. Milliliters to Liters\n11. Speed Calculator\n12. Speed Unit Conversion\n";
        cout << "13. Exit\n";
        cout << "Enter your choice (1-13): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nError: Invalid Input!\n";
            continue;
        }

        if (choice == 13) return 0;

        int subChoice = 1;
        while (subChoice == 1) {
            cout << "\n";
            
            switch (choice) {
                case 1: {
                    double val = getVal("Meters");
                    cout << "Kilometers: " << convertLength.meterToKilometer(val) << " km\n\n";
                    break;
                }
                case 2: {
                    double val = getVal("Kilometers");
                    cout << "Meters: " << convertLength.kilometerToMeter(val) << " m\n\n";
                    break;
                }
                case 3: {
                    double val = getVal("Centimeters");
                    cout << "Inches: " << convertLength.cmToInches(val) << " in\n\n";
                    break;
                }
                case 4: {
                    double val = getVal("Inches");
                    cout << "Centimeters: " << convertLength.inchesToCm(val) << " cm\n\n";
                    break;
                }
                case 5: {
                    double val = getVal("Celsius");
                    cout << "Fahrenheit: " << convertTemperature.celsiusToFahrenheit(val) << " F\n\n";
                    break;
                }
                case 6: {
                    double val = getVal("Fahrenheit");
                    cout << "Celsius: " << convertTemperature.fahrenheitToCelsius(val) << " C\n\n";
                    break;
                }
                case 7: {
                    double val = getVal("Kilograms");
                    cout << "Pounds: " << convertWeight.kgToLbs(val) << " lbs\n\n";
                    break;
                }
                case 8: {
                    double val = getVal("Pounds");
                    cout << "Kilograms: " << convertWeight.lbsToKg(val) << " kg\n\n";
                    break;
                }
                case 9: {
                    double val = getVal("Liters");
                    cout << "Milliliters: " << convertVolume.lToMl(val) << " ml\n\n";
                    break;
                }
                case 10: {
                    double val = getVal("Milliliters");
                    cout << "Liters: " << convertVolume.mlToL(val) << " L\n\n";
                    break;
                }
                case 11: {
                    double d = getVal("Distance (in meters)"), t = getVal("Time (in seconds)");
                    cout << "Speed: " << convertSpeed.calcSpeed(d, t) << " m/s\n\n";
                    break;
                }
                case 12: {
                    int sChoice;
                    cout << "1. m/s -> km/h\n2. km/h -> m/s\nChoice: ";
                    cin >> sChoice;
                    double v = getVal("Value");
                    if (sChoice == 1)
                        cout << "Speed: " << convertSpeed.msToKmh(v) << " km/h\n\n";
                    else
                        cout << "Speed: " << convertSpeed.kmhToMs(v) << " m/s\n\n";
                    break;
                }
                default:
                    cout << "Invalid Choice!\n";
                    subChoice = 2;
                    break;
            }

            if (subChoice == 2) break;

            while (true) {
                cout << "1. Redo\n2. Main Menu\n3. Exit\nChoice: ";
                if (cin >> subChoice && (subChoice >= 1 && subChoice <= 3))
                    break;
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Error: Choose only 1, 2, or 3.\n\n";
            }
            if (subChoice == 2) break;
            if (subChoice == 3) return 0;
        }
    }
    return 0;
}

// Group Members
// Abella, Chrizyl
// Atinon, Jhody
// Ebora, Sebastian Luis
// Ilao, Jen Mae
// Magpayo, Shemaiah Ezra
// Tanglao, Wayne Saila