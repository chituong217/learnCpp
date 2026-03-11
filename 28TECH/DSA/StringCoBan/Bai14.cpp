#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    stringstream ss(s);
    string word;

    int cnt = 0;

    while (ss >> word){
        for (int i = 0; i < (int)word.size(); i++){
            word[i] = tolower(word[i]);
        }

        if (word == "28tech"){
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}