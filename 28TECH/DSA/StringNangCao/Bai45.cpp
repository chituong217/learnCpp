#include <iostream>
#include <string>

using namespace std;

long long moduleBy(string n, long long m){
    long long res = 0;

    for (int i = 0; i < (int)n.size(); i++){
        res = ((__int128_t)res * 10 + (n[i] - '0')) % m;
    }

    return res;
}

int main(){
    string s;
    cin >> s;

    int r = moduleBy(s, 4);
    
    if (r == 1){
        cout << "8";
    }
    else if (r == 2){
        cout << "4";
    }
    else if (r == 3){
        cout << "2";
    }
    else{
        cout << "6";
    }

    return 0;
}