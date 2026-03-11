#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    int cnt = 0;

    stringstream ss(s);
    string word;
    
    while (ss >> word){
        bool isUpper = true;

        for (int i = 0; i < (int)word.size(); i++){
            if (isupper(word[i]) == 0){
                isUpper = false;
            }
        }

        if (isUpper == true){
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}