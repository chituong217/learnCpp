#include <iostream>

using namespace std;

int n = 8;
int a[100][100], X[100], cot[100], cheo1[100], cheo2[100];
long long point = 0, maxPoint = 0;

void Try(int i){
    for (int j = 1; j <= n; j++){
        if (cot[j] == 0 && cheo1[n + i - j] == 0 && cheo2[i + j - 1] == 0){
            X[i] = j;
            point += a[i][j];

            cot[j] = 1;
            cheo1[n + i - j] = 1;
            cheo2[i + j - 1] = 1;

            if (i == n){
                maxPoint = max(point, maxPoint);
            }
            else{
                Try(i + 1);
            }

            point -= a[i][j];
            cot[j] = 0;
            cheo1[n + i - j] = 0;
            cheo2[i + j - 1] = 0;
        }
    }
}

int main(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    Try(1);
    cout << maxPoint;

    return 0;
}