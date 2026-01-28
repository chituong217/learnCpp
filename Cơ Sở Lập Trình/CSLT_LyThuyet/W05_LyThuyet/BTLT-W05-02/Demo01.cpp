#include <iostream>
#include <fstream>
using namespace std;

void inputIntArray(int a[], int &n);
void saveIntArray(ofstream &f, int a[], int n);

int main(int argc, const char * argv[]) {
    int a[100];
    int n = 0;
    inputIntArray(a, n);
    ofstream f;
    f.open("D:\\intarray-output.txt");
    if(!f.is_open()){
        cout << "Khong the mo file intarray-output.txt" << endl;
    }
    else{
        saveIntArray(f, a, n);
        f.close();
    }
    
    return 0;
}

void inputIntArray(int a[], int &n){
    cout << "Number of elements: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
}

void saveIntArray(ofstream &f, int a[], int n){
    f << n << endl;
    for(int i = 0; i < n; i++){
        f << a[i] << " ";
    }
}