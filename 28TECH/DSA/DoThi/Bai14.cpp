#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ke[1005];
bool visited[1005];
bool check = false;
int parent[1005];

void findPathByDFS(int current, int target){
    visited[current] = true;
    if (current == target){
        check = true;
        return;
    }

    for (int x : ke[current]){
        if (visited[x] == false){
            parent[x] = current;

            findPathByDFS(x, target);

            if (check == true) return;
        }
    }
}

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    for (int i = 1; i <= m; i++){
        int dau, cuoi;
        cin >> dau >> cuoi;

        ke[dau].push_back(cuoi);
        ke[cuoi].push_back(dau);
    }

    for (int i = 1; i <= n; i++){
        sort(ke[i].begin(), ke[i].end());
    }

    findPathByDFS(s, t);

    if (check == false){
        cout << "-1";
    }
    else{
        vector<int> path;
        int current = t;
        while (parent[current] != 0){
            path.push_back(current);
            current = parent[current];
        }
        path.push_back(current);
        reverse(path.begin(), path.end());
        
        for (int x : path){
            cout << x << ' ';
        }
    }

    return 0;
}