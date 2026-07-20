#include <iostream>
#define MAX_LEN 100

using namespace std;

int main(){
    int m, n, p;
    int a[MAX_LEN][MAX_LEN], b[MAX_LEN][MAX_LEN], c[MAX_LEN][MAX_LEN];
    cin >> m >> n >> p;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<p; j++){
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < m; i++){
        for (int j=0; j <p; j++){
            c[i][j] = 0;
            for (int k = 0; k < n; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (int i=0; i<m; i++){
        for (int j=0; j<p; j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}