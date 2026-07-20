#include <iostream>
#include <set>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    set <int> se;
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        se.insert(tmp);
    }

    bool isFound = false;
    for (auto it = se.begin(); it != se.end(); it++){
        int hieu = *it - x;
        if (se.find(hieu) != se.end()){
            isFound = true;
            break;
        }
    }
    if (isFound == true){
        cout << "1" << endl;
    }
    else{
        cout << "-1" << endl;
    }

    return 0;
}