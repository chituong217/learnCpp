#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge{
    int x, y, w;
};

int n, m;
int parent[1000005];
int sz[1000005];
vector<edge> dscanh;

void nhap(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;

        dscanh.push_back({x, y, w});
    }
}

void ktao(){
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int u){
    if (parent[u] == u) return u;
    else{
        parent[u] = Find(parent[u]);
        return parent[u];
    }
}

bool Union(int u, int v){
    u = Find(u);
    v = Find(v);

    if (u == v) return false;

    if (sz[u] < sz[v]) swap(u, v);

    sz[u] += sz[v];
    parent[v] = u;
    return true;
}

bool comp(edge a, edge b){
    return a.w < b.w;
}

long long Kruskal(){
    sort(dscanh.begin(), dscanh.end(), comp);

    long long sumWeight = 0;
    int count = 0;
    for (auto it : dscanh){
        if (count == n - 1) break;

        if (Union(it.x, it.y)){
            count++;
            sumWeight += it.w;
        }
    }

    if (count == n - 1) return sumWeight;
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    nhap();
    ktao();
    cout << Kruskal();

    return 0;
}