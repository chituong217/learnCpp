#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int comp(const void *a, const void *b){
	int *x = (int *)a;
	int *y = (int *)b;
	return *y - *x;
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	qsort(a, n, 4, comp);
	
	int h = a[0];
	int ans =1;
	for (int i=1; i<n; i++){
		if (h <=0) break;
		ans ++;
		h = fmin( h-1, a[i]);
	}
	printf("%d", ans);
	return 0;
}
