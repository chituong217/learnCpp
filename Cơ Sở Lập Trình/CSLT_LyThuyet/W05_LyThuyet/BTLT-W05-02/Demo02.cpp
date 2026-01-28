#include <iostream>
#include <fstream>
using namespace std;

void loadIntArray(ifstream &f, int a[], int &n);
void printIntArray(int a[], int n);

int main(int argc, const char * argv[]) {
    ifstream f;
    int a[100];
    int n = 0;
    
    f.open("D:\\intarray-input.txt");
    if(!f.is_open()){
        cout << "File khong ton tai" << endl;
    }
    else{
        loadIntArray(f, a, n);
        printIntArray(a, n);
        f.close();
    }
    return 0;
}

void loadIntArray(ifstream &f, int a[], int &n){
    f >> n;
    for(int i = 0; i < n; i++){
        f >> a[i];
    }
}

void printIntArray(int a[], int n){
    if(n == 0){
        cout << "Mang rong" << endl;
    }
    else{
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}