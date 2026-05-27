#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> ke[100005];
bool visited[100005];

void nhap(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;

        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void dfs(int u){
    visited[u] = true;

    for (int v : ke[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
}

int demTPLT(){
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (visited[i] == false){
            cnt++;
            dfs(i);
        }
    }

    return cnt;
}

int main(){
    nhap();
    cout << demTPLT();

    return 0;
}