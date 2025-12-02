#include <stdio.h>
#include <math.h>

int snt(int n){
	for (int i=2; i<=sqrt(n); i++){
		if (n%i==0){
			return 0;
		}
	}
	return n>1;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int a[n][m];
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	int max_val = -1e9, min_val = 1e9;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			max_val = fmax(max_val, a[i][j]);
			min_val = fmin(min_val, a[i][j]);
		}
	}
	printf("%d %d", min_val, max_val);
	return 0;
}
