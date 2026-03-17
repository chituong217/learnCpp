#include <iostream>
#include <string>

using namespace std;

bool isDivisibleBy11(string s){
    int n = s.size();

    if (n == 0){
        return false;
    }
    else if (n == 1){
        if (s[0] == '0'){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        int tongLe = 0, tongChan = 0;
        for (int i = 0; i < (int)s.size(); i++){
            if (i % 2 == 0){
                tongChan += s[i] - '0';
            }
            else{
                tongLe += s[i] - '0';
            }
        }

        int chenhlech = abs(tongChan - tongLe);
        return (chenhlech % 11 == 0);
    }
}

int main(){
    string s;
    cin >> s;

    if (isDivisibleBy11(s) == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}