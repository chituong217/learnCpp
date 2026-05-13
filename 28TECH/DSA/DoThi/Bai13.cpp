#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ke[1005];
bool visited[1005];

void DFS(int u){
    visited[u] = true;

    for (int x : ke[u]){
        if (visited[x] == false){
            DFS(x);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;
        ke[dau].push_back(cuoi);
        ke[cuoi].puh_back(dau);
    }

    for (int i = 1; i <= n; i++){
        sort(ke[i].begin(), ke[i].end());
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (visited[i] == false){
            DFS(i);
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}