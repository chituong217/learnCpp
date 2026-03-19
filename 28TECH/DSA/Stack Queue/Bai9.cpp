#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isToanTu(char s){
    if (s == '+' || s == '-' || s == '*' || s == '/'){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s;
    cin >> s;

    stack<string> Q;
    for (int i = s.size() - 1; i >= 0; i--){
        if (isToanTu(s[i]) == false){
            string tmp;
            tmp = s[i];
            Q.push(tmp);
        }
        else{
            string a = Q.top();
            Q.pop();
            string b = Q.top();
            Q.pop();

            string tmp = '(' + a + s[i] + b + ')';
            Q.push(tmp);
        }
    }

    cout << Q.top();

    return 0;
}