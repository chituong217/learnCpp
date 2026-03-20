#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s;
    cin >> s;

    vector<char> st;

    for (int i = 0; i < (int)s.size(); i++){
        if (st.empty() == false && st.back() == s[i]){
            st.pop_back();
        }
        else{
            st.push_back(s[i]);
        }
    }

    if (st.empty() == true){
        cout << "Yes";
    }
    else{
        cout << "No";
    }

    return 0;
}