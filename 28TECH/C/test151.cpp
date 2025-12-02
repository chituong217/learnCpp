#include <stdio.h>

int partition(int a[], int l, int r){
	int pivot = a[r];
	int i = l - 1;
	for (int j = l; j < r; j++){
		if (a[j] <= pivot){
			++i;
			int tmp = a[i]; a[i] = a[j]; a[j] = tmp;
		}
	}
	++i;
	int tmp = a[i]; a[i] = a[r]; a[r] = tmp;
	return i;
}

void quickSort(int a[], int l, int r){
	if (l < r){
		int pivot = partition(a, l, r);
		quickSort(a, l, pivot - 1);
		quickSort(a, pivot + 1, r);
	}
}

int binarySearch(int a[], int l, int r, int x){
	if (l > r) return -1;
	else{
		int m = (l + r)/2;
		if ( a[m]== x) return m;
		else if (a[m] < x){
			binarySearch(a, m+1, r, x);
		}
		else if (a[m] > x){
			binarySearch(a, l, m-1, x);
		}
	}
}

int main(){
	int n, x;
	scanf("%d %d", &n, &x);
	int a[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	quickSort(a, 0, n-1);
	for (int i=0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n%d ", binarySearch(a, 0, n-1, x));
	return 0;
}
