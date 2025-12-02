#include <stdio.h>

void merge(int a[], int b[], int n, int m){
	int i=0, j=0;
	while (i<n && j<m){
		if (a[i] <= b[j]){
			printf("%d ", a[i++]);
		}
		else printf("%d ", b[j++]);
	}
	while (i<n){
		printf("%d ", a[i++]);
	}
	while (j<n){
		printf("%d ", b[j++]);
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int a[n], b[m];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for (int i=0; i<m; i++){
		scanf("%d", &b[i]);
	}
	merge (a, b, n, m);
	return 0;
}
