#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map<int, int> mp;
    mp.insert({1, 2}); 
    mp.insert({1, 3});
    mp.insert({2, 2});
    mp.insert({2, 3});
    mp.insert({3, 4});
    for (unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
        cout << (*it).first << ' ' << (*it).second << endl;
    }
}