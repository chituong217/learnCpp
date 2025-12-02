#include <stdio.h>

int partition(int a[], int l, int r){
	int pivot = a[r];
	int i=l-1;
	for (int j = l; j < r; j++){
		if (a[j] <= pivot){
			++i;
			int tmp =a[i]; a[i] =a[j]; a[j] = tmp;
		}
	}
	i++;
	int tmp = a[i]; a[i] = a[r]; a[r] = tmp;
	return i;
}

void quickSort(int a[], int l, int r){
	if (l < r){
		int p = partition(a, l, r);
		quickSort(a, l, p-1);
		quickSort(a, p+1, r);
	}
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	quickSort(a, 0, n-1);
	int small = k < n-k ? k : n-k;
	int big = k > n-k ? k : n-k;
	long long hieu=0;
	for (int i=0; i< small; i++){
		hieu -= a[i];
	}
	for (int i=small; i<n; i++){
		hieu += a[i];
	}
	printf("%lld", hieu);
	return 0;
}
