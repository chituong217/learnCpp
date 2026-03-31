#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n], b[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b + n);
    bool ok = true;
    for (int i = 0; i < n / 2; i++){
        if (!((a[i] == b[i] && a[n - i - 1] == b[n - i - 1]) || 
              (a[i] == b[n - i - 1] && a[n - i - 1] == b[i]))){
            ok = false;
        }
    }

    if (n % 2 != 0){
        if (a[n / 2] != b[n / 2]){
            ok = false;
        }
    }

    if (ok){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    
    return 0;
}