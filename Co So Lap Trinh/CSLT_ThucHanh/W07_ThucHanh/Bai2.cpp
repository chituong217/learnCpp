#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define minVal -1000
#define maxVal 2000

using namespace std;

void phatsinhMang(int *a, int n){
    for (int i = 0; i < n; i++){
        a[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

bool isSquare(int n){
    if (n < 0) return false; 
    int k = sqrt(n);
    return k * k == n;
}

bool isPrime(int n){
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    srand(time(NULL));

    int n;
    do{
        cout << "Nhap vao so luong phan tu (>=10): ";
        cin >> n;
    } while (n < 10);

    int *a = new int[n];
    phatsinhMang(a, n);

    cout << "Cac phan tu trong mang: ";
    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    cout << endl;

    bool isFoundsochinhphuongdautien = false;
    for (int i = 0; i < n; i++){
        if (isSquare(a[i])){
            isFoundsochinhphuongdautien = true;
            cout << "So chinh phuong dau tien trong mang: " << a[i] << endl;
            break;
        }
    }
    if (isFoundsochinhphuongdautien == false){
        cout << "Khong tim thay so chinh phuong nao trong mang" << endl;
    }

    int *Prime = new int[n];
    int idxPrime = 0;
    for (int i = 0; i < n; i++){
        if (isPrime(a[i])){
            Prime[idxPrime] = a[i];
            idxPrime++;
        }
    }
    
    if (idxPrime != 0){
        cout << "Mang con chua cac so nguyen to: ";
    }
    else{
        cout << "Khong ton tai so nguyen to trong mang" << endl;
    }
    for (int i = 0; i < idxPrime; i++){
        cout << Prime[i] << ' ';
    }

    cout << endl;
    
    delete []a;
    delete []Prime;
    return 0;
}