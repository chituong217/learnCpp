#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n; cin >> n;
    set <int> se;
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        se.insert(tmp);
    }
    cout << se.size() << endl;
    auto it1 = se.begin();
    auto it2 = se.rbegin();
    cout << *it2 << ' ' << *it1 << endl;
    it1++; it2++;
    cout << *it2 << ' ' << *it1 << endl;   
    return 0;
}