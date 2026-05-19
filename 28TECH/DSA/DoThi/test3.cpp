#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n, m;
vector<int> ke[1005], t_ke[1005];
bool visited[1005];
stack<int> topo;

void nhap(){
    cin >> n >> m;

    for (int i = 1; i <= m; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;

        ke[dau].push_back(cuoi);
        t_ke[cuoi].push_back(dau);
    }
}

void clearVisited(){
    for (int i = 1; i <= n; i++){
        visited[i] = false;
    }
}

void DFS1(int u){
    visited[u] = true;

    for (int v : ke[u]){
        if (visited[v] == false){
            DFS1(v);
        }
    }

    topo.push(u);
}

void DFS2(int u){
    cout << u << ' ';
    visited[u] = true;

    for (int v : ke[u]){
        if (visited[v] == false){
            DFS2(v);
        }
    }
    
}

void kosaraju(){
    for (int i = 1; i <= n; i++){
        if (visited[i] == false) DFS1(i);
    }

    clearVisited();
    int soTPLTmanh = 0;

    while (topo.empty() == false){
        int u = topo.top(); topo.pop();
        if (visited[u] == false){
            soTPLTmanh++;
            DFS2(u);
            cout << '\n';
        }
    }
    cout << soTPLTmanh << endl;
}

int main(){
    nhap();
    kosaraju();

    return 0;
}