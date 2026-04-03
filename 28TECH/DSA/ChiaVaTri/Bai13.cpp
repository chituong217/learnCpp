#include <iostream>

using namespace std;

long long F[100];

void khoitao(){
    F[1] = 1;
    F[2] = 1;
    
    for (int i = 3; i <= 92; i++){
        F[i] = F[i - 1] + F[i - 2];
    }
}

int find(int n, long long k){
    if (n == 1){
        return 0;
    }
    if (n == 2){
        return 1;
    }

    if (k <= F[n - 2]){
        return find(n - 2, k);
    }
    else{
        return find(n - 1, k - F[n - 2]);
    }
}

int main(){
    int n;
    long long k;
    cin >> n >> k;

    khoitao();

    cout << find(n, k);

    return 0;
}