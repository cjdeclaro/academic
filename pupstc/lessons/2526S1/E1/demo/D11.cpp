using namespace std;
#include <iostream>

int main() {
    int maxPersonNumber = 5;
    int choice = 0;
    int counter = 0;
    int updateChoice = 0;
    
    string people[maxPersonNumber] = {};
    
    while(true){
        cout << "\n\nOptions:\n1 Add Person\n2 Show List\n3 Update Entry\n4 Delete Entry\n\n";

        cout << "Choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "\n\nADD PERSON\n\n";
                cout << "Name: ";
                cin >> people[counter];
                counter += 1;
                break;
            case 2:
                cout << "\n";
                for(int i = 0; i < counter; i++){
                    cout << i+1 << " " << people[i] << "\n";
                }
                break;
            case 3:
                cout << "\n\nUPDATE ENTRY\n\n";
                
                cout << "ID: ";
                cin >> updateChoice;
                updateChoice -= 1;
                
                cout << "New info: ";
                cin >> people[updateChoice];
                break;
            case 4:
                cout << "\n\nDELETE ENTRY\n\n";
                
                cout << "ID: ";
                cin >> updateChoice;
                updateChoice -= 1;
                
                people[updateChoice] = "-";
    
                break;
            default:
                cout << "\n\nInput Error";
        }
    }
    
    return 0;
}
