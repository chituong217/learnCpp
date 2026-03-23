#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &a, int target){
    int left = 0, right = a.size() - 1;
    int ans = -1;

    while (left <= right){
        int mid = (left + right) / 2;

        if (target == a[mid]){
            ans = mid;
            break;
        }

        if (a[left] <= a[mid]){
            if (a[left] <= target && target < a[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if (a[mid] < target && target <= a[right]){
                left = mid + 1;
            }
            else{
                right = mid -1;
            }
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

    while (q--){
        int target;
        cin >> target;

        cout << binarySearch(v, target) << '\n';
    }

    return 0;
}