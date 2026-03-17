#include <iostream>
#include <string>

using namespace std;

long long moduleBy(string n, long long m){
    long long res = 0;

    for (int i = 0; i < (int)n.size(); i++){
        res *= 10;
        res += n[i] - '0';
        res %= m;
    }

    return res;
}

int main(){
    string n;
    long long m;
    cin >> n >> m;

    cout << moduleBy(n, m);

    return 0;
}