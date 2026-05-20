#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, s;
vector<pair<int,int>> ke[1005];
bool visited[1005];

void nhap(){
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;

        ke[x].push_back({y, w});
        ke[y].push_back({x, w});
    }
}

void Dijkstra(int s){
    vector<int> d(n + 1, 1e9);
    d[s] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    Q.push({0, s});
    
    while (!Q.empty()){
        // Chon ra dinh u co duong di ngan nhat => relaxation
        pair<int,int> top = Q.top(); Q.pop();
        int u = top.second, kc = top.first;

        if (kc > d[u]) continue;
        
        // relax
        for (auto it : ke[u]){
            int v = it.first, w = it.second;
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++){
        cout << d[i] << ' ';
    }
}

int main(){
    nhap();
    Dijkstra(s);

    return 0;
}