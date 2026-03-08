#include <iostream>
#include <map>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    map<int, int> first_pos;
    map<int, int> last_pos;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        if (first_pos.find(a[i]) == first_pos.end()){
            first_pos[a[i]] = i;
        }

        last_pos[a[i]] = i;
    }

    int maxDis = -1;
    
    for (auto it = first_pos.begin(); it != first_pos.end(); it++){
        int val = it->first;

        if(first_pos.find(val - k) != first_pos.end()){
            maxDis = max(last_pos[val] - first_pos[val - k], maxDis);
            maxDis = max(last_pos[val - k] - first_pos[val], maxDis);
        }

        if (first_pos.find(val + k) != first_pos.end()){
            maxDis = max(last_pos[val] - first_pos[val + k], maxDis);
            maxDis = max(last_pos[val + k] - first_pos[val], maxDis);
        }
    }

    cout << maxDis;

    return 0;
}