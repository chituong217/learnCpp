#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <pair <int,int> > a;
    for (int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        a.push_back({start, 1});
        a.push_back({end, -1});
    }
    sort(a.begin(), a.end());
    int current_customers = 0;
    int max_customers = 0;
    for (int i = 0; i < a.size(); i++){
        current_customers += a[i].second;
        if (current_customers > max_customers){
            max_customers = current_customers;
        }
    }
    cout << max_customers << endl;
    return 0;
}