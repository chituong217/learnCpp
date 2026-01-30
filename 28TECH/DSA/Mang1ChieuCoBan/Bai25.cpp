#include <iostream>

using namespace std;

int main(){
    int cntEven = 0;
    int cntOdd = 0;
    int a[10001];
    int n = 0;
    while (cin >> a[n]){
        if (a[n] % 2 == 0){
            cntEven++;
        }
        else{
            cntOdd++;
        }
        n++;
    }

    if (cntEven > cntOdd){
        cout << "CHAN";
    }
    else if (cntEven == cntOdd){
        cout << "CHANLE";
    }
    else{
        cout << "LE";
    }

    return 0;
}