#include <stdio.h>

void merge(int b[], int c[], int m, int n){
	int i=0, j=0;
	while (i < m && j < n){
		if (b[i] <= c[j]){
			printf("b%d ", i+1);
			i++;
		}
		else{
			printf("c%d ", j+1);
			j++;
		}
	}
	while (i<m){
		printf("b%d", i+1);
		i++;
	}
	while (j<n){
		printf("c%d", j+1);
		j++;
	}
}

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	int b[m], c[n];
	for (int i=0; i<m; i++){
		scanf("%d", &b[i]);
	}
	for (int i=0; i<n; i++){
		scanf("%d", &c[i]);
	}
	merge(b, c, m, n);
	return 0;
}
