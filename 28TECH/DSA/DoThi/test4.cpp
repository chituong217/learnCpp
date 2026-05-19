#include <iostream>


using namespace std;

int n;
int parent[1000005];

void init(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        parent[i] = i;
    }
}

// Tim dinh dai dien cho tap hop chua u
int Find(int u){
    while (u != parent[u]){
        u = parent[u];
    }

    return u;
}

bool Union(int u, int v){
    u = Find(u); // tim dai dien cua dinh u
    v = Find(v); // tim dai dien cua dinh v

    if (u == v){
        // co cung dai dien => cung tap hop
        return false; // ko gop duoc
    }
    else{
        // chon thang nho hon lam dai dien
        if (u < v) parent[v] = u;
        else parent[u] = v;
        return true;
    }
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