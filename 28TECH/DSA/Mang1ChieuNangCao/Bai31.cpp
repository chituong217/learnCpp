#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);
    long long maxVal = max(abs(a[n-1] + a[n - 2]), abs(a[1] + a[0]));
    cout << abs(maxVal);

    return 0;
}