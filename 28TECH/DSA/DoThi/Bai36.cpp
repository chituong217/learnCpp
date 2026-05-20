#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> ke[1005];
bool visited[1005];
vector<pair<int,int>> docao;

void nhap(){
    cin >> n;
    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void dfs(int u, int height){
    docao.push_back({u, height});
    visited[u] = true;

    for (int v : ke[u]){
        if (visited[v] == false){
            dfs(v, height + 1);
        }
    }
}

int main(){
    nhap();
    dfs(1, 0);

    sort(docao.begin(), docao.end());
    for (auto it : docao){
        cout << it.second << ' ';
    }

    return 0;
}