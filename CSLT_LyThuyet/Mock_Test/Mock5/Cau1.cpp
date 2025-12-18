#include <iostream>

using namespace std;

bool isMountainArray(int* a, int n){
    if (n < 3) return false;

    int i = 0;

    while (i + 1 < n && a[i] < a[i + 1]){
        i++;
    }

    if (i == 0 || i == n - 1) return false;

    while (i + 1 < n && a[i] > a[i+1]){
        i++;
    }

    return i == (n - 1);
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