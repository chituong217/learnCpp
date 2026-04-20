#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    set<pair<string, string>> unique_leaves;

    for (int i = 0; i < n; ++i) {
        string species, color;
        cin >> species >> color;
        
        unique_leaves.insert({species, color});
    }

    cout << unique_leaves.size() << endl;

    return 0;
}