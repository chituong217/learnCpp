#include <bits/stdc++.h>

using namespace std;

template <class T>
T findMax(T a, T b){
    if (a < b){
        return b;
    }
    else return a;
}

int main(){
    cout << findMax(2, 3) << endl;
    cout << findMax(2.3, 2.9999) << endl;
    return 0;
}