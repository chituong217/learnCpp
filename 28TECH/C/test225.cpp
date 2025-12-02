#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void ssort(char a[][100], int n){
	for (int i=0; i<n; i++){
		int min_pos = i;
		for (int j=i+1; j<n; j++){
			if ( strcmp(a[min_pos], a[j]) != -1){
				min_pos = j;
			}
		}
		char tmp[100];
		strcpy (tmp, a[i]);
		strcpy (a[i], a[min_pos]);
		strcpy (a[min_pos], tmp);
	}
}

int comp(const void *a, const void *b){
	char *x = (char *)a;
	char *y = (char *)b;
	return strcmp(x, y);
}

int main(){
	char c[10001];
	fgets(c, 10001, stdin);
	c[strlen(c) - 1] = '\0';
	char a[100][100];
	int n=0;
	char *word = strtok(c, " ");
	while (word != NULL){
		strcpy(a[n], word);
		n++;
		word = strtok(NULL, " ");
	}
//	qsort(a, n, sizeof(a[0]), comp);
	ssort(a, n);
	for (int i=0; i <n; i++){
		printf("%s ", a[i]);
	}
	return 0;
}
