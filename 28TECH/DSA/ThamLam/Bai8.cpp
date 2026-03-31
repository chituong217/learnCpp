#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct job{
    int id, deadline, profit;
};

bool comp(job a, job b){
    return a.profit > b.profit;
}


int main(){
    int n;
    cin >> n;

    vector<job> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].id >> v[i].deadline >> v[i].profit;
    }

    sort(v.begin(), v.end(), comp);

    set<int> time;
    for (int i = 0; i < n; i++){
        time.insert(i);
    }

    long long sum = 0;

    for (int i = 0; i < n; i++){
        // tim tgian de lam muon nhat ^^
        auto it = time.lower_bound(v[i].deadline);
        if (it != time.begin()){
            --it;
            time.erase(it);
            sum += v[i].profit;
        }
    }

    cout << sum;

    return 0;
}