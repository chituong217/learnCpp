#include <iostream>
#include <string>

using namespace std;

bool isDivisibleBy4(string s){
    if (s.size() == 0){
        return false;
    }
    else if (s.size() == 1){
        if ((s[0] - '0') % 4 == 0){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        int n = s.size();
        string haiSoCuoi = s.substr(n - 2);
        int haiSoCuoiInt = stoi(haiSoCuoi);

        return haiSoCuoiInt % 4 == 0;
    }
}

int main(){
    string s;
    cin >> s;

    if (isDivisibleBy4(s) == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}