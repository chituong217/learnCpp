#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int F[105][105][105];

int main(){
    string x, y, z;
    cin >> x >> y >> z;

    int n = x.size(), m = y.size(), p = z.size();
    x = "0" + x;
    y = "0" + y;
    z = "0" + z;

    F[0][0][0] = 0;
    F[1][0][0] = 0;
    F[0][1][0] = 0;
    F[0][0][1] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int k = 1; k <= p; k++){
                if (x[i] == y[j] && y[j] == z[k]){
                    F[i][j][k] = F[i - 1][j - 1][k - 1] + 1;
                }
                else{
                    F[i][j][k] = max({F[i - 1][j][k], F[i][j - 1][k], F[i][j][k - 1]});
                }
            }
        }
    }

    cout << F[n][m][p];

    return 0;
}