#include <iostream>

using namespace std;


int main(){
    int n, x , k;
    cin >> n >> x >> k;
    int a[n + 1];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = n; i >= k; i--){
        a[i] = a[i - 1];
    }
    a[k - 1] = x;

    for (int i = 0; i < n + 1; i++){
        cout << a[i] << ' ';
    }

    return 0;
}