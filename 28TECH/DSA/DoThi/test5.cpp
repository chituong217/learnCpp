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

void init(){
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

void nhap(){
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++){
        int dau, cuoi, w;
        cin >> dau >> cuoi >> w;

        dscanh.push_back((edge){dau, cuoi, w});
    }
}

bool comp(edge a, edge b){
    // theo trong so
    return a.w < b.w;
}

void Kruskal(){
    // B1 : sap xep danh sach canh theo trong so tang dan
    sort(dscanh.begin(), dscanh.end(), comp);

    // B2 : Lap va chon
    int d = 0;
    vector<edge> MST;

    for (int i = 0; i < m; i++){
        if (MST.size() == n - 1) break;

        edge e = dscanh[i];
        // them canh e vao MST -> co tao chu trinh ko?
        if (Union(e.x, e.y) == true){
            MST.push_back(e);
            d += e.w;
        }
    }

    cout << d << endl;
    for (auto it : MST){
        cout << it.x << ' ' << it.y << ' ' << it.w << endl;
    }
}

int main(){
    nhap();
    init();
    Kruskal();

    return 0;
}