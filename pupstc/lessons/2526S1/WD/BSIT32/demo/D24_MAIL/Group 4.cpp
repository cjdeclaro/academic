#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <ctime>

static constexpr int MAX_PATIENTS = 100;
static constexpr int MAX_HISTORY = 50;

// ==========================================
// Utility helpers (no "using namespace std;")
// ==========================================
class InputHelper {
public:
    // Nicely format floating numbers, remove trailing zeros.
    static std::string formatNum(double value, int precision = 2) {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(precision) << value;
        std::string s = oss.str();

        // Trim trailing zeros and possibly the decimal point.
        if (s.find('.') != std::string::npos) {
            while (!s.empty() && s.back() == '0') s.pop_back();
            if (!s.empty() && s.back() == '.') s.pop_back();
        }
        return s;
    }

    static double getFloat(const std::string& prompt, double minVal) {
        double value;
        while (true) {
            std::cout << prompt;
            if (!(std::cin >> value)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a numeric value.\n";
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (value < minVal) {
                std::cout << "Value must be at least " << minVal << ". Please try again.\n";
                continue;
            }
            return value;
        }
    }

    static int getInt(const std::string& prompt, int minVal, int maxVal) {
        int value;
        while (true) {
            std::cout << prompt;
            if (!(std::cin >> value)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a whole number.\n";
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (value < minVal || value > maxVal) {
                std::cout << "Please enter a number between " << minVal << " and " << maxVal << ".\n";
                continue;
            }
            return value;
        }
    }

    static std::string trim(const std::string& s) {
        auto start = s.find_first_not_of(" \t\r\n");
        if (start == std::string::npos) return "";
        auto end = s.find_last_not_of(" \t\r\n");
        return s.substr(start, end - start + 1);
    }

    // Accept letters, spaces, hyphens and apostrophes for names.
    static std::string getName(const std::string& prompt) {
        std::string text;
        while (true) {
            std::cout << prompt;
            std::getline(std::cin, text);
            text = trim(text);
            if (text.empty()) {
                std::cout << "Name cannot be empty. Please try again.\n";
                continue;
            }
            bool valid = true;
            for (char c : text) {
                if (!std::isalpha(static_cast<unsigned char>(c)) &&
                    c != ' ' && c != '-' && c != '\'') {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                std::cout << "Name must contain only letters, spaces, hyphens, or apostrophes.\n";
                continue;
            }
            return text;
        }
    }

    static bool askToRepeat() {
        while (true) {
            std::cout << "\nWould you like to perform another calculation for this patient?\n";
            std::cout << "1 - Yes\n2 - No (return to previous menu)\nChoice: ";
            std::string input;
            std::getline(std::cin, input);
            if (input == "1") return true;
            if (input == "2") return false;
            std::cout << "Invalid selection. Please enter 1 or 2.\n";
        }
    }
};

// ==========================================
// Patient class
// ==========================================
class Patient {
private:
    int id_;
    std::string name_;
    int age_;
    std::string gender_;
    std::vector<std::string> history_;

    static std::string currentTimestamp() {
        auto now = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(now);
        char buf[64];
        if (std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&t))) {
            return std::string(buf);
        }
        return "unknown time";
    }

public:
    Patient() : id_(0), name_(""), age_(0), gender_("") {}

    void setID(int id) { id_ = id; }
    int getID() const { return id_; }

    void setInfo() {
        std::cout << "\n--- NEW PATIENT ENTRY ---\n";
        name_ = InputHelper::getName("Enter patient's full name: ");
        age_ = InputHelper::getInt("Enter patient's age: ", 0, 150);

        while (true) {
            std::cout << "Enter gender (male / female): ";
            std::string input;
            std::getline(std::cin, input);
            input = InputHelper::trim(input);
            std::transform(input.begin(), input.end(), input.begin(),
                           [](unsigned char c){ return std::tolower(c); });
            if (input == "male" || input == "female") {
                input[0] = static_cast<char>(std::toupper(input[0]));
                gender_ = input;
                break;
            }
            std::cout << "Invalid entry. Please enter 'male' or 'female'.\n";
        }

        std::cout << "\nAssigned Patient ID: " << id_ << "\n";
    }

    std::string getName() const { return name_; }
    int getAge() const { return age_; }
    std::string getGender() const { return gender_; }

    void addRecord(const std::string& text) {
        if (static_cast<int>(history_.size()) >= MAX_HISTORY) {
            std::cout << "Cannot save record: history capacity reached.\n";
            return;
        }
        std::string entry = "[" + currentTimestamp() + "] " + text;
        history_.push_back(entry);
        std::cout << "Record saved.\n";
    }

    void showHistory() const {
        std::cout << "\n========================================\n";
        std::cout << "          PATIENT RECORD (ID #" << id_ << ")\n";
        std::cout << "========================================\n";
        std::cout << "Name   : " << name_ << "\n";
        std::cout << "Age    : " << age_ << "\n";
        std::cout << "Gender : " << gender_ << "\n";
        std::cout << "----------------------------------------\n";

        if (history_.empty()) {
            std::cout << "No entries available for this patient.\n";
        } else {
            for (std::size_t i = 0; i < history_.size(); ++i) {
                std::cout << (i + 1) << ". " << history_[i] << "\n";
            }
        }
        std::cout << "========================================\n";
    }
};

// ==========================================
// Calculators
// ==========================================
class Calculators {
public:
    void cholesterol(Patient& p) {
        do {
            std::cout << "\n--- CHOLESTEROL CALCULATOR ---\n";
            std::cout << "1. Calculate Total Cholesterol\n";
            std::cout << "2. Calculate LDL\n";
            std::cout << "3. Calculate VLDL\n";
            std::cout << "4. Back\nChoice: ";
            int choice = InputHelper::getInt("", 1, 4);
            if (choice == 4) return;

            if (choice == 1) {
                double hdl = InputHelper::getFloat("Enter HDL (mg/dL): ", 0.0);
                double ldl = InputHelper::getFloat("Enter LDL (mg/dL): ", 0.0);
                double trig = InputHelper::getFloat("Enter Triglycerides (mg/dL): ", 0.0);
                double total = hdl + ldl + (trig / 5.0);
                std::string status = (total > 200.0) ? "High" : "Within expected range";
                std::cout << "Total Cholesterol: " << InputHelper::formatNum(total, 2)
                          << " mg/dL (" << status << ")\n";
                p.addRecord("Total Cholesterol: " + InputHelper::formatNum(total, 2)
                            + " mg/dL (" + status + ")");
            }
            else if (choice == 2) {
                double total = InputHelper::getFloat("Enter Total Cholesterol (mg/dL): ", 0.0);
                double hdl = InputHelper::getFloat("Enter HDL (mg/dL): ", 0.0);
                double trig = InputHelper::getFloat("Enter Triglycerides (mg/dL): ", 0.0);
                double ldl = total - hdl - (trig / 5.0);

                std::string status;
                if (p.getAge() >= 60) status = (ldl >= 70.0 && ldl <= 100.0) ? "Optimal (senior)" : "Above recommended (senior)";
                else if (p.getAge() < 18) status = (ldl < 110.0) ? "Optimal (youth)" : "Above recommended (youth)";
                else status = (ldl < 100.0) ? "Optimal (adult)" : "Above recommended (adult)";

                std::cout << "LDL: " << InputHelper::formatNum(ldl, 2)
                          << " mg/dL (" << status << ")\n";
                p.addRecord("LDL: " + InputHelper::formatNum(ldl, 2) + " mg/dL (" + status + ")");
            }
            else { // VLDL
                double trig = InputHelper::getFloat("Enter Triglycerides (mg/dL): ", 0.0);
                double vldl = trig / 5.0;
                std::cout << "VLDL: " << InputHelper::formatNum(vldl, 2) << " mg/dL\n";
                p.addRecord("VLDL: " + InputHelper::formatNum(vldl, 2) + " mg/dL");
            }

        } while (InputHelper::askToRepeat());
    }

    void bodyFat(Patient& p) {
        do {
            std::cout << "\n--- BODY FAT PERCENTAGE (FROM BMI) ---\n";
            double bmi = InputHelper::getFloat("Enter BMI: ", 0.1);
            double bfp = (1.20 * bmi) + (0.23 * p.getAge()) - (p.getGender() == "Male" ? 16.2 : 5.4);
            std::cout << "Estimated Body Fat: " << InputHelper::formatNum(bfp, 2) << " %\n";
            p.addRecord("Body Fat: " + InputHelper::formatNum(bfp, 2) + "% (calculated from BMI " + InputHelper::formatNum(bmi, 2) + ")");
        } while (InputHelper::askToRepeat());
    }

    void bloodSugar(Patient& p) {
        do {
            std::cout << "\n--- BLOOD GLUCOSE ---\n";
            double mg = InputHelper::getFloat("Enter blood glucose (mg/dL): ", 0.0);
            std::string status;
            if (mg < 70.0) status = "Hypoglycemia";
            else if (mg < 100.0) status = "Normal";
            else if (mg <= 125.0) status = "Prediabetes";
            else status = "Diabetes range";
            std::cout << InputHelper::formatNum(mg, 2) << " mg/dL (" << status << ")\n";
            p.addRecord("Blood Glucose: " + InputHelper::formatNum(mg, 2) + " mg/dL (" + status + ")");
        } while (InputHelper::askToRepeat());
    }

    void waistToHeight(Patient& p) {
        do {
            std::cout << "\n--- WAIST-TO-HEIGHT RATIO ---\n";
            double waist = InputHelper::getFloat("Waist circumference (cm): ", 0.1);
            double height = InputHelper::getFloat("Height (cm): ", 0.1);
            double ratio = waist / height;
            std::string status;
            if (ratio < 0.50) status = "Healthy";
            else if (ratio < 0.60) status = "Increased risk";
            else status = "High risk";
            std::cout << "Waist-to-Height ratio: " << InputHelper::formatNum(ratio, 2) << " (" << status << ")\n";
            p.addRecord("Waist-to-Height ratio: " + InputHelper::formatNum(ratio, 2) + " (" + status + ")");
        } while (InputHelper::askToRepeat());
    }

    void lipidProfile(Patient& p) {
        do {
            std::cout << "\n--- IDL LIPID ANALYSIS ---\n";
            double idl = InputHelper::getFloat("Enter IDL (mg/dL): ", 0.0);
            std::string status;
            if (idl < 20.0) status = "Normal";
            else if (idl < 30.0) status = "Borderline";
            else status = "Elevated";
            std::cout << "IDL: " << InputHelper::formatNum(idl, 2) << " mg/dL (" << status << ")\n";
            p.addRecord("IDL: " + InputHelper::formatNum(idl, 2) + " mg/dL (" + status + ")");
        } while (InputHelper::askToRepeat());
    }

    void bloodPressure(Patient& p) {
        do {
            std::cout << "\n--- BLOOD PRESSURE ---\n";
            int sys = InputHelper::getInt("Systolic (mm Hg): ", 0, 300);
            int dia = InputHelper::getInt("Diastolic (mm Hg): ", 0, 200);
            std::string status;
            if (sys > 180 || dia > 120) status = "Hypertensive crisis";
            else if (sys >= 140 || dia >= 90) status = "Stage 2 Hypertension";
            else if (sys >= 130 || dia >= 80) status = "Stage 1 Hypertension";
            else if (sys >= 120 && dia < 80) status = "Elevated";
            else status = "Normal";
            std::cout << "Blood Pressure: " << sys << "/" << dia << " mm Hg (" << status << ")\n";
            p.addRecord("Blood Pressure: " + std::to_string(sys) + "/" + std::to_string(dia) + " mm Hg (" + status + ")");
        } while (InputHelper::askToRepeat());
    }

    void bmiCalc(Patient& p) {
        do {
            std::cout << "\n--- BODY MASS INDEX (BMI) ---\n";
            double height_cm = InputHelper::getFloat("Height (cm): ", 0.1);
            double weight_kg = InputHelper::getFloat("Weight (kg): ", 0.1);
            double bmi = weight_kg / ((height_cm / 100.0) * (height_cm / 100.0));
            std::string status;
            if (bmi < 18.5) status = "Underweight";
            else if (bmi < 25.0) status = "Normal";
            else if (bmi < 30.0) status = "Overweight";
            else status = "Obese";
            std::cout << "BMI: " << InputHelper::formatNum(bmi, 1) << " (" << status << ")\n";
            p.addRecord("BMI: " + InputHelper::formatNum(bmi, 1) + " (" + status + ")");
        } while (InputHelper::askToRepeat());
    }

    void ibwCalc(Patient& p) {
        do {
            std::cout << "\n--- IDEAL BODY WEIGHT (IBW) ---\n";
            std::cout << "Gender used: " << p.getGender() << "\n";
            double height_cm = InputHelper::getFloat("Height (cm): ", 0.1);
            double height_in = height_cm / 2.54;
            double ibw;
            if (p.getGender() == "Male") {
                ibw = 50.0 + 2.3 * (height_in - 60.0);
            } else {
                ibw = 45.5 + 2.3 * (height_in - 60.0);
            }
            std::cout << "Estimated ideal weight: " << InputHelper::formatNum(ibw, 2) << " kg\n";
            p.addRecord("Ideal Body Weight: " + InputHelper::formatNum(ibw, 2) + " kg");
        } while (InputHelper::askToRepeat());
    }
};

// ==========================================
// Application controller
// ==========================================
class MedicalApp {
private:
    Patient patients_[MAX_PATIENTS];
    int currentIndex_;
    Calculators calculators_;

public:
    MedicalApp() : currentIndex_(0) {}

    void run() {
        std::cout << "WELCOME TO THE MEDICAL ASSESSMENT SYSTEM\n";
        std::cout << "Please provide accurate patient information for reliable results.\n";

        while (true) {
            // If current patient is empty, collect data and assign ID
            if (patients_[currentIndex_].getName().empty()) {
                patients_[currentIndex_].setID(currentIndex_ + 1);
                patients_[currentIndex_].setInfo();
            }

            bool usedService = false;

            // Session loop for the current patient
            while (true) {
                std::cout << "\n--- MAIN MENU ---\n";
                std::cout << "1. Medical Calculations\n";
                std::cout << "2. Patient History (Database)\n";
                if (usedService) {
                    std::cout << "3. Register a New Patient\n";
                    std::cout << "4. Exit Application\n";
                } else {
                    std::cout << "3. Exit Application\n";
                }
                std::cout << "Choice: ";

                int maxChoice = usedService ? 4 : 3;
                int choice = InputHelper::getInt("", 1, maxChoice);

                if (choice == 1) {
                    calculationMenu();
                    usedService = true;
                }
                else if (choice == 2) {
                    // separation line after selecting Patient History
                    std::cout << "\n----------------------------------------\n";
                    handlePatientLookup();
                }
                else if (choice == 3) {
                    if (usedService) {
                        if (currentIndex_ < (MAX_PATIENTS - 1)) {
                            currentIndex_++;
                            break; // break to outer loop to register new patient
                        } else {
                            std::cout << "Cannot register new patient: capacity reached.\n";
                        }
                    } else {
                        std::cout << "\nThank you for using the application. Goodbye.\n";
                        return;
                    }
                }
                else { // choice == 4
                    std::cout << "\nThank you for using the application. Goodbye.\n";
                    return;
                }
            }
        }
    }

private:
    void handlePatientLookup() {
        while (true) {
            std::cout << "\n========================================\n";
            std::cout << "           PATIENT DATABASE\n";
            std::cout << "========================================\n";
            std::cout << "Enter patient ID to view records (0 to return): ";
            int id = InputHelper::getInt("", 0, MAX_PATIENTS);
            if (id == 0) return;
            if (id >= 1 && id <= (currentIndex_ + 1) && !patients_[id - 1].getName().empty()) {
                patients_[id - 1].showHistory();
            } else {
                std::cout << "No patient found with ID #" << id << ". Please try again.\n";
            }
        }
    }

    void calculationMenu() {
        while (true) {
            std::cout << "\n--- MEDICAL CALCULATIONS ---\n";
            // separation line placed immediately after the MEDICAL CALCULATIONS header
            std::cout << "----------------------------------------\n";
            std::cout << "1. Cholesterol\n";
            std::cout << "2. Body Fat % (from BMI)\n";
            std::cout << "3. Blood Glucose\n";
            std::cout << "4. Waist-to-Height Ratio\n";
            std::cout << "5. Lipid Profile (IDL)\n";
            std::cout << "6. Blood Pressure\n";
            std::cout << "7. BMI\n";
            std::cout << "8. Ideal Body Weight\n";
            std::cout << "9. Return to Main Menu\n";
            std::cout << "Choice: ";

            int choice = InputHelper::getInt("", 1, 9);
            if (choice == 9) return;

            switch (choice) {
                case 1: calculators_.cholesterol(patients_[currentIndex_]); break;
                case 2: calculators_.bodyFat(patients_[currentIndex_]); break;
                case 3: calculators_.bloodSugar(patients_[currentIndex_]); break;
                case 4: calculators_.waistToHeight(patients_[currentIndex_]); break;
                case 5: calculators_.lipidProfile(patients_[currentIndex_]); break;
                case 6: calculators_.bloodPressure(patients_[currentIndex_]); break;
                case 7: calculators_.bmiCalc(patients_[currentIndex_]); break;
                case 8: calculators_.ibwCalc(patients_[currentIndex_]); break;
                default: break;
            }
        }
    }
};

int main() {
    MedicalApp app;
    app.run();
    return 0;
}
