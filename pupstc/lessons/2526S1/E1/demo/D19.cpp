using namespace std;
#include <iostream>

int main() {
    string words[][5] = {
        {"Hello", "World"},
        {"Kumusta", "Mundo"},
        {"你好", "世界"},
        {"안녕하세요", "세계"}
    };
    
    int lang = 0;
    
    cout << "Choose Language:\n";
    cout << "1 - English\n";
    cout << "2 - Filipino\n";
    cout << "3 - Chinese\n";
    cout << "4 - Korean\n";
    
    cout << "\nChoice:";
    cin >> lang;
    
    lang-=1;
    
    cout << words[lang][0] << " " << words[lang][1];

    return 0;
}
