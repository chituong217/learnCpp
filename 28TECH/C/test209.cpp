#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b){
	int *x = (int *)a;
	int *y = (int *)b;
	if (*x < *y) return -1;
	else return 1;
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n][n];
	for(int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	int b[n][n];
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			b[i][j] = a[j][i];
		}
	}
	
	
	
	
	
	
	for (int i=0; i<n; i++){
		qsort(b[i], n, sizeof(int), comp);
	}
	for(int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			printf("%d ", b[j][i]);
		}
		printf("\n");
	}
	return 0;
}
