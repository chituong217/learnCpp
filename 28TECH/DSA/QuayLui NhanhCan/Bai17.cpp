#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n;
string s = "";
vector<string> result;
stack<char> st;

char mongoac[3] = {'(', '[', '{'};
char dongngoac[3] = {')', ']', '}'};

void Try(int i){
    // dieu kien stop
    if (i == n){
        if (st.empty() == true){
            result.push_back(s);
        }
        return;
    }

    // thu mo ngoac
    for (int j = 0; j < 3; j++){
        if (i <= n && (int)st.size() < (n / 2)){
            s += mongoac[j];
            st.push(mongoac[j]);

            Try(i + 1);

            s.pop_back();
            st.pop();
        }
    }

    // thu dong ngoan
    for (int j = 0; j < 3; j++){
        if (st.empty() == false){
            bool coXoa = false;
            char top = st.top();

            if (dongngoac[j] == ')' && top == '('){
                st.pop();
                s += dongngoac[j];
                coXoa = true;
            }
            if (dongngoac[j] == ']' && top == '['){
                st.pop();
                s += dongngoac[j];
                coXoa = true;
            }
            if (dongngoac[j] == '}' && top == '{'){
                st.pop();
                s += dongngoac[j];
                coXoa = true;
            }

            if (coXoa){
                Try(i + 1);

                s.pop_back();
                st.push(top);
            }
        }
    }
}

int main(){
    cin >> n;

    if (n % 2 != 0){
        cout << "NOT FOUND";
    }
    else{
        Try(0);
        sort(result.begin(), result.end());
        for (auto it = result.begin(); it != result.end(); it++){
            cout << *it << ' ';
        }
    }

    return 0;
}