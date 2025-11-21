#include <iostream>
#include <fstream>
#include <cstring> 

using namespace std;

int main() {
    char myString[] = "Hello Binary File";

    ofstream outFile("demo07.bin", ios::binary);

    if (!outFile) {
        cout << "Khong the mo file." << endl;
        return 1;
    }
    
    int len = strlen(myString); 
    
    outFile.write((const char*)&len, sizeof(len));
    outFile.write(myString, len); 

    outFile.close();

    cout << "Da ghi chuoi (cung do dai) vao file demo07.bin." << endl;
    return 0;
}