#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tmp;
    int cntOdd = 0, cntEven = 0;

    while (cin >> tmp){
        if (tmp % 2 == 0){
            cntEven++;
        }
        else{
            cntOdd++;
        }
    }

    bool ok = false;
    if ((cntOdd + cntEven) % 2 == 0){
        if (cntEven > cntOdd){
            ok = true;
        }
    }
    else{
        if (cntOdd > cntEven){
            ok = true;
        }
    }

    if (ok){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}