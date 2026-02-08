#include <iostream>

using namespace std;

int a[1005][1005];
long long prefix[1005][1005];

int main(){
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j];
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;

        int sum = prefix[x2][y2] - prefix[x2][y1 - 1] - prefix[x1 - 1][y2] + prefix[x1 - 1][y1 - 1];
        cout << sum << endl;
    }
    
    return 0;
}