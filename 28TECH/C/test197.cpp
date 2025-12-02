#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b){
	int *x = (int *)a;
	int *y = (int *)b;
	if ( *x < *y) return -1;
	else return 1;
}

int main(){
	int n;
	scanf("%d", &n);
	int start[n];
	int end[n];
	for (int i=0; i<n; i++){
		scanf("%d %d", &start[i], &end[i]);
	}
	qsort(end, n, sizeof(int), comp);
	int cnt =1;
	int point = end[0];
	for (int i=1; i<n; i++){
		if ( start[i] > point){
			cnt++;
			point = end[i];
		}
	}
	printf("%d", cnt);
	return 0;
}
