#include <iostream>
#define MAX_LEN 100

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[MAX_LEN][MAX_LEN];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    int sum = 0;
    for (int i=0; i<n; i++){
        for (int j = i+1; j < n; j++){
            sum += a[i][j];
        }
    }
    cout << sum;
    return 0;
}