#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define limit (pow(2, 32) - 1)

using namespace std;


int main(){
    int l;
    cin >> l;
    cin.ignore();

    bool ok = true;

    long long x = 0;

    vector<long long> st;

    while (l--){
        string s;
        cin >> s;
        
        if (s == "add"){
            if (st.empty() == false){
                if (st.back() > limit){
                    ok = false;
                }
                else{
                    x += st.back();
                    if (x > limit){
                        ok = false;
                    }
                }
            }
            else{
                x++;
                if (x > limit){
                    ok = false;
                }
            }
        }
        else if (s == "for"){
            int n;
            cin >> n;
            cin.ignore();

            long long currentTop;
            if (st.empty() == false){
                currentTop = st.back();
            }
            else{
                currentTop = 1;
            }

            long long nextVal;

            if (currentTop > limit || (n > 1 && currentTop > limit/n)){
                nextVal = limit + 1;
            }
            else{
                nextVal = currentTop * n;;

                if (nextVal > limit){
                    nextVal = limit + 1;
                }
            }

            st.push_back(nextVal);
        }
        else{
            if (st.empty() == false){
                st.pop_back();
            }
        }
    }

    if (ok == true){
        cout << x;
    }
    else{
        cout << "OVERFLOW!!!";
    }

    return 0;
}