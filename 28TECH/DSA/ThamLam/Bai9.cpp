#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    multiset<long long> se;
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        se.insert(tmp);
    }

    long long sum = 0;
    while (se.size() > 1){
        auto day1 = se.begin();
        auto day2 = day1;
        day2++;

        long long newDay = *day1 + *day2;
        sum += newDay;

        se.erase(day1);
        se.erase(day2);

        se.insert(newDay);
    }

    cout << sum;
    
    return 0;
}