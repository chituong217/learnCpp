#include <iostream>
#include <cstdlib>
#include <ctime>

#define minVal -50
#define maxVal 50

using namespace std;

void phatsinhMang(int *a, int n){
    for (int i = 0; i < n; i++){
        a[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

bool binarySearch(int *a, int n, int x){
    int left = 0, right = n - 1;
    while (left <= right){
        int mid = left + (right - left)/2;
        if (a[mid] == x){
            return true;
        }
        else if (a[mid] < x){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return false;
}

bool linearSearch(int *a, int n, int x){
    for(int i = 0; i < n; i++){
        if(a[i] == x) return true;
    }
    return false;
}

void bubbleSort(int *a, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

int main(){
    srand(time(NULL));

    int np, nq;

    do{
        cout << "Nhap vao so luong phan tu cua mang p: ";
        cin >> np;
    } while (np < 10);

    do{
        cout << "Nhap vao so luong phan tu cua mang q: ";
        cin >> nq;
    } while (nq < 10);

    int *p = new int[np];
    int *q = new int[nq];

    phatsinhMang(p, np);
    phatsinhMang(q, nq);

    cout << "Mang p: ";
    for (int i = 0; i < np; i++){
        cout << p[i] << ' ';
    }
    cout << endl;

    cout << "Mang q: ";
    for (int i = 0; i < nq; i++){
        cout << q[i] << ' ';
    }
    cout << endl;

    bubbleSort(p, np);
    bubbleSort(q, nq);

    bool found = false;
    cout << "Cac phan tu co trong p ma khong co trong q: ";
    for (int i = 0; i < np; i++){
        if (i > 0 && p[i] == p[i-1]) continue;
        if (binarySearch(q, nq, p[i]) == false){
            found = true;
            cout << p[i] << ' ';
        }
    }
    if (found == false){
        cout << "Khong ton tai";
    }
    cout << endl;

    int n = np + nq, idxHop = 0;
    int *hop = new int[n];

    for (int i = 0; i < np; i++){
        if (linearSearch(hop, idxHop, p[i]) == false){
            hop[idxHop++] = p[i];
        }
    }

    for (int i = 0; i < nq; i++){
        if (linearSearch(hop, idxHop, q[i]) == false){
            hop[idxHop++] = q[i];
        }
    }

    cout << "Hop cua 2 mang: ";
    for (int i = 0; i < idxHop; i++){
        cout << hop[i] << ' ';
    }
    cout << endl;

    delete []p;
    delete []q;
    delete []hop;
    return 0;
}