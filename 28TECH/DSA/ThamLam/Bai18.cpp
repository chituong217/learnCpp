#include <iostream>

using namespace std;

void insertionSort(int a[], int n){
    for (int i = 0; i < n; i++){
        int j = i;
        while (j > 0 && a[j] < a[j - 1]){
            swap(a[j], a[j - 1]);
            j++;
        }
    }
}

int main(){
    int n;
    cin >> n;

    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] == 1){
            cnt1++;
        }
        else if (a[i] == 2){
            cnt2++;
        }
        else if (a[i] == 3){
            cnt3++;
        }
        else{
            cnt4++;
        }
    }

    int xe = cnt4;

    while (cnt3 > 0){
        if (cnt1 > 0){
            cnt1--;
        }
        cnt3--;
        xe++;
    }
    while(cnt2 > 0){
        if (cnt1 > 0){
            if (cnt1 == 1){
                cnt1--;
            }
            else if (cnt1 > 1){
                cnt1 -= 2;
            }
            cnt2--;
            xe++;
        }
        else{
            if (cnt2 >= 2){
                cnt2 -= 2;
            }
            else if (cnt2 > 0){
                cnt2--;
            }
            xe++;
        }
    }
    if (cnt1 > 0){
        xe += cnt1 / 4;
        cnt1 %= 4;
        if (cnt1 != 0){
            xe++;
        }
    }

    cout << xe;

    return 0;
}