#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int demSoLuongChuSoChan(int n){
    int cnt = 0;
    if (n == 0){
        return 1;
    }
    while (n){
        if ((n%10) % 2 == 0){
            cnt++;
        }
        n /= 10;
    }
    return cnt;
}

int demSoLuongChuSoLe(int n){
    int cnt = 0;
    while (n){
        if ((n%10) % 2 != 0){
            cnt++;
        }
        n /= 10;
    }
    return cnt;
}

bool comp1(int a, int b){
    int cntA = demSoLuongChuSoChan(a);
    int cntB = demSoLuongChuSoChan(b);
    if (cntA < cntB){
        return true;
    }
    else if (cntA == cntB){
        return a < b;
    }
    else{
        return false;
    }
}

bool comp2(int a, int b){
    int cntA = demSoLuongChuSoLe(a);
    int cntB = demSoLuongChuSoLe(b);
    if (cntA < cntB){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a.begin(), a.end(), comp1);
    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    stable_sort(b.begin(), b.end(), comp2);
    for (int i = 0; i < n; i++){
        cout << b[i] << ' ';
    }
    return 0;
}