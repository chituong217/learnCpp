#include <stdio.h>

int n, m, u, v;
int a[200][200];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void loang (int a[][200], int i, int j){
	a[i][j] = 0;
	for (int k=0; k<4; k++){
		int i1 = i + dx[k], j1 = j + dy[k];
		if (i1>=0 && j1>=0 && i1<n && j1<m && a[i1][j1] == 1){
			loang(a, i1, j1);
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	int s, t;
	scanf("%d%d%d%d", &s, &t, &u, &v);
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	--u;--v;--s;--t;
	loang(a, s, t);
	if (a[u][v] == 0) printf("YES");
	else printf("NO");
	return 0;
}
