#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &a, int left, int mid, int right){
    int n1 = mid - left + 1, n2 = right - (mid + 1) + 1;
    vector<int> x(n1), y(n2);

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

void mergeSort(vector<int> &a, int left, int right){
    if (left < right){
        int mid = (left + right) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}

int binarySearchLower(vector<int> &a, int left, int right, int target){
    int ans = -1;
    while (left <= right){
        int mid = (left + right) / 2;

        if (a[mid] <= target){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return ans;
}

int binarySearchLarger(vector<int> &a, int left, int right, int target){
    int ans = -1;
    while (left <= right){
        int mid = (left + right) / 2;

        if (a[mid] >= target){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    return ans;
}

int main(){
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    mergeSort(v, 0, n - 1);
    while (q--){
        int target;
        cin >> target;

        int idxLow = binarySearchLower(v, 0, n - 1, target);
        int idxLarge = binarySearchLarger(v, 0, n - 1, target);

        if (idxLarge == -1){
            cout << v[idxLow] << endl;
        }
        else if (idxLow == -1){
            cout << v[idxLarge] << endl;
        }
        else{
            int low = v[idxLow];
            int large = v[idxLarge];

            if (abs(low - target) < abs(large - target)){
                cout << low << endl;
            }
            else if (abs(low - target) == abs(large - target)){
                cout << large << endl;
            }
            else{
                cout << large << endl;
            }
        }
    }

    return 0;
}