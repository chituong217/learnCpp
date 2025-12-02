#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int comp1(const void *a, const void *b){
	char *x = (char *)a;
	char *y = (char *)b;
	return strcmp(x, y);
}

int comp2(const void *a, const void *b){
	char *x = (char *)a;
	char *y = (char *)b;
	if (strlen(x) != strlen(y)){
		return strlen(x) - strlen(y);
	}
	else return strcmp(x, y);
}

int main(){
	char c[100001];
	fgets(c, 100001, stdin);
	c[strlen(c) - 1] = '\0';
	char memo[10000][100];
//	Tach cac tu bang strtok va luu vao mang memo
	int n=0;
	char *word = strtok(c, " ");
	while (word != NULL){
		strcpy(memo[n++], word);
		word = strtok(NULL, " ");
	}
//	Sap xep mang memo theo thututudien = ham qsort
	qsort(memo, n, sizeof(memo[0]), comp1);
	for (int i=0; i<n; i++){
		printf("%s ", memo[i]);
	}
	printf("\n");
//	Sap xep mang memo theo thu tu chieu dai tang dan
	qsort(memo, n, sizeof(memo[0]), comp2);
	for (int i=0; i<n; i++){
		printf("%s ", memo[i]);
	}
	return 0;
}
