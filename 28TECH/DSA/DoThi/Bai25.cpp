#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char a[1005][1005];
bool visited[1005][1005];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int n, m;

void loang(int i, int j){
    visited[i][j] = true;
    for (int k = 0; k < 4; k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];

        if (i1 > 0 && j1 > 0 && i1 <= n && j1 <= m && visited[i1][j1] == false && a[i][j] == '.'){
            loang(i1, j1);
        }
    }
}

int main(){
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (visited[i][j] == false && a[i][j] == '.'){
                cnt++;
                loang(i, j);
            }
        }
    }

    cout << cnt;

    return 0;
}