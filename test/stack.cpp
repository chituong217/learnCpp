#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    stack <char> st;
    int len = s.size();
    bool hople = true;
    for (int i = 0; i < len; i++){
        if (s[i] == '('){
            st.push(s[i]);
        }
        else{
            if (st.empty()){
                hople = false;
                break;
            }
            else{
                st.pop();
            }
        }
    }
    if (st.empty() == false){
        hople = false;
    }
    
    if (hople){
        cout << "Hop le !" << endl;
    }
    else{
        cout << "Khong hop le !" << endl;
    }
    return 0;
}