#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> ke[100005];
int color[100005];

void nhap(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;

        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

bool bfs(int u){
    queue<int> q;
    q.push(u);
    color[u] = 1;

    while (!q.empty()){
        int u = q.front();
        q.pop();

        for (int v : ke[u]){
            if (color[v] == 0){
                if (color[u] == 1) color[v] = 2;
                else if (color[u] == 2) color[v] = 1;
                q.push(v);
            }
            else{
                if (color[u] == color[v]) return false;
            }
        }
    }

    return true;
}

int main(){
    nhap();

    bool ok = true;
    for (int i = 1; i <= n; i++){
        if (color[i] == 0){
            if (bfs(i) == false) ok = false;
        }
    }

    if (ok){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}