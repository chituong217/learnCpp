#include <iostream>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    string amax, bmax, amin, bmin;
    amax = amin = a;
    bmax = bmin = b;

    for (int i = 0; i < (int)a.size(); i++){
        if (a[i] == '5'){
            amax[i] = '6';
        }
        if (a[i] == '6'){
            amin[i] = '5';
        }
    }
    for (int i = 0; i < (int)b.size(); i++){
        if (b[i] == '5'){
            bmax[i] = '6';
        }
        if (b[i] == '6'){
            bmin[i] = '5';
        }
    }

    long long sumMax = stoll(amax) + stoll(bmax);
    long long sumMin = stoll(amin) + stoll(bmin);

    cout << sumMax << ' ' << sumMin;
    
    return 0;
}