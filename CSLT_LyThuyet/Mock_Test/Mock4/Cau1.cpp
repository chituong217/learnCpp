#include <iostream>

using namespace std;

bool isMountainArray(int* a, int n){
    bool daTang = false;
    for (int i = 0; i < n; i++){
        if (daTang == false){
            if (i == 0 && a[i] >= a[i+1]) return false;
            while (a[i] < a[i+1]){
                i++;
            }
            if (a[i] > a[i+1]) daTang = true;
            else if (a[i] == a[i+1]) return false;
        }
        else{
            if (i == n - 1){
                if (a[i] < a[i-1]){
                    return true;
                }
                else{
                    return false;
                }
            }
            while (i + 1 < n && a[i] < a[i+1]){
                i++;
            }
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << isMountainArray(a, n);
}