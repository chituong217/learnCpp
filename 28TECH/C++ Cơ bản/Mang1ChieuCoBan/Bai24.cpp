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
    int k; cin >> k;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i <= n-k; i++){
        int sum = 0;
        for (int j = i; j < i + k; j++){
            sum += a[j];
        }
        cout << sum << ' ';
    }
    return 0;
}