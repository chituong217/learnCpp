#include <stdio.h>
#include <math.h>

int a[501][501];
int n, m;
int dx[4]= {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void loang(int a[][501], int i, int j, int *cnt){
	a[i][j] = 0;
	for (int k = 0; k<4; k++){
		int i1 = i + dx[k], j1 = j + dy[k];
		if (i1 >= 0 && j1 >= 0 && i1 <n && j1 < m && a[i1][j1] == 1){
			*cnt = *cnt +1;
			loang(a, i1, j1, cnt);
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	int max = 0;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (a[i][j] == 1){
				int cnt = 1;
				loang (a, i, j, &cnt);
				max = fmax(max, cnt);
			}
		}
	}
	printf("%d", max);
	return 0;
}
