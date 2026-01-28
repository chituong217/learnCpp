#include <iostream>
#define MAX_LEN 100

using namespace std;

bool isDoixung(int a[][MAX_LEN], int n){
    for (int i=0; i<n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (a[i][j] != a[n-1-j][n-1-i]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    int a[MAX_LEN][MAX_LEN];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    
    if (isDoixung(a, n) == true){
        cout << "Ma tran doi xung qua cheo phu" << endl;
    }
    else{
        cout << "Ma tran KHONG doi xung qua cheo phu" << endl;
    }
    return 0;
}