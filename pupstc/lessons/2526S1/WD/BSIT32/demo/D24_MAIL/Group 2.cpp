#include <iostream>
using namespace std;

class MeasurementsSystem {
public:
    // length: l
    double metersToFeet(double v) { return v * 3.28084; } // meters to feet
    double feetToMeters(double v) { return v / 3.28084; } // feet to meters
    double cmToInches(double v) { return v / 2.54; } // centimeters to inches
    double inchesToCm(double v) { return v * 2.54; } // inches to centimeters

    // weight: w
    double kgToLbs(double v) { return v * 2.20462; } // kilograms to pounds
    double lbsToKg(double v) { return v / 2.20462; } // pounds to kilograms
    double gramsToKg(double v) { return v / 1000; } // grams to kilograms
    double kgToGrams(double v) { return v * 1000; } // kilograms to grams

    // temperature: tp
    double cToF(double v) { return (v * 9.0 / 5.0) + 32; } // celsius to fahrenheit
    double fToC(double v) { return (v - 32) * 5.0 / 9.0; } // fahrenheit to celsius

    // time: tm
    double secondsToMinutes(double v) { return v / 60; } // seconds to minutes
    double minutesToSeconds(double v) { return v * 60; } // minutes to seconds
    double minutesToHours(double v) { return v / 60; } // minutes to hours
    double hoursToMinutes(double v) { return v * 60; } // hours to minutes

    // volume: v
    double mlToLiters(double v) { return v / 1000; } // milliliters to liters
    double litersToMl(double v) { return v * 1000; } // liters to milliliters
    double litersToGallons(double v) { return v * 0.264172; } // liters to gallons
    double gallonsToLiters(double v) { return v / 0.264172; } // gallons to liters

    // pressure: p
    double atmToKpa(double v) { return v * 101.325; } // atm to kpa
    double kpaToAtm(double v) { return v / 101.325; } // kpa to atm
    double psiToBar(double v) { return v * 0.0689476; } // psi to bar
    double barToPsi(double v) { return v / 0.0689476; } // bar to psi

    // speed: s
    double kmhToMs(double v) { return v / 3.6; } // km/h to m/s
    double msToKmh(double v) { return v * 3.6; } // m/s to km/h
    double msToFts(double v) { return v * 3.28084; } // m/s to ft/s
    double ftsToMs(double v) { return v / 3.28084; } // ft/s to m/s

    // storage unit: su
    double bytesToKb(double v) { return v / 1000; } // bytes to kb
    double kbToBytes(double v) { return v * 1000; } // kb to bytes
    double mbToGb(double v) { return v / 1000; } // mb to gb
    double gbToMb(double v) { return v * 1000; } // gb to mb

    // internet speed: is
    double mbpsToMbs(double v) { return v / 8; } // mbps to mb/s
    double mbsToMbps(double v) { return v * 8; } // mb/s to mbps

    // download time: dt
    double downloadTime(double sizeMB, double speedMbs) { return sizeMB / speedMbs; } // file size (mb) / internet speed (mb/s)
};

void printSeparator() {
    cout << "-------------------------------------------------\n";
}

bool getValidInt(int &value) {
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        return false;
    }
    return true;
}

bool getValidDouble(double &value) {
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        return false;
    }
    return true;
}

int postConversionMenu() {
    int userChoice;
    while (true) {
        printSeparator();
        cout << "Do you want to:\n[1] Convert another value\n[2] Change conversion type\n[0] Back to Main Menu\n";
        printSeparator();
        cout << "Enter your choice: ";

        if (!getValidInt(userChoice)) {
            cout << "\nInvalid input! Please enter a numeric value.\n";
            continue;
        }

        if (userChoice < 0 || userChoice > 2) {
            cout << "\nInvalid input! Please enter a number from 0 to 2.\n";
            continue;
        }
        break;
    }
    return userChoice;
}

void lengthConversionMenu() {
    MeasurementsSystem l;
    int subChoice;

    while (true) {
        cout << "\n--------------- LENGTH CONVERSION ---------------\n";
        cout << "[1] Meters to Feet\n[2] Feet to Meters\n";
        cout << "[3] Centimeters to Inches\n[4] Inches to Centimeters\n";
        cout << "[0] Back to Main Menu\n";
        printSeparator();

        while (true) {
            cout << "Enter your choice: ";
            if (!getValidInt(subChoice)) {
                cout << "\nInvalid input! Please enter a numeric value.\n";
                printSeparator();
                continue;
            }
            if (subChoice < 0 || subChoice > 4) {
                cout << "\nInvalid input! Please enter a number from 0 to 4.\n";
                printSeparator();
                continue;
            }
            break;
        }

        if (subChoice == 0) break;

        string selectedConversion;
        switch (subChoice) {
            case 1: selectedConversion = "Meters to Feet"; break;
            case 2: selectedConversion = "Feet to Meters"; break;
            case 3: selectedConversion = "Centimeters to Inches"; break;
            case 4: selectedConversion = "Inches to Centimeters"; break;
        }

        while (true) {
            double value;
            while (true) {
                cout << "\nSelected: " << selectedConversion << "\n";
                cout << "Enter value: ";
                if (!getValidDouble(value)) {
                    cout << "\nInvalid input! Please enter a numeric value.\n";
                    printSeparator();
                    continue;
                }
                if (value < 0) {
                    cout << "\nInvalid input! Value cannot be negative.\n";
                    printSeparator();
                    continue;
                }
                break;
            }

            if (subChoice == 1) cout << "Result: " << value << " m = " << l.metersToFeet(value) << " ft\n";
            else if (subChoice == 2) cout << "Result: " << value << " ft = " << l.feetToMeters(value) << " m\n";
            else if (subChoice == 3) cout << "Result: " << value << " cm = " << l.cmToInches(value) << " in\n";
            else if (subChoice == 4) cout << "Result: " << value << " in = " << l.inchesToCm(value) << " cm\n";

            int postChoice = postConversionMenu();
            if (postChoice == 1) continue; // convert another value
            if (postChoice == 2) break; // change conversion type
            if (postChoice == 0) return; // back to main menu
        }
    }
}

void weightConversionMenu() {
    MeasurementsSystem w;
    int subChoice;

    while (true) {
        cout << "\n--------------- WEIGHT CONVERSION ---------------\n";
        cout << "[1] Kilograms to Pounds\n[2] Pounds to Kilograms\n";
        cout << "[3] Grams to Kilograms\n[4] Kilograms to Grams\n";
        cout << "[0] Back to Main Menu\n";
        printSeparator();

        while (true) {
            cout << "Enter your choice: ";
            if (!getValidInt(subChoice)) {
                cout << "\nInvalid input! Please enter a numeric value.\n";
                printSeparator();
                continue;
            }
            if (subChoice < 0 || subChoice > 4) {
                cout << "\nInvalid input! Please enter a number from 0 to 4.\n";
                printSeparator();
                continue;
            }
            break;
        }

        if (subChoice == 0) break;

        string selectedConversion;
        switch (subChoice) {
            case 1: selectedConversion = "Kilograms to Pounds"; break;
            case 2: selectedConversion = "Pounds to Kilograms"; break;
            case 3: selectedConversion = "Grams to Kilograms"; break;
            case 4: selectedConversion = "Kilograms to Grams"; break;
        }

        while (true) {
            double value;
            while (true) {
                cout << "\nSelected: " << selectedConversion << "\n";
                cout << "Enter value: ";
                if (!getValidDouble(value)) {
                    cout << "\nInvalid input! Please enter a numeric value.\n";
                    printSeparator();
                    continue;
                }
                if (value < 0) {
                    cout << "\nInvalid input! Value cannot be negative.\n";
                    printSeparator();
                    continue;
                }
                break;
            }

            if (subChoice == 1) cout << "Result: " << value << " kg = " << w.kgToLbs(value) << " lb\n";
            else if (subChoice == 2) cout << "Result: " << value << " lb = " << w.lbsToKg(value) << " kg\n";
            else if (subChoice == 3) cout << "Result: " << value << " g = " << w.gramsToKg(value) << " kg\n";
            else if (subChoice == 4) cout << "Result: " << value << " kg = " << w.kgToGrams(value) << " g\n";

            int postChoice = postConversionMenu();
            if (postChoice == 1) continue; // convert another value
            if (postChoice == 2) break; // change conversion type
            if (postChoice == 0) return; // back to main menu
        }
    }
}

void temperatureConversionMenu() {
    MeasurementsSystem tp;
    int subChoice;

    while (true) {
        cout << "\n------------ TEMPERATURE CONVERSION -------------\n";
        cout << "[1] Celsius to Fahrenheit\n[2] Fahrenheit to Celsius\n";
        cout << "[0] Back to Main Menu\n";
        printSeparator();

        while (true) {
            cout << "Enter your choice: ";
            if (!getValidInt(subChoice)) {
                cout << "\nInvalid input! Please enter a numeric value.\n";
                printSeparator();
                continue;
            }
            if (subChoice < 0 || subChoice > 2) {
                cout << "\nInvalid input! Please enter a number from 0 to 2.\n";
                printSeparator();
                continue;
            }
            break;
        }

        if (subChoice == 0) break;

        string selectedConversion;
        switch (subChoice) {
            case 1: selectedConversion = "Celsius to Fahrenheit"; break;
            case 2: selectedConversion = "Fahrenheit to Celsius"; break;
        }

        while (true) {
            double value;
            while (true) {
                cout << "\nSelected: " << selectedConversion << "\n";
                cout << "Enter value: ";
                if (!getValidDouble(value)) {
                    cout << "\nInvalid input! Please enter a numeric value.\n";
                    printSeparator();
                    continue;
                }
                break;
            }

            if (subChoice == 1) cout << "Result: " << value << " °C = " << tp.cToF(value) << " °F\n";
            else if (subChoice == 2) cout << "Result: " << value << " °F = " << tp.fToC(value) << " °C\n";

            int postChoice = postConversionMenu();
            if (postChoice == 1) continue; // convert another value
            if (postChoice == 2) break; // change conversion type
            if (postChoice == 0) return; // back to main menu
        }
    }
}

void timeConversionMenu() {
    MeasurementsSystem tm;
    int subChoice;

    while (true) {
        cout << "\n---------------- TIME CONVERSION ----------------\n";
        cout << "[1] Seconds to Minutes\n[2] Minutes to Seconds\n";
        cout << "[3] Minutes to Hours\n[4] Hours to Minutes\n";
        cout << "[0] Back to Main Menu\n";
        printSeparator();

        while (true) {
            cout << "Enter your choice: ";
            if (!getValidInt(subChoice)) {
                cout << "\nInvalid input! Please enter a numeric value.\n";
                printSeparator();
                continue;
            }
            if (subChoice < 0 || subChoice > 4) {
                cout << "\nInvalid input! Please enter a number from 0 to 4.\n";
                printSeparator();
                continue;
            }
            break;
        }

        if (subChoice == 0) break;

        string selectedConversion;
        switch (subChoice) {
            case 1: selectedConversion = "Seconds to Minutes"; break;
            case 2: selectedConversion = "Minutes to Seconds"; break;
            case 3: selectedConversion = "Minutes to Hours"; break;
            case 4: selectedConversion = "Hours to Minutes"; break;
        }

        while (true) {
            double value;
            while (true) {
                cout << "\nSelected: " << selectedConversion << "\n";
                cout << "Enter value: ";
                if (!getValidDouble(value)) {
                    cout << "\nInvalid input! Please enter a numeric value.\n";
                    printSeparator();
                    continue;
                }
                if (value < 0) {
                    cout << "\nInvalid input! Value cannot be negative.\n";
                    printSeparator();
                    continue;
                }
                break;
            }

            if (subChoice == 1) cout << "Result: " << value << " s = " << tm.secondsToMinutes(value) << " min\n";
            else if (subChoice == 2) cout << "Result: " << value << " min = " << tm.minutesToSeconds(value) << " s\n";
            else if (subChoice == 3) cout << "Result: " << value << " min = " << tm.minutesToHours(value) << " h\n";
            else if (subChoice == 4) cout << "Result: " << value << " h = " << tm.hoursToMinutes(value) << " min\n";

            int postChoice = postConversionMenu();
            if (postChoice == 1) continue; // convert another value
            if (postChoice == 2) break; // change conversion type
            if (postChoice == 0) return; // back to main menu
        }
    }
}

void volumeConversionMenu() {
    MeasurementsSystem v;
    int subChoice;

    while (true) {
        cout << "\n--------------- VOLUME CONVERSION ---------------\n";
        cout << "[1] Milliliters to Liters\n[2] Liters to Milliliters\n";
        cout << "[3] Liters to Gallons\n[4] Gallons to Liters\n";
        cout << "[0] Back to Main Menu\n";
        printSeparator();

        while (true) {
            cout << "Enter your choice: ";
            if (!getValidInt(subChoice)) {
                cout << "\nInvalid input! Please enter a numeric value.\n";
                printSeparator();
                continue;
            }
            if (subChoice < 0 || subChoice > 4) {
                cout << "\nInvalid input! Please enter a number from 0 to 4.\n";
                printSeparator();
                continue;
            }
            break;
        }

        if (subChoice == 0) break;

        string selectedConversion;
        switch (subChoice) {
            case 1: selectedConversion = "Milliliters to Liters"; break;
            case 2: selectedConversion = "Liters to Milliliters"; break;
            case 3: selectedConversion = "Liters to Gallons"; break;
            case 4: selectedConversion = "Gallons to Liters"; break;
        }

        while (true) {
            double value;
            while (true) {
                cout << "\nSelected: " << selectedConversion << "\n";
                cout << "Enter value: ";
                if (!getValidDouble(value)) {
                    cout << "\nInvalid input! Please enter a numeric value.\n";
                    printSeparator();
                    continue;
                }
                if (value < 0) {
                    cout << "\nInvalid input! Value cannot be negative.\n";
                    printSeparator();
                    continue;
                }
                break;
            }

            if (subChoice == 1) cout << "Result: " << value << " mL = " << v.mlToLiters(value) << " L\n";
            else if (subChoice == 2) cout << "Result: " << value << " L = " << v.litersToMl(value) << " mL\n";
            else if (subChoice == 3) cout << "Result: " << value << " L = " << v.litersToGallons(value) << " gal\n";
            else if (subChoice == 4) cout << "Result: " << value << " gal = " << v.gallonsToLiters(value) << " L\n";

            int postChoice = postConversionMenu();
            if (postChoice == 1) continue; // convert another value
            if (postChoice == 2) break; // change conversion type
            if (postChoice == 0) return; // back to main menu
        }
    }
}

void pressureConversionMenu() {
    MeasurementsSystem p;
    int subChoice;

    while (true) {
        cout << "\n-------------- PRESSURE CONVERSION --------------\n";
        cout << "[1] atm to kPa\n[2] kPa to atm\n";
        cout << "[3] psi to bar\n[4] bar to psi\n";
        cout << "[0] Back to Main Menu\n";
        printSeparator();

        while (true) {
            cout << "Enter your choice: ";
            if (!getValidInt(subChoice)) {
                cout << "\nInvalid input! Please enter a numeric value.\n";
                printSeparator();
                continue;
            }
            if (subChoice < 0 || subChoice > 4) {
                cout << "\nInvalid input! Please enter a number from 0 to 4.\n";
                printSeparator();
                continue;
            }
            break;
        }

        if (subChoice == 0) break;

        string selectedConversion;
        switch (subChoice) {
            case 1: selectedConversion = "atm to kPa"; break;
            case 2: selectedConversion = "kPa to atm"; break;
            case 3: selectedConversion = "psi to bar"; break;
            case 4: selectedConversion = "bar to psi"; break;
        }

        while (true) {
            double value;
            while (true) {
                cout << "\nSelected: " << selectedConversion << "\n";
                cout << "Enter value: ";
                if (!getValidDouble(value)) {
                    cout << "\nInvalid input! Please enter a numeric value.\n";
                    printSeparator();
                    continue;
                }
                if (value < 0) {
                    cout << "\nInvalid input! Value cannot be negative.\n";
                    printSeparator();
                    continue;
                }
                break;
            }

            if (subChoice == 1) cout << "Result: " << value << " atm = " << p.atmToKpa(value) << " kPa\n";
            else if (subChoice == 2) cout << "Result: " << value << " kPa = " << p.kpaToAtm(value) << " atm\n";
            else if (subChoice == 3) cout << "Result: " << value << " psi = " << p.psiToBar(value) << " bar\n";
            else if (subChoice == 4) cout << "Result: " << value << " bar = " << p.barToPsi(value) << " psi\n";

            int postChoice = postConversionMenu();
            if (postChoice == 1) continue; // convert another value
            if (postChoice == 2) break; // change conversion type
            if (postChoice == 0) return; // back to main menu
        }
    }
}

void speedConversionMenu() {
    MeasurementsSystem s;
    int subChoice;

    while (true) {
        cout << "\n--------------- SPEED CONVERSION ----------------\n";
        cout << "[1] km/h to m/s\n[2] m/s to km/h\n";
        cout << "[3] m/s to ft/s\n[4] ft/s to m/s\n";
        cout << "[0] Back to Main Menu\n";
        printSeparator();

        while (true) {
            cout << "Enter your choice: ";
            if (!getValidInt(subChoice)) {
                cout << "\nInvalid input! Please enter a numeric value.\n";
                printSeparator();
                continue;
            }
            if (subChoice < 0 || subChoice > 4) {
                cout << "\nInvalid input! Please enter a number from 0 to 4.\n";
                printSeparator();
                continue;
            }
            break;
        }

        if (subChoice == 0) break;

        string selectedConversion;
        switch (subChoice) {
            case 1: selectedConversion = "km/h to m/s"; break;
            case 2: selectedConversion = "m/s to km/h"; break;
            case 3: selectedConversion = "m/s to ft/s"; break;
            case 4: selectedConversion = "ft/s to m/s"; break;
        }

        while (true) {
            double value;
            while (true) {
                cout << "\nSelected: " << selectedConversion << "\n";
                cout << "Enter value: ";
                if (!getValidDouble(value)) {
                    cout << "\nInvalid input! Please enter a numeric value.\n";
                    printSeparator();
                    continue;
                }
                if (value < 0) {
                    cout << "\nInvalid input! Value cannot be negative.\n";
                    printSeparator();
                    continue;
                }
                break;
            }

            if (subChoice == 1) cout << "Result: " << value << " km/h = " << s.kmhToMs(value) << " m/s\n";
            else if (subChoice == 2) cout << "Result: " << value << " m/s = " << s.msToKmh(value) << " km/h\n";
            else if (subChoice == 3) cout << "Result: " << value << " m/s = " << s.msToFts(value) << " ft/s\n";
            else if (subChoice == 4) cout << "Result: " << value << " ft/s = " << s.ftsToMs(value) << " m/s\n";

            int postChoice = postConversionMenu();
            if (postChoice == 1) continue; // convert another value
            if (postChoice == 2) break; // change conversion type
            if (postChoice == 0) return; // back to main menu
        }
    }
}

void storageConversionMenu() {
    MeasurementsSystem su;
    int subChoice;

    while (true) {
        cout << "\n------------ STORAGE UNIT CONVERSION ------------\n";
        cout << "[1] Bytes to KB\n[2] KB to Bytes\n";
        cout << "[3] MB to GB\n[4] GB to MB\n";
        cout << "[0] Back to Main Menu\n";
        printSeparator();

        while (true) {
            cout << "Enter your choice: ";
            if (!getValidInt(subChoice)) {
                cout << "\nInvalid input! Please enter a numeric value.\n";
                printSeparator();
                continue;
            }
            if (subChoice < 0 || subChoice > 4) {
                cout << "\nInvalid input! Please enter a number from 0 to 4.\n";
                printSeparator();
                continue;
            }
            break;
        }

        if (subChoice == 0) break;

        string selectedConversion;
        switch (subChoice) {
            case 1: selectedConversion = "Bytes to KB"; break;
            case 2: selectedConversion = "KB to Bytes"; break;
            case 3: selectedConversion = "MB to GB"; break;
            case 4: selectedConversion = "GB to MB"; break;
        }

        while (true) {
            double value;
            while (true) {
                cout << "\nSelected: " << selectedConversion << "\n";
                cout << "Enter value: ";
                if (!getValidDouble(value)) {
                    cout << "\nInvalid input! Please enter a numeric value.\n";
                    printSeparator();
                    continue;
                }
                if (value < 0) {
                    cout << "\nInvalid input! Value cannot be negative.\n";
                    printSeparator();
                    continue;
                }
                break;
            }

            if (subChoice == 1) cout << "Result: " << value << " B = " << su.bytesToKb(value) << " KB\n";
            else if (subChoice == 2) cout << "Result: " << value << " KB = " << su.kbToBytes(value) << " B\n";
            else if (subChoice == 3) cout << "Result: " << value << " MB = " << su.mbToGb(value) << " GB\n";
            else if (subChoice == 4) cout << "Result: " << value << " GB = " << su.gbToMb(value) << " MB\n";

            int postChoice = postConversionMenu();
            if (postChoice == 1) continue; // convert another value
            if (postChoice == 2) break; // change conversion type
            if (postChoice == 0) return; // back to main menu
        }
    }
}

void internetSpeedConversionMenu() {
    MeasurementsSystem is;
    int subChoice;

    while (true) {
        cout << "\n----------- INTERNET SPEED CONVERSION -----------\n";
        cout << "[1] Mbps to MB/s\n[2] MB/s to Mbps\n";
        cout << "[0] Back to Main Menu\n";
        printSeparator();

        while (true) {
            cout << "Enter your choice: ";
            if (!getValidInt(subChoice)) {
                cout << "\nInvalid input! Please enter a numeric value.\n";
                printSeparator();
                continue;
            }
            if (subChoice < 0 || subChoice > 2) {
                cout << "\nInvalid input! Please enter a number from 0 to 2.\n";
                printSeparator();
                continue;
            }
            break;
        }

        if (subChoice == 0) break;

        string selectedConversion;
        switch (subChoice) {
            case 1: selectedConversion = "Mbps to MB/s"; break;
            case 2: selectedConversion = "MB/s to Mbps"; break;
        }

        while (true) {
            double value;
            while (true) {
                cout << "\nSelected: " << selectedConversion << "\n";
                cout << "Enter value: ";
                if (!getValidDouble(value)) {
                    cout << "\nInvalid input! Please enter a numeric value.\n";
                    printSeparator();
                    continue;
                }
                if (value < 0) {
                    cout << "\nInvalid input! Value cannot be negative.\n";
                    printSeparator();
                    continue;
                }
                break;
            }
            
            if (subChoice == 1) cout << "Result: " << value << " Mbps = " << is.mbpsToMbs(value) << " MB/s\n";
            else if (subChoice == 2) cout << "Result: " << value << " MB/s = " << is.mbsToMbps(value) << " Mbps\n";

            int postChoice = postConversionMenu();
            if (postChoice == 1) continue; // convert another value
            if (postChoice == 2) break; // change conversion type
            if (postChoice == 0) return; // back to main menu
        }
    }
}

void downloadTimeConversionMenu() {
    MeasurementsSystem dt;

    while (true) {
        cout << "\n----------- DOWNLOAD TIME CONVERSION ------------\n";

        double size, speed;

        while (true) {
            cout << "Enter file size in MB: ";
            if (!getValidDouble(size)) {
                cout << "\nInvalid input! Please enter a numeric value.\n";
                printSeparator();
                continue;
            }
            if (size <= 0) {
                cout << "\nInvalid input! File size must be greater than 0.\n";
                printSeparator();
                continue;
            }
            break;
        }

        while (true) {
            cout << "Enter download speed in MB/s: ";
            if (!getValidDouble(speed)) {
                cout << "\nInvalid input! Please enter a numeric value.\n";
                printSeparator();
                continue;
            }
            if (speed <= 0) {
                cout << "\nInvalid input! Speed must be greater than 0.\n";
                printSeparator();
                continue;
            }
            break;
        }

        double result = dt.downloadTime(size, speed);
        cout << "Result: Estimated download time = " << result << " seconds\n";

        int postChoice;
        while (true) {
            printSeparator();
            cout << "Do you want to:\n[1] Convert another value\n[0] Back to Main Menu\n";
            printSeparator();
            cout << "Enter your choice: ";

            if (!getValidInt(postChoice)) {
                cout << "\nInvalid input! Please enter a numeric value.\n";
                continue;
            }

            if (postChoice < 0 || postChoice > 1) {
                cout << "\nInvalid input! Please enter 0 or 1.\n";
                continue;
            }
            break;
        }

        if (postChoice == 1) continue; // convert another value
        else if (postChoice == 0) break; // back to main menu
    }
}

int main() {
    cout << "Welcome to \"Measurement Conversion System\"!\n";
    cout << "A reliable tool for precise unit conversions.\n";

    while (true) {
        int mainChoice;

        cout << "\n=================== MAIN MENU ===================\n";
        cout << "[1] Length Conversion\n[2] Weight Conversion\n[3] Temperature Conversion\n";
        cout << "[4] Time Conversion\n[5] Volume Conversion\n[6] Pressure Conversion\n";
        cout << "[7] Speed Conversion\n[8] Storage Unit Conversion\n[9] Internet Speed Conversion\n";
        cout << "[10] Download Time Conversion\n[0] Exit\n";
        printSeparator();

        while (true) {
            cout << "Enter your choice: ";
            if (!getValidInt(mainChoice)) {
                cout << "\nInvalid input! Please enter a numeric value.\n";
                printSeparator();
                continue;
            }

            if (mainChoice < 0 || mainChoice > 10) {
                cout << "\nInvalid input! Please enter a number from 0 to 10.\n";
                printSeparator();
                continue;
            }
            break;
        }

        if (mainChoice == 0) {
            cout << "\nProgram terminated. Thank you.\n";
            break;
        }
        else if (mainChoice == 1) lengthConversionMenu();
        else if (mainChoice == 2) weightConversionMenu();
        else if (mainChoice == 3) temperatureConversionMenu();
        else if (mainChoice == 4) timeConversionMenu();
        else if (mainChoice == 5) volumeConversionMenu();
        else if (mainChoice == 6) pressureConversionMenu();
        else if (mainChoice == 7) speedConversionMenu();
        else if (mainChoice == 8) storageConversionMenu();
        else if (mainChoice == 9) internetSpeedConversionMenu();
        else if (mainChoice == 10) downloadTimeConversionMenu();
    }

    return 0;
}