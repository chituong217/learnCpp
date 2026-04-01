#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int cntEven = 0, cntOdd = 0;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] % 2 == 0){
            cntEven++;
        }
        else{
            cntOdd++;
        }
    }

    if (cntEven % 2 == 0 && cntOdd % 2 == 0){
        cout << "YES";
        return 0;
    }
    
    sort(a, a + n);

    for (int i = 1; i < n; i++){
        if (abs(a[i] - a[i - 1]) == 1){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}