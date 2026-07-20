#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int x;

bool comp1(int a, int b){
    int absA = abs(a - x);
    int absB = abs(b - x);
    if (absA < absB){
        return true;
    }
    else if (absA == absB){
        return a < b;
    }
    else{
        return false;
    }
}

bool comp2 (int a, int b){
    int c1 = a % 2;
    int c2 = b % 2;
    if (c1 == 1 && c2 == 0){
        return false;
    }
    else if (c1 == 0 && c2 == 1){
        return true;
    }
    else if (c1 == 0 && c2 == 0){
        return a < b;
    }
    else{
        return a > b;
    }
}

int main(){
    int n;
    cin >> n >> x;
    vector <int> a1(n);
    vector <int> a2(n);
    for (int i = 0; i < n; i++){
        cin >> a1[i];
        a2[i] = a1[i];
    }
    sort(a1.begin(), a1.end(), comp1);
    for (int i = 0; i < n; i++){
        cout << a1[i] << ' ';
    }
    cout << endl;
    sort(a2.begin(), a2.end(), comp2);
    for (int i = 0; i < n; i++){
        cout << a2[i] << ' ';
    }
    cout << endl;
    return 0;
}