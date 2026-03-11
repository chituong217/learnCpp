#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    cout << s << endl;

    sort(s.begin(), s.end(), greater<int>());
    
    cout << s;

    return 0;
}