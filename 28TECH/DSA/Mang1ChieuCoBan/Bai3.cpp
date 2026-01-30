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
    int cnt = 0;

    for (int i = 0; i < n; i++){
        if (min > a[i]){
            min = a[i];
        }
    }

    for (int i = 0; i < n; i++){
        if (min == a[i]){
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}