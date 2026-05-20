#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> ke[1005];
bool visited[1005];

void nhap(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;

        ke[dau].push_back(cuoi);
        ke[cuoi].push_back(dau);
    }
}

void dfs(int u){
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

int demTPLT(){
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (visited[i] == false){
            dfs(i);
            cnt++;
        }
  }

    return cnt;
}

int demDinhTru(){
    int cnt = 0;
    int tpltbandau = demTPLT();
    for (int i = 1; i <= n; i++){
        clearVisited();
        visited[i] = true;

        int tpltsaukhixoa = demTPLT();

        if (tpltbandau < tpltsaukhixoa){
            cnt++;
        }
    }

    return cnt;
}

int main(){
    nhap();
    cout << demDinhTru();

    return 0;
}