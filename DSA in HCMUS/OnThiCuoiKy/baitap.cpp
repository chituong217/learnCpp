#include  <bits/stdc++.h>

using namespace std;

// 1. Khai báo danh sách kề ở hàm main hoặc qua struct tùy bạn.
vector<int> ads[1005];
vector<bool> visited[1005];
// 2. Trả về số lượng thành phần liên thông
void dfs(int u){
    visited[u] = true;
    
    for (int v : adj[u]){
        if (visited[v] == false){
            dfs(v);
        }
    }
}

int countConnectedComponents(int numV, const vector<int> adj[]){
    int count = 0;
    for (int i = 0; i < numV; i++){
        if (visited[i] == false){
            count++;
            dfs(i);
        }
    }

    return count;
}

// 3. Trả về true nếu đồ thị có chu trình, ngược lại trả về false
bool checkChuTrinh(int u, int parent, const vector<int> adj[]){
    visited[u] = true;

    for (int v : adj[u]){
        if (visited[v] == true){
            if (parent != v) return true;
        }
        else{
            if (checkChuTrinh(v, u, adj)) return true;
        }
    }

    return false;
}

bool hasCycle(int numV, const vector<int> adj[]){
    for (int i = 0; i < numV; i++){
        if (visited[i] == false){
            if (checkChuTrinh(i, -1, adj)) return true;
        }
    }

    return false;
}

int main(){

    return 0;
}