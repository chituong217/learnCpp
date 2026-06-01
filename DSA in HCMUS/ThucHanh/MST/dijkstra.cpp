#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int,int>> ke[100005];
int parent[100005];

void nhap(){
    cin >> n >> m;
    
    for (int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;

        ke[x].push_back({y, w});
        ke[y].push_back({x, w});
    }
}

void Dijkstra(int s){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<long long> d(n + 1, 1e18);

    d[s] = 0;
    q.push({0, s});

    while (q.empty() == false){
        auto top = q.top();
        q.pop();
        int u = top.second, kc = top.first;

        if (kc > d[u]) continue;

        for (auto it : ke[u]){
            int v = it.first, w = it.second;

            if (d[v] > d[u] + w){
                parent[v] = u;
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    nhap();
    Dijkstra(1);

    vector<int> path;

    int i = n;
    while (parent[i] != 0){
        path.push_back(i);
        i = parent[i];
    }
    path.push_back(i);

    if (i != 1){
        cout << "-1";
    }
    else{
        reverse(path.begin(), path.end());
        for (int x : path){
            cout << x << ' ';
        }
    }

    return 0;
}