#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int n = 3;
    int* dynamicArray = new int[n];
    dynamicArray[0] = 100;
    dynamicArray[1] = 200;
    dynamicArray[2] = 300;

    ofstream outFile("demo09.bin", ios::binary);

    if (!outFile) {
        cout << "Khong the mo file." << endl;
        delete[] dynamicArray; 
        return 1;
    }

    outFile.write((const char*)&n, sizeof(n));
    outFile.write((const char*)dynamicArray, n * sizeof(int));

    outFile.close();
    
    cout << "Da ghi mang dong (3 phan tu) vao file demo09.bin." << endl;

    delete[] dynamicArray;

    return 0;
}