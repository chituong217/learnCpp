#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int check[100001] = {0};

int comp(const void *a, const void *b){
	int *x = (int *)a;
	int *y = (int *)b;
	if ( *x < *y) return -1;
	else return 1;
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n][n];
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	int found_any = 0;
	qsort(a[0], n, sizeof(int), comp);
	for (int i=0; i<n; i++){
		if (i>0 && a[0][i] == a[0][i-1]) continue;
		int ans = a[0][i];
		
		int foundinallrow=1;
		for (int j=1; j<n; j++){
			int foundinrow=0;
			for (int k=0; k<n; k++){
				if (a[j][k] == ans){
					foundinrow = 1;
					break;
				}
			}
			if (foundinrow == 0) {
				foundinallrow=0;
				break;
			}
		}
		if (foundinallrow == 1){
			printf("%d ", ans);
			found_any++;
		}
	}
	if (found_any ==0) printf("NOT FOUND");
	
	return 0;
}
