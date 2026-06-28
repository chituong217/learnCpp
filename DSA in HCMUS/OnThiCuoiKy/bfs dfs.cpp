#include <bits/stdc++.h>

using namespace std;

void bfs(int start, const vector<int> adj[], int numV){
    if (numV == 0) return;
    vector<bool> visited(numV, false);

    queue<int> q;
    q.push(start);

    while (!q.empty()){
        int u = q.front();
        cout << u << ' ';
        q.pop();

        for (int v : adj[u]){
            if (visited[v] == false){
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

void dfs(int u, const vector<int> adj[], bool visited[]){
    cout << u << ' ';
    visited[u] = true;

    for (int v : adj[u]){
        if (visited[v] == false){
            dfs(v, adj, visited);
        }
    }
}