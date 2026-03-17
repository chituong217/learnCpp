#include <iostream>
#include <stack>

using namespace std;

int main(){
    string s;
    cin >> s;

    bool ok = true;

    stack<char> st;
    for (int i = 0; i < (int)s.size(); i++){
        if (s[i] == '('){
            st.push(s[i]);
        }
        else{
            if (st.empty() == true){
                ok = false;
                break;
            }
            else{
                st.pop();
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