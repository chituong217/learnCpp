#include <iostream>
#include <vector>

using namespace std;

int n, m;
int parent[1005], bac[1005];

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
        if (bac[u] < bac[v] || (bac[u] == bac[v]) && (u > v)){
            swap(u, v);
        }
        parent[v] = u;
        return true;
    }
}


int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<pair<int,int>> edges;
    for (int i = 1; i <= m; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;

        edges.push_back({dau, cuoi});
        bac[dau]++;
        bac[cuoi]++;
    }

    for (auto it : edges){
        int x = it.first, y = it.second;
        Union(x, y);
    }

    for (int i = 1; i <= n; i++){
        if (i == parent[i]){
            cout << i << ' ';
        }
    }

    return 0;
}