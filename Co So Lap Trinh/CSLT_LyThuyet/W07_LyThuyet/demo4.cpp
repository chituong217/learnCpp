#include <iostream>
#include <fstream>
#include <stdint.h> 

using namespace std;

struct Fraction {
    int32_t num;   
    int32_t denom; 
};

int main() {
    Fraction p; 

    ifstream inFile("demo03.bin", ios::binary); 

    if (!inFile) {
        cout << "Khong the mo file." << endl;
        return 1;
    }
    
    inFile.read((char*)&p, sizeof(Fraction));
    inFile.close();

    cout << "Doc duoc tu file demo03.bin: " << p.num << "/" << p.denom << endl;
    return 0;
}