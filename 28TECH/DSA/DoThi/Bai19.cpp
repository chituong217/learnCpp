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
        ke[cuoi].push_back(dau);
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

int demTPLT(){
    int dem = 0;
    for (int i = 1; i <= n; i++){
        if (visited[i] == false){
            dem++;
            DFS(i);
        }
    }

    return dem;
}

void clearVisited(){
    for (int i = 1; i <= n; i++){
        visited[i] = false;
    }
}

int main(){
    nhap();
    int soTPLTBanDau = demTPLT();

    int cntDinhTru = 0;
    for (int i = 1; i <= n; i++){
        clearVisited();
        visited[i] = true;
        int soTPLTBayGio = demTPLT();
        if (soTPLTBanDau < soTPLTBayGio){
            cntDinhTru++;
        }
    }

    cout << cntDinhTru;

    return 0;
}