#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    set<int> se;
    for (int i = 0; i < n; i++){
        if (se.size() == 10){
            break;
        }
        int tmp = a[i];
        if (tmp == 0){
            if (se.find(0) == se.end()){
                se.insert(0);
            }
        }
        while (tmp){
            int x = tmp%10;
            if (se.find(x) == se.end()){
                se.insert(x);
            }
            tmp/=10;
        }
    }

    for (auto it = se.begin(); it != se.end(); it++){
        cout << *it << ' ';
    }

    return 0;
}