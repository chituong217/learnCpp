#include <iostream>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;
    set <int> se;
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        se.insert(tmp);
    }
    cout << se.size();
    return 0;
}