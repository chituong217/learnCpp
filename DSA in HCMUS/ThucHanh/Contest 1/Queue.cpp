#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &a, int l, int r){
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++){
        if (a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i], a[r]);
    return i;
}

void quickSort(vector<int> &a, int l, int r){
    if (l >= r){
        return;
    }

    int pivot = partition(a, l, r);
    quickSort(a, l, pivot - 1);
    quickSort(a, pivot + 1, r);
}

void merge(vector<int> &a, int l, int m, int r){
    int n1 = m - l + 1, n2 = r - m;
    vector<int> x1(n1), x2(n2);
    for (int i = l; i <= m; i++){
        x1[i - l] = a[i];
    }
    for (int i = m + 1; i <= r; i++){
        x2[i - m - 1] = a[i];
    }

    int i = 0, j = 0, idx = l;
    while (i < n1 && j < n2){
        if (x1[i] < x2[j]){
            a[idx] = x1[i];
            idx++;
            i++;
        }
        else{
            a[idx] = x2[j];
            idx++;
            j++;
        }
    }

    while (i < n1){
        a[idx] = x1[i];
        idx++;
        i++;
    }

    while (j < n2){
        a[idx] = x2[j];
        idx++;
        j++;
    }
}

void mergeSort(vector<int> &a, int l, int r){
    if (l < r){
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    mergeSort(v, 0, v.size() - 1);

    int cnt = 0;
    long long currentTime = 0;
    for (int i = 0; i < (int)v.size(); i++){
        if (currentTime <= v[i]){
            currentTime += v[i];
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}