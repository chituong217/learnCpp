#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);
    long long so1 = 0, so2 = 0;
    for (int i = 0; i < n; i++){
        if (i % 2 == 0){
            so1 *= 10;
            so1 += a[i];
        }
        else{
            so2 *= 10;
            so2 += a[i];
        }
    }

    long long sum = so1 + so2;
    cout << sum;

    return 0;
}