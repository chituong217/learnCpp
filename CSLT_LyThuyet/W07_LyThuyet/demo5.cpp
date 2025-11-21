#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int arr[5] = { 10, 20, 30, 40, 50 };

    ofstream outFile("demo05.bin", ios::binary);

    if (!outFile) {
        cout << "Khong the mo file." << endl;
        return 1;
    }
    
    outFile.write((const char*)arr, sizeof(arr));
    outFile.close();

    cout << "Da ghi mang 5 so nguyen vao file demo05.bin." << endl;
    return 0;
}