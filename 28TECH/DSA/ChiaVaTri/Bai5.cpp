#include <iostream>

using namespace std;

long long F[100];

void khoitaoFibo(){
    F[1] = 1;
    F[2] = 1;
    for (int i = 3; i <= 92; i++){
        F[i] = F[i - 1] + F[i - 2];
    }
}

char findFibo(int n, long long k){
    if (n == 1){
        return 'A';
    }
    if (n == 2){
        return 'B';
    }

    if (k <= F[n - 2]){
        return findFibo(n - 2, k);
    }
    else{
        return findFibo(n - 1, k - F[n - 2]);
    }
}


int main(){
    int n;
    long long k;
    cin >> n >> k;

    cout << findFibo(n, k);

    return 0;
}