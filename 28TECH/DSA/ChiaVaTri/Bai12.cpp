#include <iostream>
#define ll long long 

using namespace std;

struct Matrix{
    ll f[2][2];
};

ll mod = 1e9 + 7;

Matrix operator * (Matrix a, Matrix b){
    Matrix c;
    
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            c.f[i][j] = 0;
            for (int k = 0; k < 2; k++){
                c.f[i][j] += (a.f[i][k] * b.f[k][j]) % mod;
                c.f[i][j] %= mod;
            }
        }
    }

    return c;
}

Matrix powMod(Matrix a, int n){
    if (n == 1) return a;

    Matrix X = powMod(a, n / 2);
    if (n % 2 == 0){
        return X * X;
    }
    else{
        return X * X * a;
    }
}

int main(){
    int n; cin >> n;

    Matrix a;
    a.f[0][0] = a.f[0][1] = a.f[1][0] = 1;
    a.f[1][1] = 0;

    Matrix res = powMod(a, n);
    cout << res.f[1][0];

    return 0;
}