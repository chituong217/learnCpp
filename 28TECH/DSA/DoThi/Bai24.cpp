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

bool isLienThong(){
    DFS(1);
    for (int i = 1; i <= n; i++){
        if (visited[i] == false){
            return false;
        }
    }

    return true;
}

bool isTree(){
    int canh = 0;
    for (int i = 0; i <= n; i++){
        for (int u : ke[i]){
            canh++;
        }
    }

    canh /= 2;

    return (canh == n - 1) && isLienThong();
}

int main(){
    nhap();

    if (isTree()){
        cout << "1";
    }
    else{
        cout << "0";
    }

    return 0;
}