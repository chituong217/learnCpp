#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solveStack(string s){
    stack<char> st;

    int cnt = 0;

    for (int i = 0; i < (int)s.size(); i++){
        if (s[i] == ')'){
            if (st.empty() == true){
                cnt++;
            }
            else{
                st.pop();
            }
        }
        else{
            st.push(s[i]);
        }
    }

    return st.size() + cnt;
}

int main(){
    string s;
    cin >> s;
    
    cout << solveStack(s);

    return 0;
}