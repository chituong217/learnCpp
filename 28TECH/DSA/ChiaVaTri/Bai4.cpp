#include <iostream>

using namespace std;

long long X[100];

void ktao(){
    X[1] = 1;
    for (int i = 2; i <= 50; i++){
        X[i] = 2 * X[i - 1] + 1;
    }
}

long long find(int n, long long k){
    if (n == 1){
        return 1;
    }

    if (k == X[n]/2 + 1){
        return n;
    }
    else if (k < X[n]/2 + 1){
        return find(n - 1, k);
    }
    else{
        return find(n - 1, k - (X[n]/2 + 1));
    }
}

int main(){
    int n;
    long long k;
    cin >> n >> k;

    ktao();

    cout << find(n, k);

    return 0;
}