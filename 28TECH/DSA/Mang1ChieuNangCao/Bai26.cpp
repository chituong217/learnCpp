#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long cnt = 0;
    for (int i = 1; i < n; i++){
        if (a[i] <= a[i - 1]){
            int needToPlus = a[i - 1] - a[i] + 1;
            cnt += needToPlus;
            a[i] += needToPlus;
        }
    }

    // for (int i = 0; i < n; i++){
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    cout << cnt;

    return 0;
}