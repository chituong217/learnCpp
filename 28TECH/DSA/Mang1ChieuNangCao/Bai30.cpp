#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);

    int sobe;
    if (k > n - k){
        sobe = n - k;
    }
    else{
        sobe = k;
    }

    long long tongBe = 0, tongLon = 0;
    for (int i = 0; i < sobe; i++){
        tongBe += a[i];
    }
    for (int i = sobe; i < n; i++){
        tongLon += a[i];
    }

    cout << tongLon - tongBe;

    return 0;
}