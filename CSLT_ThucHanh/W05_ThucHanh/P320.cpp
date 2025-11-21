#include <iostream>
#include <iomanip>

#define MAX_LEN 100

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    double a[MAX_LEN][MAX_LEN];
    for (int i=0; i<m; i++){
        for (int j= 0; j<n; j++){
            cin >> a[i][j];
        }
    }
    double sum = 0.0;
    for (int i=0; i<m; i++){
        for (int j=0; j< n; j++){
            sum += a[i][j];
        }
    }
    cout << fixed << setprecision(2) << sum;
}