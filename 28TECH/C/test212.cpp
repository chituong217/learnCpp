#include <stdio.h>

int loang(int a[][50], int check[], int i, int j, int moi, int old, int idx, int n, int m){
	if ( i<0 || j<0 || i>=n || j>=m){
		return 0;
	}
	if (a[i][j] == old){
		check[idx]++;
		a[i][j] = moi;
		loang(a, check, i-1, j, moi, old, idx, n, m);
		loang(a, check, i, j-1, moi, old, idx, n, m);
		loang(a, check, i, j+1, moi, old, idx, n, m);
		loang(a, check, i+1, j, moi, old, idx, n, m);
		
		loang(a, check, i-1, j-1, moi, old, idx, n, m);
		loang(a, check, i-1, j+1, moi, old, idx, n, m);
		loang(a, check, i+1, j-1, moi, old, idx, n, m);
		loang(a, check, i+1, j+1, moi, old, idx, n, m);
		return 1;
	}
	else return 0;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int a[n][50];
	int check[n*m]={0};
	int idx=0;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (loang(a, check, i, j, 7, 1, idx, n, m))
				idx++;
		}
	}
	printf("%d", idx);
	return 0;
}
