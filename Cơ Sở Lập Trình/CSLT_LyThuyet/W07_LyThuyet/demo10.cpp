#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile("demo09.bin", ios::binary); 

    if (!inFile) {
        cout << "Khong the mo file." << endl;
        return 1;
    }

    int n = 0;
    inFile.read((char*)&n, sizeof(n));

    int* dynamicArray = new int[n];

    inFile.read((char*)dynamicArray, n * sizeof(int));

    inFile.close();

    cout << "Doc duoc mang dong (" << n << " phan tu) tu file demo09.bin:" << endl;
    for (int i = 0; i < n; i++) {
        cout << dynamicArray[i] << " ";
    }
    cout << endl;

    delete[] dynamicArray;

    return 0;
}