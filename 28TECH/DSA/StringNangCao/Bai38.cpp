#include <iostream>
#include <string>

using namespace std;

bool isDivisibleBy25(string s){
    int n = s.size();
    if (n == 0){
        return false;
    }
    else if (n == 1){
        if (s[0] == '0'){
            return true;
        }
        return false;
    }
    else{
        string haiSoCuoi = s.substr(n - 2);
        int haiSoCuoiInt = stoi(haiSoCuoi);

        if (haiSoCuoiInt % 25 == 0){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){
    string s;
    cin >> s;

    if (isDivisibleBy25(s) == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}