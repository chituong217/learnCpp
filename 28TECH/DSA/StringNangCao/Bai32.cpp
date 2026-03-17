#include <iostream>
#include <string>

using namespace std;

bool isPrime(int n){
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            return false;
        }
    }

    return n > 1;
}

int main(int argc, char** argv){
    string s;
    cin >> s;

    bool ok = true;
    for (int i = 0; i < (int)s.size(); i++){
        if (isPrime(s[i] - '0') == false){
            ok = false;
            break;
        }
    }

    int sum = 0;
    for (int i = 0; i < (int)s.size(); i++){
        sum += s[i] - '0';
    }

    if (isPrime(sum) == false){
        ok = false;
    }

    if (ok == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}