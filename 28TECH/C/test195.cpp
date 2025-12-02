#include <stdio.h>
#include <stdlib.h>

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
	long long milk = 0;
	int i =0;
	for (int j=0; j<n; j++){
		if ( a[j] - i < 0) break;
		milk += a[j] - i;
		i++;
	}
	printf("%lld", milk);
	return 0;
}
