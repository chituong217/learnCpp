#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main(){
    string s;
    getline(cin, s);
    if (s.size() % 2 == 0){
        cout << "NOT FOUND\n";
    }
    else{
        int middlePos = (s.size()/2);
        cout << s[middlePos] << endl;
    }

    return 0;
}