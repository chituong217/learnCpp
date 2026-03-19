#include <iostream>
#include <string>
#include <stack>

using namespace std;

int calPriority(char a){
    if (a == '+' || a == '-'){
        return 1;
    }
    else if (a == '*' || a == '/'){
        return 2;
    }
    return 0;
}

int main(){
    string s;
    cin >> s;

    stack<char> st;
    string res = "";

    for (int i = 0; i < (int)s.size(); i++){
        if (isalpha(s[i]) == true){
            res += s[i];
        }
        else if (s[i] == '('){
            st.push(s[i]);
        }
        else if (s[i] == ')'){
            while (st.empty() == false && st.top() != '('){
                res += st.top();
                st.pop();
            }
            if (st.empty() == false && st.top() == '('){
                st.pop();
            }
        }
        else{
            while(st.empty() == false && calPriority(st.top()) >= calPriority(s[i])){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (st.empty() == false){
        if (st.top() != '('){
            res += st.top();
        }
        st.pop();
    }

    cout << res;

    return 0;
}