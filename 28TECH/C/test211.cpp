#include <stdio.h>


int main(){
	int n;
	scanf("%d", &n);
	long long a[n][n];
	
	
	
	long long fibo[81];
	long long f1 = 0;
	long long f2 = 1;
	long long f;
	fibo[0] = 0; fibo[1] = 1;
	for (int i=2; i<81; i++){
		f = f1 + f2;
		fibo[i] = f;
		f1 = f2;
		f2 = f;
	}
	
	int c1 = 0, c2 = n-1, h1 = 0, h2 = n-1;
	int dem = 0;
	while (dem < n*n){
		for (int i=c1; i <= c2; i++){
			a[h1][i] = fibo[dem++];
		}
		h1++;
		for (int i=h1; i<= h2; i++){
			a[i][c2] = fibo[dem++];
		}
		c2--;
		for (int i= c2; i>= c1; i--){
			a[h2][i] = fibo[dem++];
		}
		h2--;
		for (int i=h2; i>= h1; i--){
			a[i][c1] = fibo[dem++];
		}
		c1++;
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			printf("%lld ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
