#include <iostream>
#include <string>

using namespace std;

struct MatHang{
    string maHang;
    int gia;
    int tonKho;
};

bool laNhoHon(MatHang a, MatHang b){
    if (a.gia < b.gia){
        return true;
    }
    else if (a.gia == b.gia){
        if (a.tonKho > b.tonKho){
            return true;
        }
        else if (a.tonKho == b.tonKho){
            return a.maHang < b.maHang;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

void myQuickSort(MatHang a[], int low, int high){
    if (low < high){
        int i = low, j = high;
        MatHang pivot = a[(low + high) / 2];

        while (i <= j){
            while (laNhoHon(a[i], pivot) == true) i++;
            while (laNhoHon(pivot, a[j]) == true) j--;

            while (i <= j){
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }

        if (low < j) myQuickSort(a, low, j);
        if (i < high) myQuickSort(a, i, high);
    }
}

int main(){

    return 0;
}