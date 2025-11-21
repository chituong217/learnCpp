#include <iostream>
#define MAX_LEN 100

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    int a[MAX_LEN][MAX_LEN];
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    for (int i=0; i < n; i++){
        for (int j = m-1; j>=0; j--){
            cout << a[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}