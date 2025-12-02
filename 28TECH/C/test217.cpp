#include <stdio.h>

int n, s, t, u, v;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int a[200][200];

void loang(int a[][200], int i, int j){
	a[i][j] = 0;
	if (i == u && j == v) {
		a[i][j] = 7;
		return;
	}
	for (int k=0; k<8; k++){
		int i1 = i + dx[k], j1 = j + dy[k];
		if (i1 >= 0 && j1 >= 0 && i1 < n && j1 < n && a[i1][j1] == 1){
			loang(a, i1, j1);
		}
	}
}

int main(){
	scanf("%d", &n);
	scanf("%d%d%d%d", &s, &t, &u, &v);
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	--s;--t;--u;--v;n
	loang (a, s, t);
	if (a[u][v] == 7) printf("YES");
	else printf("NO");
	return 0;
}
