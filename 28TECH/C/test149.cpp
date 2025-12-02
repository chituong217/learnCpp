#include <stdio.h>

int partition(int a[], int l, int r){
//	cai dat khoa pivot
	int pivot = a[r];
	int i = l-1;
	for (int j = l; j < r; j++){
		if (a[j] <= pivot){
			++i;
			int tmp = a[i];
			a[i]= a[j];
			a[j]=tmp;
		}
	}
	++i;
	int tmp= a[r];
	a[r]=a[i];
	a[i]=tmp;
	return i;
}

void quickSort (int a[], int l, int r){
	if (l<r){
		int pivot = partition(a, l, r);
		quickSort(a, l, pivot-1);
		quickSort(a, pivot+1, r);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	quickSort(a, 0, n-1);	
	for (int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
