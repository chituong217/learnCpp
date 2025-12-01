#include <iostream>

using namespace std;

int findPartitionIndex(int *nums, int size){
    int totalSum = 0;
    for (int i = 0; i < size; i++){
        totalSum += nums[i];
    }
    int totalLeft = 0;
    for (int i = 0; i < size; i++){
        totalLeft += nums[i];
        int totalRight = totalSum - totalLeft;
        if (totalRight == totalLeft){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << findPartitionIndex(a, n);
    return 0;
}