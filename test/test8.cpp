#include <iostream>
using namespace std;

long long prime[10000000];

void sangsnt(long long prime[], int n){
    for(int i=0; i<=n; i++){
        prime[i] = 1;
    }
    prime[0] = 0;
    prime[1] = 0;
    for (int i=2; i<=n; i++){
        if (prime[i] == 1){
            for (int j = i*i; j<=n; j+=i){
                prime[j] = 0;
            }
        }
    }
}

int main(){
    int n, cnt=0;
    cin >> n;
    sangsnt(prime, n);
    for (int i=0; i<=n; i++){
        if (prime[i]){
            cnt++;
            cout << "#" << cnt << " = " << i << endl;
        }
    }
    cout << "There are " << cnt << " prime numbers.";
    return 0;
}