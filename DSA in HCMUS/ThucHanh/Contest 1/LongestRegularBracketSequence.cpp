#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    vector<int> st;
    st.push_back(-1);

    int maxLen = 0;
    int count = 1;

    for (int i = 0; i < (int)s.size(); i++){
        if (s[i] == '('){
            st.push_back(i);
        }
        else{
            st.pop_back();

            if (st.empty() == true){
                st.push_back(i);
            }
            else{
                int currLen = i - st.back();

                if (currLen > maxLen){
                    maxLen = currLen;
                    count = 1;
                }
                else if (currLen == maxLen && maxLen > 0){
                    count++;
                }
            }
        }
    }

    cout << maxLen << ' ' << count;

    return 0;
}