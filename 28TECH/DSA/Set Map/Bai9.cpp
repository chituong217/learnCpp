#include <iostream>
#include <set>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    set<int> se;
    for (int i = 0; i < m + n; i++){
        int tmp;
        cin >> tmp;
        se.insert(tmp);
    }

    for (set<int>::reverse_iterator it = se.rbegin(); it != se.rend(); it++){
        cout << *it << ' ';
    }
    return 0;
}