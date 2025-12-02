#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int comp(const void *a, const void *b){
	char *x = (char *)a;
	char *y = (char *)b;
	if (strlen(x) != strlen(y))
		return strlen(x) - strlen(y);
	else
		return strcmp(x, y);
}

int main(){
	char c[10001];
	fgets(c, 10001, stdin);
	c[ strlen(c) - 1] = '\0';
	int n=0;
	char a[1000][100];
	char *word = strtok(c, " ");
	while (word != NULL){
		strcpy(a[n++], word);
		word = strtok(NULL, " ");
	}
	qsort(a, n, sizeof(a[0]), comp);
	for (int i=0; i<n; i++){
		printf("%s ", a[i]);
	}
	
	return 0;
}
