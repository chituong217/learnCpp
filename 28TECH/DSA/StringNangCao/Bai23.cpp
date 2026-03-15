#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    
    sort(words.begin(), words.end(), cmp);
    
    string result;
    for (string w : words) {
        result += w;
    }
    
    cout << result << endl;
    
    return 0;
}