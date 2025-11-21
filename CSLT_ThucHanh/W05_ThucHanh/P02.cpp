#include <iostream>
#include <iomanip>

using namespace std;

#define MAX_LEN 100

int main(){
    int n;
    cin >> n;
    int a[MAX_LEN];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    double tbc = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (a[i]%2 == 0){
            tbc += a[i];
            cnt++;
        }
    }
    tbc /= cnt;
    cout << fixed << setprecision(2) << tbc;
    return 0;
}