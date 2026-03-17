#include <iostream>
#include <string>

using namespace std;
 
bool isBinaryDivisibleBy2PowerOfK(string s, int k){
    int n = s.size();

    if (k > n){
        return false;
    }

    for (int i = n - 1; i >= n - k; i--){
        if (s[i] == '1'){
            return false;
        }
    }

    return true;
}

int main(){
    string s;
    cin >> s;

    int k; cin >> k;

    if (isBinaryDivisibleBy2PowerOfK(s, k) == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}