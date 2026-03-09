#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int a[n], b[m];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    int i = 0, j = 0;
    bool ok = false;

    while (i < n && j < m){
        if (a[i] == b[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
    }

    if (j == m){
        ok = true;
    }

    if (ok == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}