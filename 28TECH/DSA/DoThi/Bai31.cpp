#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
char a[1005][1005];
bool visited[1005][1005];
int dientich = 0;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

void nhap(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
}

void dfs(int i, int j){
    dientich++;
    visited[i][j] = true;

    for (int k = 0; k < 4; k++){
        int i1 = i + dx[k], j1 = j + dy[k];

        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == '.' && visited[i1][j1] == false){
            dfs(i1, j1);
        }
    }
}

void inDienTich(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i][j] == '.' && visited[i][j] == false){
                dfs(i, j);
                cout << dientich << ' ';
                dientich = 0;
            }
        }
    }
}

int main(){
    nhap();
    inDienTich();

    return 0;
}