#include <iostream>

using namespace std;

int totien[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

int main(){
    int n;
    cin >> n;

    int cnt = 0;

    for (int i = 0; i < 10; i++){
        if (n > 0){
            cnt += (n / totien[i]);
            n %= totien[i];
        }
    }

    cout << cnt;

    return 0;
}