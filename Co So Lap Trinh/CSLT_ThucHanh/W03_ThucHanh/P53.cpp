#include <iostream>
using namespace std;

long long countMax(int n){
    int cnt = 0;
    int max = -1e9;
    while (n){
        if (n%10 > max){
            max = n%10;
            cnt =1;
        }
        else if (n%10 == max){
            cnt++;
        }
        n/=10;
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    cout << countMax(n);
    return 0;
}