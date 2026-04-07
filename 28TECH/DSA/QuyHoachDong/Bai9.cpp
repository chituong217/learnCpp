#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int F[1005][1005];

int main(){
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    int a[n + 1], b[m + 1];
    for (int i = 1; i <= n; i++){
        a[i] = (int)(s[i - 1] - '0');
    }
    for (int i = 1; i <= m; i++){
        b[i] = (int)(t[i - 1] - '0');
    }

    F[0][0] = 0;
    F[0][1] = 0;
    F[1][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i] == b[j]){
                F[i][j] = F[i - 1][j - 1] + 1;
            }
            else{
                F[i][j] = max(F[i - 1][j], F[i][j - 1]);
            }
        }
    }

    cout << F[n][m];

    return 0;
}