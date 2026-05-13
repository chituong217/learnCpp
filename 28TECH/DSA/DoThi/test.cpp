#include <iostream>
#include <vector>

using namespace std;

vector<int> ke[1001]; // ds ke
int a[1001][1001]; // mtran ke
vector<pair<int,int>> dscanh;

int n, m;
bool visited[1001];

// DFS bang danh sach ke
void DFS1(int u){
    cout << u << ' ';

    visited[u] = true;

    // duyet danh sach ke cua dinh u
    for (int v : ke[u]){
        if (visited[v] == false){
            DFS1(v);
        }
    }
}

// DFS bang ma tran ke
void DFS2(int u){
    cout << u << ' ';
    visited[u] = true;

    for (int v = 1; v <= n; v++){
        if (a[u][v] == 1){
            if (visited[v] == false){
                DSF2(v);
            }
        }
    }
}

// DFS bang danh sach canh
void DFS3(int u){
    cout << u << ' ';
    visited[u] = true;

    for (auto it : dscanh){
        if (it.first == u){
            if (visited[it.second] == false){
                DFS3(it.second);
            }
        }
        if (it.second == u){
            if (visited[it.first] == false){
                DFS3(it.first);
            }
        }
    }
}

int main(){


    return 0;
}