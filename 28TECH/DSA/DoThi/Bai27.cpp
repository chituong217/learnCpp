#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int cnt = 0;
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
    cnt++;
    visited[u] = true;

    for (int v : ke[u]){
        if (visited[v] == false){
            DFS(v);
        }
    }
}

int demSoLuongTPLTNhieuPhanTuNhat(){
    int maxNum = 0;
    for (int i = 1; i <= n; i++){
        if (visited[i] == false){
            DFS(i);
            maxNum = max(maxNum, cnt);
            
            cnt = 0;
        }
    }

    return maxNum;
}

int main(){
    nhap();
    cout << demSoLuongTPLTNhieuPhanTuNhat();

    return 0;
}