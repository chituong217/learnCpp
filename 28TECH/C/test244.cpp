#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int comp(const void *a, const void *b){
	char *x = (char *)a;
	char *y = (char *)b;
	char xy[1000];
	strcpy(xy, x);
	strcat(xy, y);
	char yx[1000];
	strcpy(yx, y);
	strcat(yx, x);
	return strcmp(yx, xy);
}

int main(){
	int n;
	scanf("%d", &n);
	char a[1000][1000] = {0};
	for (int i=0; i<n; i++){
		scanf("%s", a[i]);
	}
	qsort(a, n, sizeof(a[0]), comp);
	for (int i=0; i<n; i++){
		printf("%s", a[i]);
	}
	return 0;
}
