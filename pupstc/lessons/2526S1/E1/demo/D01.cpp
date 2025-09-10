#include <iostream>
using namespace std;

void printGrade(int g, string evaluation){ //parameter
    cout << g << " (" << evaluation << ")";
}

int main() {
    float grade = 0;
    
    cout << "Input grade:";
    cin >> grade;
    
    bool isPassed = grade < 5;
    bool isGradeValid = grade <= 5;
    
    if(isGradeValid) {
        if(isPassed) {
            //function call
            printGrade(grade, "P");
        } else {
            printGrade(grade, "F");
        }
    } else {
        printGrade(0, "INVALID"); //arguments
    }
    
    return 0;
}
