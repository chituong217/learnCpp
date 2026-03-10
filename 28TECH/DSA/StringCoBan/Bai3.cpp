#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    long long sum = 0;

    for (int i = 0; i < (int)s.size(); i++){
        if (isdigit(s[i])){
            sum += s[i] - '0';
        }
    }

    cout << sum;

    return 0;
}