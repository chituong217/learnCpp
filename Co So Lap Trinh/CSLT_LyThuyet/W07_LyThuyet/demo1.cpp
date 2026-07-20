#include <iostream>
#include <fstream> 

using namespace std;

int main() {
    int myNumber = 12345;

    ofstream outFile("demo01.bin", ios::binary);

    if (!outFile.is_open()) {
        cout << "Khong the mo file." << endl;
        return 1;
    }
    
    outFile.write((const char*)&myNumber, sizeof(myNumber));
    outFile.close();

    cout << "Da ghi file demo01.bin thanh cong." << endl;
    return 0;
}