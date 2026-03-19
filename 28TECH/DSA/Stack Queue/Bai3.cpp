#include <iostream>
#include <stack>

using namespace std;

int main(){
    string s;
    cin >> s;

    stack<char> st;

    bool ok = true;

    for (int i = 0; i < (int)s.size(); i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }
        else{
            if (st.empty() == true){
                ok = false;
                break;
            }

            char top = st.top();
            st.pop();

            if (s[i] == ')' && top != '('){
                ok = false;
                break;
            }
            if (s[i] == ']' && top != '['){
                ok = false;
                break;
            }
            if (s[i] == '}' && top != '{'){
                ok = false;
                break;
            }
        }
    }

    if (st.empty() == false){
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