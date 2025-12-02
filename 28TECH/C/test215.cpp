#include <stdio.h>
#include <math.h>
int n, m;

int main(){
	scanf("%d%d", &n, &m);
	int a[n][m];
	long long b[n][m];
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (i==0 && j==0) b[i][j] = a[i][j];
			else if (i==0) b[i][j] = b[i][j-1] + a[i][j];
			else if (j==0) b[i][j] = b[i-1][j] + a[i][j];
			else b[i][j] = fmax(b[i-1][j], b[i][j-1]) + a[i][j];
		}
	}
	printf("%lld", b[n-1][m-1]);
	return 0;
}
