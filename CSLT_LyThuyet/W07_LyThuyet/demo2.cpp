#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int myNumber = 0; 

    ifstream inFile("demo01.bin", ios::binary); 

    if (!inFile) {
        cout << "Khong the mo file." << endl;
        return 1;
    }
    
    inFile.read((char*)&myNumber, sizeof(myNumber));
    inFile.close();

    cout << "Doc duoc tu file demo01.bin: " << myNumber << endl;
    return 0;
}