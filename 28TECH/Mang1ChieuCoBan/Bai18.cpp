#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000000
#define MOD 1000000007
using namespace std;


long long a[MAX_LEN];


int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=0; i<n; i++){
        if (i == 0){
            if (a[i] * a[i+1] < 0){
                cout << a[i] << ' ';
            }
        }
        else if (i == n-1){
            if (a[i] * a[i-1] < 0){
                cout << a[i] << ' ';
            }
        }
        else{
            if (a[i] * a[i+1] < 0 || a[i] * a[i-1] < 0){
                cout << a[i] << ' ';
            }
        }
    }
    return 0;
}