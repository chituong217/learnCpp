#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    set <int> se;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];      
    }
    for (int i = 0; i < n; i++){
        if (se.count(a[i]) == 0){
            cout << a[i] << ' ';
            se.insert(a[i]);
        }
    }
    return 0;
}