#include <iostream>
#include <string>
#include <vector>

using namespace std;

void insertionSort(vector<int> &v){
    int n = v.size();

    for (int i = 1; i < n; i++){
        int j = i;
        while (j > 0 && v[j] < v[j - 1]){
            swap(v[j], v[j - 1]);
            j--;
        }
    }
}

int main(){
    string s;
    cin >> s;

    vector<int> v;
    for (int i = 0; i < (int)s.size(); i++){
        if (isdigit(s[i]) == 1){
            v.push_back(s[i] - '0');
        }
    }

    insertionSort(v);
    int n = v.size();
    for (int i = 0; i < n; i++){
        cout << v[i];
        if (i != n - 1){
            cout << '+';
        }
    }

    return 0;
}