#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> ke[1005];
bool visited[1005];

void nhap(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;

        ke[dau].push_back(cuoi);
    }
}

void DFS(int u){
    visited[u] = true;

    for (int v : ke[u]){
        if (visited[v] == false){
            DFS(v);
        }
    }
}

void clearVisited(){
    for (int i = 1; i <= n; i++){
        visited[i] = false;
    }
}

bool kiemtraLienThong(int u){
    clearVisited();
    DFS(u);
    for (int i = 1; i <= n; i++){
        if (visited[i] == false) return false;
    }

    return true;
}

bool kiemtraLienThongManh(){
    for (int i = 1; i <= n; i++){
        if (kiemtraLienThong(i) == false) return false;
    }

    return true;
}

int main(){
    nhap();

    if (kiemtraLienThongManh()){
        cout << "1";
    }
    else{
        cout << "0";
    }

    return 0;
}