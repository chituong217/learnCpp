#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ke[1005];
bool visited[1005];
int id[1005];
int cnt = 0;

void nhap(int canh){
    for (int i = 1; i <= canh; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;

        ke[dau].push_back(cuoi);
        ke[cuoi].push_back(dau);
    }
}

void DFS(int u){
    id[u] = cnt;
    visited[u] = true;

    for (int v : ke[u]){
        if (visited[v] == false){
            DFS(v);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    nhap(m);

    for (int i = 1; i <= n; i++){
        sort(ke[i].begin(), ke[i].end());
    }

    for (int i = 1; i <= n; i++){
        if (visited[i] == false){
            cnt++;
            DFS(i);
        }
    }

    int q;
    cin >> q;
    while (q--){
        int s, t;
        cin >> s >> t;

        if (id[s] == id[t]){
            cout << "1\n";
        }
        else{
            cout << "-1\n";
        }
    }

    return 0;
}