#include <iostream>
#include <string>

using namespace std;

int main(){
    int x; cin >> x;
    string s;
    cin.ignore(1);
    getline(cin, s);
    cout << s << endl;
    cout << "Do dai cua xau la : " << s.size() << endl;
    return 0;
}