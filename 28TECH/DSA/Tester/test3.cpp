#include <iostream>
#include <cmath>
#include <vector>

bool prime[1000001];

void sang(int n){
    for (int i = 0; i <= n; i++){
        prime[i] = true;
    }
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i <= sqrt(n); i++){
        if (prime[i] == true){
            // loại bỏ các bội của i <= n
            for (int j = i*i; j <= n; j += i){
                prime[j] = false;
            }
        }
    }
}



using namespace std;

int main(){

    return 0;
}