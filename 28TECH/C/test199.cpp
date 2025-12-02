#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b){
	int *x = (int *)a;
	int *y = (int *)b;
	if ( *x < *y)
		return -1;
	else 
		return 1;
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	qsort(a, n, sizeof(int), comp);
	int p = a[0], i= 0, cnt=0;
	while (i < n){
		if ( a[i] == p){
			i++;
			p++;
		}
		else {
			cnt++;
			p++;
		}
	}
	printf("%d", cnt);
	return 0;
}
