#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000000
#define MOD 1000000007
using namespace std;


int a[MAX_LEN];

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int max = -1e9;
    int idx = -1;
    for (int i=0; i<n; i++){
        if (a[i] > max){
            max = a[i];
            idx = i;
        }
    }
    int max2 = -1e9;
    for (int i=0; i<n; i++){
        if (a[i] > max2 && i != idx){
            max2 = a[i];
        }
    }
    cout << max << ' ' << max2;
    return 0;
}