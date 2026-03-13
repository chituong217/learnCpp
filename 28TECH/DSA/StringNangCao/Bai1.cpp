#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    int alphaNum = 0, digitNum = 0, specialNum = 0;

    for (int i = 0; i < (int)s.size(); i++){
        if (isalpha(s[i]) != 0){
            alphaNum++;
        }
        else if (isdigit(s[i]) != 0){
            digitNum++;
        }
        else{
            specialNum++;
        }
    }

    cout << alphaNum << ' ' << digitNum << ' ' << specialNum;

    return 0;
}
