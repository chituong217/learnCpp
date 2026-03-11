#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    string num;
    string alpha;

    for (int i = 0; i < (int)s.size(); i++){
        if (isalpha(s[i]) != 0){
            alpha += s[i];
        }
        
        if (isdigit(s[i]) != 0){
            num += s[i];
        }
    }

    cout << num << endl;
    cout << alpha;

    return 0;
}