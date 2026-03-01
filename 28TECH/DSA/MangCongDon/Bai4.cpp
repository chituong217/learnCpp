#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int D[n];
    for (int i = 0; i < n; i++){
        if (i == 0){
            D[i] = a[i];
        }
        else{
            D[i] = a[i] - a[i - 1];
        }
    }

    for (int i = 0; i < n; i++){
        cout << D[i] << ' ';
    }

    return 0;
}