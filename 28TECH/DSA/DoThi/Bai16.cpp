#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ke[1005];
bool visited[1005];
int parent[1005];

void nhap(int canh){
    for (int i = 1; i <= canh; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;

        ke[dau].push_back(cuoi);
    }
}

void DFS(int u){
    visited[u] = true;

    for (int v : ke[u]){
        if (visited[v] == false){
            parent[v] = u;
            DFS(v);
        }
    }
}

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    
    nhap(m);
    for (int i = 1; i <= n; i++){
        sort(ke[i].begin(), ke[i].end());
    }

    DFS(s);
    if (visited[t] == false){
        cout << "-1";
    }
    else{
        vector<int> path;
        while (t != s){
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(t);

        reverse(path.begin(), path.end());

        for (int x : path){
            cout << x << ' ';
        }
    }

    return 0;
}