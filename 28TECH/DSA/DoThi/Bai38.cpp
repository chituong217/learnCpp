#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ca = 0;
vector<int> ke[1005];
bool visited[1005];
bool gian[1005];

void nhap(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int coGian;
        cin >> coGian;

        if (coGian == 1) gian[i] = true;
        else gian[i] = false; 
    }    

    for (int i = 1; i < n; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;
        ke[dau].push_back(cuoi);
        ke[cuoi].push_back(dau);
    }
}

void dfs(int u, int gianDaGap){
    if (gianDaGap > m) return;
    visited[u] = true;

    bool isLeaf = true;

    for (int v : ke[u]){
        if (visited[v] == false){
            if (gian[v] == true){
                dfs(v, gianDaGap + 1);
            }
            else{
                dfs(v, 0);
            }

            isLeaf = false;
        }
    }

    if (isLeaf){
        //cout << "NODE LA : " << u << endl;
        ca++;
    }
}

int main(){
    nhap();
    if (gian[1] == true) dfs(1, 1);
    else dfs(1, 0);
    cout << ca;

    return 0;
}