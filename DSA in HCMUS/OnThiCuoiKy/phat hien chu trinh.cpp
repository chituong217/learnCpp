#include <bits/stdc++.h>

using namespace std;

bool hasCycleUndirected(int u, int parent, const vector<int> adj[], bool visited[]){
    visited[u] = true;

    for (int v : adj[u]){
        if (visited[v] == false){
            if (hasCycleUndirected(v, u, adj, visited)){
                return true;
            }
        }
        else{
            if (v != parent) return true;
        }
    }

    return false;
}

bool hasCycleDirected(int u, const vector<int> adj[], int color[]){
    color[u] = 1;

    for (int v : adj[u]){
        if (color[v] == 1) return true;
        else if (color[v] == 0){
            if (hasCycleDirected(v, adj, color)) return true;
        }
    }

    color[u] = 2;
    return false;
}