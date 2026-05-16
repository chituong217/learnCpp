#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> ke[1005];
vector<pair<int,int>> canh;
bool visited[1005];

void nhap(){
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;

        ke[dau].push_back(cuoi);
        ke[cuoi].push_back(dau);
        canh.push_back({dau, cuoi});
    }
}

void DFS(int u, int s, int t){
    visited[u] = true;

    for (int v : ke[u]){
        if ((u == s && v == t) || (u == t && v == s)){
            continue;
        }
        if (visited[v] == false){
            DFS(v, s, t);
        }
    }
}

void clearVisited(){
    for (int i = 1; i <= n; i++){
        visited[i] = false;
    }
}

int demTPLT(int s, int t){
    clearVisited();
    
    int dem = 0;
    for (int i = 1; i <= n; i++){
        if (visited[i] == false){
            dem++;
            DFS(i, s, t);
        }
    }

    return dem;
}

int demCanhCau(){
    int cnt = 0;

    int tpltBanDau = demTPLT(0, 0);
    for (auto it : canh){
        int dau = it.first, cuoi = it.second;
        int tpltBayGio = demTPLT(dau, cuoi);

        if (tpltBanDau < tpltBayGio){
            cnt++;
        }
    }

    return cnt;
}

int main(){
    nhap();
    cout << demCanhCau();


    return 0;
}