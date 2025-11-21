#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int fre[10000005] = {0};

int findMax(int a[], int n){
    int max = a[0];
    for (int i = 0; i < n; i++){
        if ( a[i] > max){
            max = a[i];
        }
    }
    return max;
}

int findMin(int a[], int n){
    int min = a[0];
    for (int i = 0; i < n; i++){
        if ( a[i] < min){
            min = a[i];
        }
    }
    return min;
}

long long findSum(int a[], int n){
    long long sum = 0;
    for (int i = 0; i < n; i++){
        sum += a[i];
    }
    return sum;
}

long long findSumMaxFre(int a[], int n){
    int maxFre = 0;
    long long sumMaxFre = 0;
    for (int i = 0; i < n; i++){
        fre[a[i]]++;
    }
    for (int i = 0; i < n; i++){
        int tmpFre = fre[a[i]];
        if (tmpFre > maxFre){
            maxFre = tmpFre;
        }
    }
    for (int i = 0; i < n; i++){
        if (fre[a[i]] == maxFre){
            sumMaxFre += a[i];
        }
    }
    return sumMaxFre;
}

int comp(const void *a, const void *b){
    int *x = (int *)a;
    int *y = (int *)b;
    if (*x < *y){
        return -1;
    }
    else{
        return 1;
    }
}

bool isConCuaMang(int a[], int n, int con[], int sizecon){
    int idx = 0;
    for (int i = 0; i < n; i++){
        int i_tmp = i;
        if (a[i] == con[idx]){
            while (a[i] == con[idx]){
                i++;
                idx++;
                if (idx == sizecon){
                    return true;
                }
                if (i >= n){
                    return false;
                }
            }
            idx = 0;
            i = i_tmp;
        }
    }
    return false;
}

int main(){
    int n;
    do{
        cin >> n;
    } while (n < 3);
    int *a = new int[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int max = findMax(a, n);
    cout << "Phan tu lon nhat: " << max << endl;

    int min = findMin(a, n);
    cout << "Phan tu nho nhat: " << min << endl;

    long long sum = findSum(a, n);
    cout << "Tong cac phan tu trong mang: "<< sum << endl;

    long long sumMaxFre = findSumMaxFre(a, n);
    cout << "Tong cac phan tu co so lan xuat hien lon nhat: " << sumMaxFre << endl;

    // xu li phan tu trung vi
    int *b = new int [n];
    for (int i = 0; i < n; i++){
        b[i] = a[i];
    }
    qsort(b, n, sizeof(int), comp);
    int middle_pos = n/2;
    bool isEven = false;
    if (n % 2 == 0){
        isEven = true;
    }
    cout << "Phan tu trung vi cua mang: ";
    if (isEven == false){
        cout << b[middle_pos] << endl;
    }
    else{
        cout << b[middle_pos - 1] << ' ' << b[middle_pos] << endl;
    }


    // xu li mang con
    int sizecon;
    cout << "Hay nhap vao size cua mang con: ";
    cin >> sizecon;
    int *con = new int[sizecon];
    if (sizecon == 0){
        cout << "Mang rong la mang con cua moi mang" << endl;
    }
    else{
        cout << "Hay nhap vao " << sizecon << " phan tu cua mang con:" << endl;
        for (int i = 0; i < sizecon; i++){
            cin >> con[i];
        }
        bool isCon = isConCuaMang(a, n, con, sizecon);
        if (isCon == true){
            cout << "Mang con cua mang ban dau" << endl;
        }
        else{
            cout << "Khong phai mang con cua mang ban dau" << endl;
        }
    }
    
    
    delete []a;
    delete []b;
    delete []con;
    return 0;
}