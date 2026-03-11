#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;

    string day, month, year;
    int cntSlash = 0;

    for (int i = 0; i < (int)s.size(); i++){
        if (s[i] == '/'){
            cntSlash++;
            continue;
        }

        if (cntSlash == 0){
            day += s[i];
        }
        else if (cntSlash == 1){
            month += s[i];
        }
        else{
            year += s[i];
        }
    }

    if (day.size() < 2){
        day += '0';
        reverse(day.begin(), day.end());
    }
    
    if (month.size() < 2){
        month += '0';
        reverse(month.begin(), month.end());
    }

    cout << day << '/' << month << '/' << year;

    return 0;
}