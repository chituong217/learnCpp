#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[1005];
vector<int> ke[1005];

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
        
        cout << v << ' ';
        for (int x : ke[v]){
            if (visited[x] == false){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main(){
    int n, m, s;
    cin >> n >> m >> s;
    nhap(m);

    for (int i = 1; i <= n; i++){
        sort(ke[i].begin(), ke[i].end());
    }
    
    BFS(s);

    return 0;
}