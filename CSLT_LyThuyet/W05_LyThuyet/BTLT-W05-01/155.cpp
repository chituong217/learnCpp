#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int ans = a[0];
    for (int i=0; i<n; i++){
        if (abs(a[i] - x) > abs(ans - x)){
            ans = a[i];
        }
    }
    cout << ans;
    return 0;
}