#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> ke[1005];
int visited[1005];
vector<int> lthong;

void DFS(int u){
    visited[u] = true;

    for (int v : ke[u]){
        if (visited[v] == false){
            DFS(v);
        }
    }
}

// void clearVisited(){
//     for (int i = 1; i <= n; i++){
//         visited[i] = false;
//     }
// }

void demTPLT(){
    for (int i = 1; i <= n; i++){
        if (visited[i] == false){
            DFS(i);
            lthong.push_back(i);
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;

        ke[dau].push_back(cuoi);
        ke[cuoi].push_back(dau);
    }

    demTPLT();
    cout << lthong.size() - 1 << endl;
    for (int i = 0; i < (int)(lthong.size() - 1); i++){
        cout << lthong[i] << ' ' << lthong[i + 1] << '\n';
    }

    return 0;
}