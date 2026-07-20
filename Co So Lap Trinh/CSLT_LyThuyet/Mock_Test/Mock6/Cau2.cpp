#include <iostream>

using namespace std;

int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1}; 

void generateMinesweeperMap(int a[][100], int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            // do min
            if (a[i][j] == 0){
                int cnt = 0;
                for (int k = 0; k < 8; k++){
                    int i1 = i + dx[k];
                    int j1 = j + dy[k];
                    if (i1 >= 0 && j1 >= 0 && i1 < m && j1 < n && a[i1][j1] == -1){
                        cnt++;
                    }
                }
                a[i][j] = cnt;
            }
        }
    }
}
