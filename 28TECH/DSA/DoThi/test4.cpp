#include <iostream>


using namespace std;

int n;
int parent[1000005]; // luu dinh dai dien
int sz[1000005]; // luu size cua tap hop 

void init(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

// Tim dinh dai dien cho tap hop chua u
int Find(int u){
    if (u == parent[u]) return u;
    else parent[u] = Find(parent[u]);
}

bool Union(int u, int v){
    u = Find(u); // tim dai dien cua dinh u
    v = Find(v); // tim dai dien cua dinh v

    if (u == v){
        // co cung dai dien => cung tap hop
        return false; // ko gop duoc
    }
    
    if (sz[u] < sz[v]){
        swap(u, v); // uu tien u la thang size lon hon
    }
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}

int main(){
    init();
    cout << Union(6, 7) << endl;
    cout << Union(5, 7) << endl;
    cout << Union(4, 5) << endl;
    cout << Union(4, 7) << endl;
    for (int i = 1; i <= n; i++){
        cout << i << " " << parent[i] << endl;
    }

    return 0;
}