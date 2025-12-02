#include <stdio.h>

int UPpartition(int a[], int l, int r){
	int pivot = a[r];
	int i=l-1;
	for (int j=l; j < r; j++){
		if (a[j] < pivot){
			i++;
			int tmp = a[i]; a[i] = a[j]; a[j] =tmp;
		}
	}
	i++;
	int tmp= a[i]; a[i] = a[r]; a[r] = tmp;
	return i;
}

void UPquickSort(int a[], int l, int r){
	if ( l < r){
		int p = UPpartition(a, l, r);
		UPquickSort(a, l, p-1);
		UPquickSort(a, p+1, r);
	}
}

int DOWNpartition(int a[], int l, int r){
	int pivot = a[r];
	int i=l-1;
	for (int j=l; j < r; j++){
		if (a[j] > pivot){
			i++;
			int tmp = a[i]; a[i] = a[j]; a[j] =tmp;
		}
	}
	i++;
	int tmp= a[i]; a[i] = a[r]; a[r] = tmp;
	return i;
}

void DOWNquickSort(int a[], int l, int r){
	if ( l < r){
		int p = DOWNpartition(a, l, r);
		DOWNquickSort(a, l, p-1);
		DOWNquickSort(a, p+1, r);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n], b[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for (int i=0; i<n; i++){
		scanf("%d", &b[i]);
	}
	UPquickSort(a, 0, n-1);
	DOWNquickSort(b, 0, n-1);
	int i=0, j=0;
	int idx=0;
	while (idx < 2*n){
		if (idx%2==0) printf("%d ", a[i++]);
		else printf("%d ", b[j++]);
		idx++;
	}
	return 0;
}


