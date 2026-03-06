#include <iostream>
#include <map>

using namespace std;


int main(){
    int n;
    cin >> n;

    int tmp;

    map<int, int> mp;

    int firstRepeat = -1;

    for (int i = 0; i < n; i++){
        cin >> tmp;
        mp[tmp]++;
        if (mp[tmp] > 1 && firstRepeat == -1){
            firstRepeat = tmp;
        }
    }

    cout << firstRepeat;


    return 0;
}