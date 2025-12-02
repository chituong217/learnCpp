#include <stdio.h>

void nhap(int a[][500], int n, int m){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
		}
	}
}

void in(int a[][500], int n, int m){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int a[n][500], b[n][500];
	nhap(a, n, m);
	nhap(b, n, m);
	int c[n][500];
	for (int i=0; i<n; i++){
		for (int j = 0; j < m; j++){
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	in(c, n, m);
	return 0;
}
