#include <iostream>

using namespace std;

int main(){
    int n, m, p;
    cin >> n >> m >> p;
    int a[n], b[m];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    for (int i = 0; i < p; i++){
        cout << a[i] << ' ';
    }

    for (int i = 0; i < m; i++){
        cout << b[i] << ' ';
    }

    for (int i = p; i < n; i++){
        cout << a[i] << ' ';
    }

    return 0;
}