#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ke[1005];
bool visited[1005];
int parent[1005];

void nhap(int m){
    for (int i = 1; i <= m; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;

        ke[dau].push_back(cuoi);
        ke[cuoi].push_back(dau);
    }
}

void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (q.empty() == false){
        int v = q.front();
        q.pop();
        
        for (int x : ke[v]){
            if (visited[x] == false){
                q.push(x);
                parent[x] = v;
                visited[x] = true;
            }
        }
    }
}

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    nhap(m);

    for (int i = 1; i <= n; i++){
        sort(ke[i].begin(), ke[i].end());
    }

    BFS(s);

    if (visited[t] == false){
        cout << "-1";
    }
    else{
        vector<int> path;
        while (t != s){
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(t);

        reverse(path.begin(), path.end());
        for (int x : path){
            cout << x << ' ';
        }
    }

    return 0;
}