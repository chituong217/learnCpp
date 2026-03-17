#include <iostream>
#include <string>

using namespace std;

bool isDivisibleBy3(string s){
    if (s.size() == 0){
        return false;
    }

    int sum = 0;
    for (int i = 0; i < (int)s.size(); i++){
        sum += (int)(s[i] - '0');
    }

    return sum % 3 == 0;
}

bool isDivisibleBy5(string s){
    if (s.size() == 0){
        return false;
    }

    int n = s.size();
    if (s[n - 1] == '5' || s[n - 1] == '0'){
        return true;
    }
    else{
        return false;
    }
}

bool isDivisibleBy15(string s){
    if (isDivisibleBy3(s) == true && isDivisibleBy5(s) == true){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s;
    cin >> s;

    if (isDivisibleBy15(s) == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}