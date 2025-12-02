#include <stdio.h>

// mergeSort co do phuc tap O(NlogN)
void merge(int a[], int l, int m, int r){
//	tao mang phu luu gia tri cua 2 day con
	int n1 = m-l+1, n2= r-m;
	int x[n1], y[n2];
	for (int i=0; i<n1; i++){
		x[i] = a[l+i];
	}
	for (int i=0; i<n2; i++){
		y[i] = a[m+1+i];
	}
//	merge 2 day con lai roi gan cho day a ban dau
	int i=0, j=0, idx=l;
	while (i < n1 && j < n2){
		if ( x[i] <= y[j]){
			a[idx++] = x[i++];
		}
		else {
			a[idx++] = y[j++];
		}
	}
	while (i < n1) {
		a[idx++] = x[i++];
	}
	while (j < n2) {
		a[idx++] = y[j++];
	}
}

void mergeSort(int a[], int l, int r){
	if (l<r){
//		chia 2 day con tinh tu gia tri mid (m)
		int m = (l+r)/2;
		mergeSort(a, l, m);
		mergeSort(a, m+1, r);
		merge(a, l, m, r);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	mergeSort(a, 0, n-1);
	for (int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
