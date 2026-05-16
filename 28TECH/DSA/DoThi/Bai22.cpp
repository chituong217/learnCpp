#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> ke[1005]; 
bool visited[1005];
int color[1005];

void nhap(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;

        ke[dau].push_back(cuoi);
    }
}

bool DFS(int u){
    color[u] = 1;

    for (int v : ke[u]){
        if (color[v] == 0){
            if (DFS(v) == true) return true;
        }
        else if (color[v] == 1){
            return true;
        }
    }

    color[u] = 2;
    return false;
}

int main(){
    nhap();

    bool ok = false;
    for (int i = 1; i <= n; i++){
        if (visited[i] == false){
            if (DFS(i) == true) ok = true;
        }
    }

    if (ok == true){
        cout << "1";
    }
    else{
        cout << "0";
    }

    return 0;
}