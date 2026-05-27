#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, s;
vector<pair<int,int>> ke[1005];

void nhap(){
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;

        ke[x].push_back({y, w});
    }
}

void Dijkstra(int s){
    vector<int> d(n + 1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;

    d[s] = 0; 
    Q.push({d[s], s});

    while (!Q.empty()){
        pair<int,int> top = Q.top();
        Q.pop();

        int u = top.second, kc = top.first;

        if (d[u] < kc) continue;

        for (auto it : ke[u]){
            int v = it.first, w = it.second;

            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++){
        if (d[i] == 1e9) cout << "-1" << ' ';
        else cout << d[i] << ' ';
    }
}

int main(){
    nhap();
    Dijkstra(s);

    return 0;
}