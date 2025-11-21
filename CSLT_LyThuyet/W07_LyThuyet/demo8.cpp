#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile("demo07.bin", ios::binary); 

    if (!inFile) {
        cout << "Khong the mo file." << endl;
        return 1;
    }

    int len = 0;
    inFile.read((char*)&len, sizeof(len));

    char* myString = new char[len + 1]; 

    inFile.read(myString, len);
    myString[len] = '\0';

    inFile.close();

    cout << "Doc duoc chuoi tu file demo07.bin:" << endl;
    cout << myString << endl;

    delete[] myString;

    return 0;
}