#include <iostream>
#include <string>

using namespace std;

bool isDivisibleBy2(string s){
    int n = s.size();

    if (n == 0){
        return false;
    }

    if ((int)(s[n - 1] - '0') % 2 == 0){
        return true;
    }
    else{
        return false;
    }
}

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

bool isDivisibleBy6(string s){
    if (isDivisibleBy2(s) == true && isDivisibleBy3(s) == true){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s;
    cin >> s;

    if (isDivisibleBy6(s) == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}