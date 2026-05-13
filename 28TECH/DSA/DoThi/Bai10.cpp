#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ke[1005];
bool visited[1005];

void DFS(int u){
    cout << u << ' ';
    visited[u] = true;

    for (int x : ke[u]){
        if (visited[x] == false){
            DFS(x);
        }
    }
}

int main(){
    int n, m, s;
    cin >> n >> m >> s;

    for (int i = 1; i <= m; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;
        ke[dau].push_back(cuoi);
    }

    for (int i = 1; i <= n; i++){
        sort(ke[i].begin(), ke[i].end());
    }

    DFS(s);

    return 0;
}