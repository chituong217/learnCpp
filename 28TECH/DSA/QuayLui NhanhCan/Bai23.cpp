#include <iostream>


using namespace std;

int snt[10000007];

int n, k;
int X[100];
int prime[200], nPrime = 0;

int sum = 0, found = 0;

void sang(){
    for (int i = 0; i <= n; i++){
        snt[i] = 1;
    }

    snt[0] = snt[1] = 0;
    
    for (int i = 2; i*i <= n; i++){
        if (snt[i] == 1){
            for (int j = i * i; j <= n; j += i){
                snt[j] = 0;
            }
        }
    }
}

void Try(int i, int pos){
    for (int j = pos; j < nPrime; j++){
        X[i] = prime[j];
        sum += prime[j];

        if (i == k){
            if (sum == n){
                found = 1;
                for (int l = 1; l <= k; l++){
                    cout << X[l];
                    if (l != k){
                        cout << " + ";
                    }
                }
                cout << '\n';
            }
        }
        else{
            if (sum < n){
                Try(i + 1, j + 1);
            }
        }

        sum -= prime[j];
    }
}

int main(){
    cin >> n >> k;
    sang();

    for (int i = 0; i <= n; i++){
        if (snt[i] == 1){
            prime[nPrime] = i;
            nPrime++;
        }
    }

    Try(1, 0);

    if (found == false){
        cout << "NOT FOUND";
    }

    return 0;
};