#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int arr[5]; 

    ifstream inFile("demo05.bin", ios::binary); 

    if (!inFile) {
        cout << "Khong the mo file." << endl;
        return 1;
    }
    
    inFile.read((char*)arr, sizeof(arr));
    inFile.close();

    cout << "Doc duoc mang 5 so nguyen tu file demo05.bin:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}