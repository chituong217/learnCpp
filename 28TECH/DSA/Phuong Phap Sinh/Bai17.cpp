#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string s;

bool sinh(){
    int i = n - 1;
    while (i >= 1 && s[i] >= s[i + 1]){
        i--;
    }

    if (i == 0){
        return false;
    }
    else{
        int j = n;
        while (s[i] >= s[j]){
            j--;
        }

        swap(s[i], s[j]);
        reverse(s.begin() + 1 + i, s.end()); 
        return true;       
    }
}

int main(){
    string a;
    cin >> a;
    s = "0";
    s += a;
    n = s.size();

    if (sinh() == false){
        cout << "NOT EXIST";
    }
    else{
        cout << s.substr(1);
    }

    return 0;
}