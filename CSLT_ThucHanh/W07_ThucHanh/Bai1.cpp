#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void phatsinhMang(int *&a, int n, int minVal, int maxVal) {
    a = new int[n]; 
    for (int i = 0; i < n; i++) {
        a[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

int findMax(int a[], int n){
    int maxVal = a[0];
    for (int i = 1; i < n; i++){
        if (a[i] > maxVal) maxVal = a[i];
    }
    return maxVal;
}

int findMin(int a[], int n){
    int minVal = a[0];
    for (int i = 1; i < n; i++){
        if (a[i] < minVal) minVal = a[i];
    }
    return minVal;
}

long long findSum(int a[], int n){
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    return sum;
}

int comp(const void *a, const void *b){
    int *x = (int *)a;
    int *y = (int *)b;
    return (*x - *y);
}

long long findSumMaxFreSafe(int a[], int n) {
    if (n == 0) return 0;
    int *temp = new int[n];
    for(int i=0; i<n; i++){
        temp[i] = a[i];
    }
    qsort(temp, n, sizeof(int), comp);

    int currentFre = 1;
    int maxFre = 1;

    for (int i = 1; i < n; i++) {
        if (temp[i] == temp[i-1]) {
            currentFre++;
        }
        else {
            if (currentFre > maxFre) {
                maxFre = currentFre;
            }
            currentFre = 1;
        }
    }
    if (currentFre > maxFre){
        maxFre = currentFre;
    }

    long long totalSum = 0;
    currentFre = 1;
    for (int i = 1; i < n; i++) {
        if (temp[i] == temp[i-1]) {
            currentFre++;
        }
        else {
            if (currentFre == maxFre) {
                totalSum += (long long)temp[i-1] * currentFre; 
            }
            currentFre = 1;
        }
    }

    if (currentFre == maxFre) {
        totalSum += (long long)temp[n-1] * currentFre;
    }

    delete[] temp;
    return totalSum;
}

bool isConCuaMang(int a[], int n, int con[], int sizecon){
    if (sizecon == 0) return true;
    if (sizecon > n) return false;

    for (int i = 0; i <= n - sizecon; i++){
        bool match = true;
        for(int j = 0; j < sizecon; j++){
            if(a[i+j] != con[j]){
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false;
}

int main(){
    srand(time(NULL));
    int n;
    do{
        cout << "Nhap so luong phan tu: ";
        cin >> n;
    } while (n < 3);

    int *a = NULL;
    int minVal, maxVal;
    cout << "Nhap khoang gia tri [min, max]: ";
    cin >> minVal >> maxVal;

    phatsinhMang(a, n, minVal, maxVal);

    cout << "Mang phat sinh: ";
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Phan tu lon nhat: " << findMax(a, n) << endl;
    cout << "Phan tu nho nhat: " << findMin(a, n) << endl;
    cout << "Tong cac phan tu: " << findSum(a, n) << endl;

    cout << "Tong cac phan tu co so lan xuat hien lon nhat: " << findSumMaxFreSafe(a, n) << endl;

    int *b = new int [n];
    for (int i = 0; i < n; i++){
        b[i] = a[i];
    }
    qsort(b, n, sizeof(int), comp);
    
    cout << "Phan tu trung vi: ";
    if (n % 2 != 0){
        cout << b[n/2] << endl;
    } else {
        cout << b[n/2 - 1] << " va " << b[n/2] << endl;
    }
    delete []b;

    int sizecon;
    cout << "Hay nhap size mang con: ";
    cin >> sizecon;
    if(sizecon > 0) {
        int *con = new int[sizecon];
        cout << "Nhap cac phan tu mang con: ";
        for (int i = 0; i < sizecon; i++){
            cin >> con[i];
        }
        
        if (isConCuaMang(a, n, con, sizecon))
            cout << "La mang con!" << endl;
        else
            cout << "Khong phai mang con!" << endl;
        
        delete []con;
    } else {
        cout << "Mang rong la mang con cua moi mang" << endl;
    }

    delete []a;
    return 0;
}