#include <iostream>

using namespace std;

bool F[105][10005];

int main(){
    int n;
    cin >> n;

    int sum = 0;
    int a[n + 1];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 0; i <= n; i++){
        F[i][0] = true;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= sum; j++){
            if (j >= a[i]){
                if (F[i - 1][j - a[i]] || F[i - 1][j]){
                    F[i][j] = true;
                }
                else{
                    F[i][j] = false;
                }
            }
            else{
                F[i][j] = F[i - 1][j];
            }
        }
    }

    for (int i = 0; i <= sum; i++){
        if (F[n][i] == true){
            cout << i << ' ';
        }
    }

    return 0;
}