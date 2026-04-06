#include <iostream>
#include <string>

using namespace std;

int F[1005][1005];

int main(){
    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    s = "0" + s;
    t = "0" + t;
    
    F[0][0] = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (s[i] == t[j]){
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