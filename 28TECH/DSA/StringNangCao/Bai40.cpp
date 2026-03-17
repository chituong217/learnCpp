#include <string>
#include <iostream>

using namespace std;

bool isBinaryDivisibleBy5(string s){
    int sum = 0;
    for (int i = 0; i < (int)s.size(); i++){
        sum = sum * 2 + (s[i] - '0');
        sum %= 5;
    }

    return sum == 0;
}

int main(){
    string s;
    cin >> s;

    if (isBinaryDivisibleBy5(s) == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}