#include <iostream>
#include <iomanip>

using namespace std;

bool check(int a[], int n, int k, double len){
    int cnt = 0;
    for (int i = 0; i < n; i++){
        cnt += (int)(a[i] / len);
    }

    return cnt >= k;
}

int main(){
    int n, k;
    cin >> n >> k;

    int a[n];

    double left = 1, right = 0;

    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > right){
            right = a[i];
        }
    }

    
    double ans = -1;
    for (int i = 0; i <= 80; i++){
        double mid = (left + right)/2.0;
        
        if (check(a, n, k, mid)){
            ans = mid;
            left = mid;
        }
        else{
            right = mid;
        }
    }

    cout << fixed << setprecision(6) << ans;

    return 0;
}