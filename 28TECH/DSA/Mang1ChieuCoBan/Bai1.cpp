#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cntEven = 0, cntOdd = 0, sumEven = 0, sumOdd = 0;

    for (int i = 0; i < n; i++){
        if (a[i] % 2 == 0){
            cntEven++;
            sumEven += a[i];
        }   
        else{
            cntOdd++;
            sumOdd += a[i];
        }
    }

    cout << cntEven << endl;
    cout << cntOdd << endl;
    cout << sumEven << endl;
    cout << sumOdd << endl;

    return 0;
}