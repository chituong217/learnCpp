#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
    set<string> se;
    
    string s;
    while (cin >> s){
        se.insert(s);
    }

    cout << se.size() << endl;
    cout << *se.begin() << ' ' << *se.rbegin();

    return 0;
}