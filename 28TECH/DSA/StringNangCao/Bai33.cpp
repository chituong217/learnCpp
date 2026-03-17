#include <iostream>
#include <string>

using namespace std;

bool isSoDep(string s){
    bool havingSix = false;

    int left = 0, right = s.size() - 1;
    while (left <= right){
        if (s[left] != s[right]){
            return false;
        }

        if (s[left] == '6' || s[right] == '6'){
            havingSix = true;
        }
        
        left++;
        right--;
    }

    if (havingSix == true){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s;
    cin >> s;
    
    if (isSoDep(s) == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }


    return 0;
}