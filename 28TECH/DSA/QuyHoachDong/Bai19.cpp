#include <iostream>
#define ll long long 
#define mod 1000000007

using namespace std;

ll F[1005][1005];

int main(){
    int n;
    cin >> n;
    char a[n + 1][n + 1];

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == 1 && j == 1 && a[1][1] == '.'){
                F[i][j] = 1;
                continue;
            }
            if (a[i][j] == '.'){
                if (a[i - 1][j] == '.'){
                    F[i][j] += F[i - 1][j];
                }
                if (a[i][j - 1] == '.'){
                    F[i][j] += F[i][j - 1];
                }
                F[i][j] %= mod;
            }
        }
    }

    cout << F[n][n];

    return 0;
}