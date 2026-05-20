#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> ke[100005];
bool visited[100005];
vector<int> component;

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
    component.push_back(u);
    visited[u] = true;

    for (int v : ke[u]){
        if (visited[v] == false){
            dfs(v);
        }
    }
}

int main(){
    nhap();
    bool ok = true;

    for (int i = 1; i <= n; i++){
        if (visited[i] == false){
            dfs(i);
        }
        
        int sz = component.size();
        for (int u : component){
            if ((int)ke[u].size() != sz - 1){
                ok = false;
                break;
            }
        }

        component.clear();
    }

    if (ok){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}