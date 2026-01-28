#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000000
#define MOD 1000000007
using namespace std;


int a[MAX_LEN];

int main(){
    int idx = 0, cntEven = 0, cntOdd = 0;
    while (cin >> a[idx]){
        if (a[idx] % 2 == 0){
            cntEven++;
        }
        else{
            cntOdd++;
        }
        idx++;
    }
    if (cntEven > cntOdd){
        cout << "CHAN";
    }
    else if (cntEven < cntOdd){
        cout << "LE";
    }
    else{
        cout << "CHANLE";
    }
    
    return 0;
}