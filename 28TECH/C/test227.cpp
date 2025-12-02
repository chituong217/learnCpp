#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int comp(const void *a, const void *b){
	char *x = (char *)a;
	char *y = (char *)b;
	return strcmp(x, y);
}

int isreverse(char c[]){
	int l=0, r = strlen(c)-1;
	while (l <= r){
		if (c[l] != c[r]){
			return 0;
		}
		l++;
		r--;
	}
	return 1;
}

int main(){
	char c[10001];
	fgets(c, 10001, stdin);
	c[strlen(c) -1] = '\0';
	char a[1000][100];
	int n=0;
	char *word = strtok(c, " ");
	while (word != NULL){
		if (isreverse(word)){
			strcpy(a[n++], word);
		}
		word = strtok(NULL, " ");
	}
	qsort(a, n, sizeof(a[0]), comp);
	for (int i=0; i<n; i++){
		printf("%s ", a[i]);
	}
	return 0;
}
