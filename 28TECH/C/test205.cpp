#include <stdio.h>
#include <math.h>

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int a[n][m];
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	int min = 1e9;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			min = fmin(min, a[i][j]);
		}
	}
	printf("%d\n", min);
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (min == a[i][j]){
				printf("%d %d\n", i+1, j+1);
			}
		}
	}
	
	int max = -1e9;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			max = fmax(max, a[i][j]);
		}
	}
	printf("%d\n", max);
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (max == a[i][j]){
				printf("%d %d\n", i+1, j+1);
			}
		}
	}
	
	return 0;
}
