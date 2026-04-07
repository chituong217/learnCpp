#include <iostream>

using namespace std;

bool F[205][50005];

int main(){
    int n, s;
    cin >> n >> s;
    
    int a[n + 1];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 0; i <= n; i++){
        F[i][0] = true;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= s; j++){
            if (j >= a[i]){
                if (F[i - 1][j - a[i]] == true || F[i - 1][j] == true){
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

    if (F[n][s] == true){
        cout << "1";
    }
    else{
        cout << "0";
    }

    return 0;
}