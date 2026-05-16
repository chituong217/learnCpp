#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> ke[1005];
bool visited[1005];
int n, m;

void nhap(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;

        ke[dau].push_back(cuoi);
        ke[cuoi].push_back(dau);
    }
}

void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(q.empty() == false){
        int v = q.front();
        q.pop();

        cout << v << ' ';

        for (int x : ke[v]){
            if (visited[x] == false){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main(){
    nhap();
    BFS(1);

    return 0;
}