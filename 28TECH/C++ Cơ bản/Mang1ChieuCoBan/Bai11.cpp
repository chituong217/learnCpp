#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000000
using namespace std;

void createFiboArray(long long fibo[]){
    long long f1 = 0;
    long long f2 = 1;
    fibo[0] = 0; fibo[1] = 1;
    long long f;
    for (int i = 2; i <= 93; i++){
        f = f1 + f2;
        fibo[i] = f;
        f1 = f2;
        f2 = f;
    }
}

long long a[MAX_LEN];
long long fibo[MAX_LEN];

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int cnt = 0;
    createFiboArray(fibo);
    for (int i=0; i<n; i++){
        int check = 0;
        for (int j=0; j<=93; j++){
            if (a[i] == fibo[j]){
                check = 1;
                cnt++;
                break;
            }
        }
        if (check == 1){
            cout << a[i] << ' ';
        }
    }
    if (cnt == 0){
        cout << "NONE";
    }
    return 0;
}