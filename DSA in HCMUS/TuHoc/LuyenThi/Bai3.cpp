#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge{
    int x, y, w;
};

int n, m;
vector<edge> dscanh;
int parent[10005];
int sz[10005];

void ktao(){
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int u){
    if (u == parent[u]) return u;
    else{
        parent[u] = Find(parent[u]);
        return parent[u];
    }
}

bool Union(int u, int v){
    u = Find(u);
    v = Find(v);

    if (u == v){
        return false;
    }
    else{
        if (sz[u] < sz[v]){
            swap(u, v);
        }

        sz[u] += sz[v];
        parent[v] = u;
        return true;
    }
}

void nhap(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        dscanh.push_back({x, y, w});
    }
}

bool compEdge(edge a, edge b){
    return a.w < b.w;
}

long long Kruskal(){
    long long minW = 0;
    int d = 0;
    sort(dscanh.begin(), dscanh.end(), compEdge);

    for (int i = 0; i < m; i++){
        if (d == n - 1) break;

        edge e = dscanh[i];
        if (Union(e.x, e.y)){
            minW += e.w;
            d++;
        }
    }

    return minW;
}

int main(){
    nhap();
    ktao();
    cout << Kruskal();

    return 0;
}