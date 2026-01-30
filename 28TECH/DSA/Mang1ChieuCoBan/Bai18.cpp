#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        bool ok = false;
        if (i == 0){
            if (a[i] * a[i + 1] < 0){
                ok = true;
            }
        }
        else if (i == n - 1){
            if (a[i] * a[i - 1] < 0){
                ok = true;
            }
        }
        else{
            if (a[i] * a[i - 1] < 0 || a[i] * a[i + 1] < 0){
                ok = true;
            }
        }

        if (ok == true){
            cout << a[i] << ' ';
        }
    }

    return 0;
}