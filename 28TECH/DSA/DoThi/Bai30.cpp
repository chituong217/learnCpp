#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct o{
    int i, j, buoc;
};

int n;
int s, t, u, v;
int a[1005][1005];

int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};

void nhap(){
    cin >> n;
    cin >> s >> t >> u >> v;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
}

int bfs(){
    if (s == u && t == v) return 0;
    queue<o> q;
    q.push({s, t, 0});
    a[s][t] = 0;

    while (q.empty() == false){
        auto it = q.front(); q.pop();
        int i = it.i, j = it.j, buoc = it.buoc;

        for (int k = 0; k < 8; k++){
            int i1 = i + dx[k];
            int j1 = j + dy[k];

            if (i1 > 0 && j1 > 0 && i1 <= n && j1 <= n && a[i1][j1] == 1){
                if (i1 == u && j1 == v) return buoc + 1;
                q.push({i1, j1, buoc + 1});
                a[i1][j1] = 0;
            }
        }
    }

    return -1;
}

int main(){
    nhap();
    cout << bfs();

    return 0;
}