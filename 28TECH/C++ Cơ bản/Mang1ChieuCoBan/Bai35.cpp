#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000000
#define MOD 1000000007
using namespace std;


int a[MAX_LEN];
int b[MAX_LEN];


int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<n-1; i++){
        cin >> b[i];
    }
    int sum = a[0];
    for (int i=0; i<n-1; i++){
        if (b[i] == 1){
            sum += a[i+1];
        }
        else{
            sum -= a[i+1];
        }
    }
    cout << sum;
    return 0;
}