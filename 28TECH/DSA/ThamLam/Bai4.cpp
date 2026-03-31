#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    k = min(k, n - k);
    sort(a, a + n);
    long long be = 0, lon = 0;
    for (int i = 0; i < k; i++){
        be += a[i];
    }
    for (int i = k; i < n; i++){
        lon += a[i];
    }

    cout << lon - be;
    

    return 0;
}