#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i < n; i++){
        if (min > a[i]){
            min = a[i];
        }
        if (max < a[i]){
            max = a[i];
        }
    }

    for (int i = n - 1; i >= 0; i--){
        if (a[i] == min){
            cout << i << ' ';
            break;
        }
    }

    for (int i = 0; i < n; i++){
        if (a[i] == max){
            cout << i;
            break;
        }
    }

    return 0;
}