#include <iostream>

using namespace std;

int main(){
    int a[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

    long long n;
    cin >> n;

    long long cnt = 0;

    for (int i = 0; i < 10; i++){
        cnt += n / a[i];
        n %= a[i];
    }

    cout << cnt;

    return 0;
}