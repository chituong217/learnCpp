#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore(1);

    stack<int> st;

    for (int i = 0; i < n; i++){
        string s;
        cin >> s;

        if (s == "show"){
            vector<int> v;
            while (st.empty() == false){
                v.push_back(st.top());
                st.pop();
            }

            for (auto it = v.rbegin(); it != v.rend(); it++){
                cout << *it << ' ';
                st.push(*it);
            }
            if (v.empty() == false){
                cout << endl;
            }
            else{
                cout << "EMPTY" << endl;
            }


        }
        else if (s == "push"){
            int x;
            cin >> x;
            cin.ignore();

            st.push(x);
        }
        else{
            if (st.empty() == false){
                st.pop();
            }
        }
    }

    return 0;
}