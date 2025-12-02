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
int dem[10000000]={0};

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	qsort(a, n, sizeof(int), comp);
	int cnt=0;
	for (int i=0; i<n; i++){
		dem[a[i]]++;
	}
	for (int i = a[0]; i <= a[n-1]; i++){
		if (dem[i]==0) cnt++;
	}
	printf("%d", cnt);
	return 0;
}
