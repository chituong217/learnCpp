#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string S;
    cin >> S;

    int demS[256] = {0};

    vector<char> s, t;
    string u = "";
    
    for (int i = S.size() - 1; i >= 0; i--){
        s.push_back(S[i]);
        demS[(int)S[i]]++;
    }

    while (s.size() > 0){
        if (t.size() == 0){
            t.push_back(s.back());
            demS[(int)s.back()]--;
            s.pop_back();
        }
        else{
            bool isMin = true;
            char top = t.back();

            for (int i = 0; i < (int)top; i++){
                if (demS[i] > 0){
                    isMin = false;
                    break;
                }
            }

            if (isMin){
                u += top;
                t.pop_back();
            }
            else{
                t.push_back(s.back());
                demS[(int)s.back()]--;
                s.pop_back();
            }
        }
    }

    while (t.size() > 0){
        u += t.back();
        t.pop_back();
    }

    cout << u;

    return 0;
}