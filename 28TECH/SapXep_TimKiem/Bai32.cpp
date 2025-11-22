#include <iostream>
#include <set>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    multiset<int> a, b;
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        a.insert(tmp);
    }
    for (int i = 0; i < m; i++){
        int tmp; cin >> tmp;
        b.insert(tmp);
    }

    auto it1 = a.begin();
    auto it2 = b.begin();
    int cnt = 0;
    while (it1 != a.end() && it2 != b.end()){
        if (*it1 - *it2 > 1){
            it2++;
        }
        else if (*it2 - *it1 > 1){
            it1++;
        }
        else{
            cnt++;
            it1++;
            it2++;
        }
    }
    cout << cnt << endl;
    return 0;
}