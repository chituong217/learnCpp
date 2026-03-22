#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void merge(vector<int> &a, int l, int m, int r){
    int n1 = m - l + 1, n2 = r - (m + 1) + 1;
    vector<int> x(n1), y(n2);


    for (int i = l; i <= m; i++){
        x[i - l] = a[i];
    }
    for (int i = m + 1; i <= r; i++){
        y[i - (m + 1)] = a[i];
    }

    int i = 0, j = 0, cnt = l;
    while (i < n1 && j < n2){
        if (x[i] < y[j]){
            a[cnt++] = x[i++];
        }
        else{
            a[cnt++] = y[j++];
        }
    }

    while (i < n1){
        a[cnt++] = x[i++];
    }
    while (j < n2){
        a[cnt++] = y[j++];
    }
}

void mergeSort(vector<int> &a, int l, int r){
    if (l < r){
        int m = (l + r)/2;
        
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

int main(){
    int n, l;
    cin >> n >> l;

    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    mergeSort(v, 0, n - 1);

    double maxDistance = v[0];

    for (int i = 1; i < n; i++){
        double currentDistance = v[i] - v[i - 1];
        currentDistance /= 2.0;

        if (currentDistance > maxDistance){
            maxDistance = currentDistance;
        }
    }

    double lastDistance = (l - v[n - 1]);
    if (lastDistance > maxDistance){
        maxDistance = lastDistance;
    }

    cout << fixed << setprecision(10) << maxDistance;

    return 0;
}