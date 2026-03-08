#include <iostream>

using namespace std;

int sang[1000005];

int main(){
    sang[0] = 0;
    sang[1] = 0;

    for (int i = 2; i <= 1000000; i++){
        sang[i] = 1;
    }

    for (int i = 2; i*i <= 1000000; i++){
        if (sang[i] == 1){
            for (int j = i * i; j <= 1000000; j += i){
                sang[j] = 0;
            }
        }
    }

    for (int i = 2; i <= 1000000; i++){
        sang[i] += sang[i - 1];
    }
    
    int q;
    cin >> q;

    while(q--){
        int left, right;
        cin >> left >> right;

        if (left == 0){
            cout << sang[right] << "\n";
        }
        else{
            cout << sang[right] - sang[left - 1] << "\n";
        }
    }

    return 0;
}