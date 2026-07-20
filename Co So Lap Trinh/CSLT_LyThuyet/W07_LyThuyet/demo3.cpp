#include <iostream>
#include <fstream>
#include <stdint.h> 

using namespace std;

struct Fraction {
    int32_t num;   
    int32_t denom; 
};

int main() {
    Fraction p = {1, 2}; 

    ofstream outFile("demo03.bin", ios::binary);

    if (!outFile) {
        cout << "Khong the mo file." << endl;
        return 1;
    }
    
    outFile.write((const char*)&p, sizeof(Fraction));
    outFile.close();

    cout << "Da ghi struct Fraction {1, 2} vao file demo03.bin." << endl;
    return 0;
}