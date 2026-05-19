#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<int> ke[1005];
bool visited[1005];
int bbv[1005];

void nhap(){
    cin >> n >> m;

    for (int i = 1; i <= m; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;

        ke[dau].push_back(cuoi);
        bbv[cuoi]++;
    }
}

void BFS(){
    queue<int> q;
    vector<int> topo;

    for (int i = 1; i <= n; i++){
        if (bbv[i] == 0){
            q.push(i);
        }
    }
    
    while (q.empty() == false){
        int u = q.front(); q.pop();
        topo.push_back(u);

        for (int x : ke[u]){
            bbv[x]--;
            if (bbv[x] == 0){
                q.push(x);
            }
        }
    }

    if ((int)topo.size() < n){
        cout << "1";
    }
    else{
        cout << "0";
    }
}

int main(){
    nhap();
    BFS();

    return 0;
}