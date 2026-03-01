#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long F[n];
    for (int i = 0; i < n; i++){
        if (i == 0){
            F[i] = a[i];
        }
        else{
            F[i] = F[i - 1] + (long long)a[i];
        }
    }

    for (int i = 0; i < n; i++){
        cout << F[i] << ' ';
    }

    return 0;
}