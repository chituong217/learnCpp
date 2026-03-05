#include <iostream>

using namespace std;

int cnt[10000005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int maxVal = 0;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
        maxVal = max(maxVal, a[i]);
    }

    for (int i = 0; i <= maxVal; i++){
        if (cnt[i] > 0){
            cout << i << ' ' << cnt[i] << '\n';
        }
    }

    cout << '\n';

    for (int i = 0; i < n; i++){
        if (cnt[a[i]] > 0){
            cout << a[i] << ' ' << cnt[a[i]] << '\n';
            cnt[a[i]] = 0;
        }
    }


    return 0;
}