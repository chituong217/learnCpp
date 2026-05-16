#include <iostream>

using namespace std;

int n;
int s, t, u, v;
int a[1005][1005];
bool visited[1005][1005];


int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

void nhap(){
    cin >> n;
    cin >> s >> t >> u >> v;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
}



int main(){
    

    return 0;
}