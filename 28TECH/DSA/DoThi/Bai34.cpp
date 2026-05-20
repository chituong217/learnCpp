#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, n, m;
int nguoi[105];
vector<int> ke[1005];
bool visited[1005];
int gapmat[1005];

void nhap(){
    cin >> k >> n >> m;
    for (int i = 1; i <= k; i++){
        cin >> nguoi[i];
    }
    for (int i = 1; i <= m; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;
        ke[dau].push_back(cuoi);
    }
}

void dfs(int u){
    gapmat[u]++;
    visited[u] = true;

    for (int v : ke[u]){
        if (visited[v] == false){
            dfs(v);
        }
    }
}

void clearVisited(){
    for (int i = 1; i <= n; i++){
        visited[i] = false;
    }
}

int demSoLuongDiemGapMat(){
    for (int i = 1; i <= k; i++){
        dfs(nguoi[i]);
        clearVisited();
    }

    int count = 0;
    for (int i = 1; i <= n; i++){
        if (gapmat[i] == k) count++;
    }

    return count;
}

int main(){
    nhap();
    cout << demSoLuongDiemGapMat();

    return 0;
}