#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int comp(const void *a, const void *b){
	int *x = (int *)a;
	int *y = (int *)b;
	if ( *x < *y) return -1;
	else return 1;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int *a = (int *) malloc (n * sizeof(int));
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	qsort(a, n, sizeof(int), comp);
	int cnt=1;
	for (int i=1; i<n; ++i){
		if (abs(a[i] - a[i-1]) > k){
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
