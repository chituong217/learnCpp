#include <stdio.h>
#include <stdlib.h>

int binarySearch(int a[], int l, int r, int x){
	if (l <= r){
		int m = (l+r)/2;
		if ( a[m] == x) return 1;
		else if ( a[m] < x) return binarySearch(a, m+1, r, x);
		else return binarySearch(a, l, m-1, x);
	}
	return 0;
}

int comp(const void *a, const void *b){
	int *x = (int *)a;
	int *y = (int *)b;
	return *x - *y;
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	qsort(a, n, 4, comp);
	int q;
	scanf("%d", &q);
	for (int i=1; i<=q; i++){
		int x;
		scanf("%d", &x);
		if (binarySearch(a, 0, n-1, x)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
