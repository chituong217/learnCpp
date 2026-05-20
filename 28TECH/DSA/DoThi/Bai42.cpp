#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, dem, maxCur = 1;
int parent[1000005], sz[1000005];

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
        maxCur = max(maxCur, sz[u]);
        parent[v] = u;
        return true;
    }
}

void nhap(){
    dem = n;
    for (int i = 1; i <= m; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;

        if (Union(dau, cuoi) == true){
            dem--;
        }
        cout << dem << ' ' << maxCur << '\n';
    }
}

void init(){
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}



int main(){
    cin >> n >> m;
    init();
    nhap();

    return 0;
}