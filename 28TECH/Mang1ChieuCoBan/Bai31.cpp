#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000000
#define MOD 1000000007
using namespace std;


int a[MAX_LEN];
int b[MAX_LEN];
int c[MAX_LEN];

int main(){
    int n, m, p;
    cin >> n >> m >> p;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<m; i++){
        cin >> b[i];
    }

    int idx=0;
    for (int i=0; i<p; i++){
        c[idx] = a[i];
        idx++;
    }
    for (int i=0; i<m; i++){
        c[idx] = b[i];
        idx++;
    }
    for (int i=p; i<n; i++){
        c[idx] = a[i];
        idx++;
    }
    for (int i=0; i < idx; i++){
        cout << c[i] << ' ';
    }
    return 0;
}