#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    bool ok = true;
    for (int i = 1; i < n; i++){
        if (a[i] <= a[i - 1]){
            ok = false;
        }
    }

    if (ok == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}