#include <iostream>

using namespace std;

// ta có thể tính a ^ b thông qua a ^ (b/2);
// nếu b chẵn thì a^b = a ^ (b/2) * a ^ (b/2);
// còn nếu b lẻ thì a^b = a ^ (b/2) * a ^ (b/2) * a;
long long binPow(long long a, long long b){
    if (b == 0){
        return 1;
    }

    // tinh a^(b/2)
    long long X = binPow(a, b/2);

    if (b % 2 == 0){
        return X * X;
    }
    else{
        return X * X * a;
    }
}

int main(){
    cout << binPow(2, 10);
    return 0;
}