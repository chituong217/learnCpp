#include <stdio.h>
#define mod 1000000007

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
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	quickSort(a, 0, n-1);
	long long max=0;
	for (int i=0; i<n; i++){
		max %= mod;
		max += (1ll*a[i] * i)%mod;
	}
	max%=mod;
	printf ("%lld", max);
	return 0;
}
