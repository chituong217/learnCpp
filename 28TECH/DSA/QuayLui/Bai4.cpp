#include <iostream>

using namespace std;

int n, k;
int a[100];
int X[100];
long long sum = 0;
bool isValid = false;

void merge(int a[], int left, int mid, int right){
    int n1 = mid - left + 1, n2 = right - mid;
    int x[n1], y[n2];
    for (int i = left; i <= mid; i++){
        x[i - left] = a[i];
    }
    for (int i = mid + 1; i <= right; i++){
        y[i - mid - 1] = a[i];
    }

    int i = 0, j = 0, cnt = left;
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

void mergeSort(int a[], int left, int right){
    if (left < right){
        int mid = (left + right) / 2;
        
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}

void Try(int i, int pos){
    for (int j = pos; j <= n; j++){
        X[i] = a[j];
        sum += a[j];

        if (sum == k){
            cout << '[';
            for (int l = 1; l <= i; l++){
                cout << X[l];
                if (l != i){
                    cout << ' ';
                }
            }
            cout << ']' << endl;
            isValid = true;
        }
        else{
            Try(i + 1, j + 1);
        }

        sum -= a[j];
    }
}

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    mergeSort(a, 1, n);
    
    Try(1, 1);
    if (isValid == false){
        cout << "-1";
    }

    return 0;
}