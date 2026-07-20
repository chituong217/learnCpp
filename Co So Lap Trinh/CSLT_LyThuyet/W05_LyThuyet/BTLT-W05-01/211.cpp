#include <iostream>
#include <cmath>
using namespace std;

int snt(int a){
    for (int i=2; i<=sqrt(a); i++){
        if (a%i==0){
            return 0;
        }
    }
    return a>1;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    double tbc = 0;
    int cnt=0;
    for (int i=0; i<n; i++){
        if (snt(a[i])){
            tbc += a[i];
            cnt++;
        }
    }
    tbc /= cnt;
    cout << tbc;
    return 0;
}