#include <iostream>
#include <string>

using namespace std;

bool isReverseString(string s){
    int left = 0, right = s.size() - 1;

    while (left <= right){
        if (s[left] != s[right]){
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main(){
    string s;
    cin >> s;

    if (isReverseString(s) == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}