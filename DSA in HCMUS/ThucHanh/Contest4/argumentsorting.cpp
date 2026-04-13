#include <iostream>
#include <vector>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if (a.first < b.first){
        return true;
    }
    else if (a.first > b.first){
        return false;
    }
    else{
        return a.second < b.second;
    }
}

void heapify(vector<pair<int,int>> &a, int left, int right){
    int p = 2 * left + 1;
    if (p > right){
        return;
    }
    if (p + 1 <= right && compare(a[p], a[p + 1])){
        p = p + 1;
    }

    if (compare(a[left], a[p])){
        swap(a[left], a[p]);

        heapify(a, p, right);
    }
}

void createHeap(vector<pair<int,int>> &a, int n){
    for (int i = (n - 1) / 2; i >= 0; i--){
        heapify(a, i, n - 1);
    }
}

void heapSort(vector<pair<int,int>> &a, int n){
    createHeap(a, n);
    
    for (int i = n - 1; i >= 1; i--){
        swap(a[0], a[i]);

        heapify(a, 0, i - 1);
    }
}

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }

    heapSort(a, n);

    for (int i = 0; i < n; i++){
        cout << a[i].second << ' ';
    }

    return 0;
}