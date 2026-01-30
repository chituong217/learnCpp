#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], b[n - 1];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++){
        cin >> b[i];
    }

    int sum = a[0];
    for (int i = 0; i < n - 1; i++){
        if (b[i] == 1){
            sum += a[i + 1];
        }
        else{
            sum -= a[i + 1];
        }
    }

    cout << sum;
    return 0;
}