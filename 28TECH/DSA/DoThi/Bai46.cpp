#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int a[505][505];
vector<pair<int,int>> ke[505 * 505]; // luu 2 dinh va trong so
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void nhap(){
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    int dem = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dem++;
            int duoi = dem - m, tren = dem + m, trai = dem - 1, phai = dem + 1;
            
            if (i - 1 >= 1){
                ke[dem].push_back({duoi, a[i - 1][j]});
            }
            if (i + 1 <= n){
                ke[dem].push_back({tren, a[i + 1][j]});
            }
            if (j - 1 >= 1){
                ke[dem].push_back({trai, a[i][j - 1]});
            }
            if (j + 1 <= m){
                ke[dem].push_back({phai, a[i][j + 1]});
            }
        }
    }
}

void Dijkstra(int s){
    vector<int> d(m * n + 1, 1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;

    d[s] = a[1][1];
    Q.push({d[s], s});
    while (!Q.empty()){
        pair<int,int> top = Q.top();
        Q.pop();

        int u = top.second, kc = top.first;

        if (d[u] < kc) continue;

        for (auto it : ke[u]){
            int v = it.first;
            int w = it.second;

            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }

    cout << d[m * n];
}

int main(){
    nhap();
    Dijkstra(1);
    
    return 0;
}