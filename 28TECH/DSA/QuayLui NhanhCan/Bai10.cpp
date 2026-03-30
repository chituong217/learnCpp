#include <iostream>

using namespace std;

int n, X[100];
int c[100][100], ans = INT_MAX;
int visited[100], sum = 0;
int cmin = INT_MAX;

// X[i] = j : thanh phu thi i di qua la thanh pho j

void Try(int i){
    for (int j = 1; j <= n; j++){
        if (visited[j] == 0){
            X[i] = j;
            visited[j] = 1;
            sum += c[X[i - 1]][X[i]];

            if (i == n){
                // cap nhat ket qua
                ans = min(sum + c[X[n]][1], ans);
            }
            else if (sum + (n - i + 1) * cmin < ans){
                // đánh giá cận
                Try(i + 1);
            }

            visited[j] = 0;
            sum -= c[X[i - 1]][X[i]];
        }
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> c[i][j];
            if (c[i][j]){
                cmin = min(cmin, c[i][j]);
            }
        }
    }

    X[1] = 1;
    visited[1] = 1;
    Try(2);
    cout << ans;

    return 0;
}