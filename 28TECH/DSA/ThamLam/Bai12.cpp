#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;

    int resA = -1, resB = -1;
    for (int b = n/7; b >= 0; b--){
        int remain = n - 7 * b;
        if (remain % 4 == 0){
            resB = b;
            resA = remain / 4;
            break;
        }
    }

    if (resA == -1){
        cout << "-1";
    }
    else{
        for (int i = 0; i < resA; i++){
            cout << '4';
        }
        for (int i = 0; i < resB; i++){
            cout << '7';
        }
    }


    return 0;
}