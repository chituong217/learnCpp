#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge{
    int x, y, w;
};

int n, m;
int parent[1000005], sz[1000005];
vector<edge> dscanh;

int Find(int u){
    if (u == parent[u]){
        return u;
    }
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
    for (int i = 1; i <= m; i++){
        int dau, cuoi, w;
        cin >> dau >> cuoi >> w;

        dscanh.push_back({dau, cuoi, w});
    }
}

void init(){
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

bool compW(edge a, edge b){
    return a.w < b.w;
}

void Kruskal(){
    sort(dscanh.begin(), dscanh.end(), compW);

    long long d = 0;
    vector<edge> MST;
    for (int i = 0; i < m; i++){
        if ((int)MST.size() == n - 1) break;

        edge e = dscanh[i];
        if (Union(e.x, e.y) == true){
            d += e.w;
            MST.push_back(e);
        }
    }

    if ((int)MST.size() == n - 1){
        cout << d;
    }
    else{
        cout << "IMPOSSIBLE";
    }
}

int main(){
    nhap();
    init();
    Kruskal();

    return 0;
}