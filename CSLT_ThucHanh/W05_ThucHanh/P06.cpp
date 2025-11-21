#include <iostream>
#define MAX_LEN 100

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[MAX_LEN];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    bool isTang = true, isGiam = true;

    for (int i=1; i<n; i++){
        if (a[i] < a[i-1]){
            isTang = false;
        }
    }

    if (isTang == 0){
        for (int i=1; i<n; i++){
            if (a[i] > a[i-1]){
            isGiam = false;
            }
        }
    }
    else{
        cout << "Mang tang" << endl;
        return 0;
    }

    if (isGiam == 1){
        cout << "Mang giam" << endl;
    }
    else{
        cout << "Mang khong tang khong giam" << endl;
    }

    return 0;
}