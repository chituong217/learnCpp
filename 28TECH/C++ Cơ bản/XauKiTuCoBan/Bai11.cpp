#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;
    string date = "";
    bool isYear = false;
    while (getline(ss, word, '/')){
        int so = stoi(word);
        if (so < 10){
            date += '0';
        }
        else if (so >= 1000){
            isYear = true;
        }
        date += to_string(so);
        if (!isYear){
            date += '/';
        }
    }
    cout << date << endl;
    return 0;
}