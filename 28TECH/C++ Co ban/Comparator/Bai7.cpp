#include <iostream>
#include <algorithm>

using namespace std;

struct elements{
    int value, count;
};

int count068(int n){
    int cnt = 0;
    if (n == 0){
        return 1;
    }
    while (n){
        int last = n % 10;
        if (last == 0 || last == 6 || last == 8){
            cnt++;
        }
        n /= 10;
    }
    return cnt;
}

bool comp(elements a, elements b){
    if (a.count > b.count){
        return true;
    }
    else if (a.count == b.count){
        return a.value < b.value;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cin >> n;
    elements* a = new elements[n];
    for (int i = 0; i < n; i++){
        cin >> a[i].value;
        a[i].count = count068(a[i].value);
    }
    sort(a, (a+n), comp);
    for (int i = 0; i < n; i++){
        cout << a[i].value << ' ';
    }

    delete []a;
    return 0;
}