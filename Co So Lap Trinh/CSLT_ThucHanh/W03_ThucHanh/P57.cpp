#include <iostream>
using namespace std;

long long checkRev(long long n){
    long long tmp = n;
    long long res = 0;
    while(n){
        res = res*10 + n%10;
        n/=10;
    }
    return res == tmp;
}

int main(){
    long long n;
    cin >> n;
    if (checkRev(n) == 1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}