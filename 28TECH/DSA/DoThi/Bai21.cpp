#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> ke[1005];
bool visited[1005];
int parent[1005];

void nhap(){
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;

        ke[dau].push_back(cuoi);
        ke[cuoi].push_back(dau);
    }
}

bool DFS(int u){
    visited[u] = true;

    for (int v : ke[u]){
        if (visited[v] == false){
            parent[v] = u;
            if (DFS(v) == true){
                return true;
            }
        }
        else if (v != parent[u]){
            return true;
        }
    }

    return false;
}

int main(){
    nhap();

    bool ok = false;
    for (int i = 1; i <= n; i++){
        if (visited[i] == false){
            if (DFS(i)) ok = true;
        }
    }

    if (ok == true){
        cout << "1";
    }
    else{
        cout << "0";
    }

    return 0;
}