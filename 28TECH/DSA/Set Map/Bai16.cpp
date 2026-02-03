#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    
    map<string, string> mp;
    for (int i = 0; i < n; i++){
        string mssv, ten;
        getline(cin, mssv);
        getline(cin, ten);
        mp[mssv] = ten;
    }

    int q;
    cin >> q;
    cin.ignore();

    for (int i = 0; i < q; i++){
        string mssv;
        getline(cin, mssv);

        auto it = mp.find(mssv);
        if (it != mp.end()){
            cout << mp[mssv] << endl;
        }
        else{
            cout << "NOT FOUND" << endl;
        }
    }

    return 0;
}