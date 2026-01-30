#include <iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> k;

    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (a[i] + a[j] == k){
                cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}