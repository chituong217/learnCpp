#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;

    stack<char> st;

    int cntLoi = 0;
    for (int i = 0; i < (int)s.size(); i++){
        if (s[i] == '('){
            st.push(s[i]);
        }
        else{
            if (st.size() == 0){
                cntLoi++;
            }
            else{
                st.pop();
            }
        }
    }

    cout << cntLoi;

    return 0;
}