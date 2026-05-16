#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> ke[1005];
int visited[1005];
pair<int,int> dinhMax = {-1,-1};
vector<int> nhomtruong;

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
    if (dinhMax.second < (int)ke[u].size()){
        dinhMax.first = u;
        dinhMax.second = ke[u].size();
    }
    else if (dinhMax.second == (int)ke[u].size()){
        if (dinhMax.first > u){
            dinhMax.first = u;
        }
    }

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

int demTPLT(){
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (visited[i] == false){
            DFS(i);
            nhomtruong.push_back(dinhMax.first);

            dinhMax = {-1,-1};
        }
    }

    return cnt;
}



int main(){
    nhap();
    demTPLT();

    sort(nhomtruong.begin(), nhomtruong.end());

    for (int x : nhomtruong){
        cout << x << ' ';
    }

    return 0;
}