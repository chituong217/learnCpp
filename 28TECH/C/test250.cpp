#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char a[10000][1000];

int comp(const void *a, const void *b){
	char *x = (char *)a;
	char *y = (char *)b;
	char xy[1000], yx[1000];
	strcpy(xy, x); strcat(xy, y);
	strcpy(yx, y);strcat(yx, x);
	return strcmp(yx, xy);
}

int main(){
	char c[100005];
	scanf("%s", c);
	for (int i=0; i<strlen(c); i++){
		if (isalpha(c[i])){
			c[i] = ' ';
		}
	}
	char *token = strtok(c, " ");
	int n=0; 
	while (token != NULL){
//		Loai bo cac so 0 o dau
		int idx = -1;
		for (int i=0; i<strlen(token); i++){
			if (token[i] != '0'){
				idx = i;
				break;
			}
		}
		if (idx == -1){
			strcpy(a[n], "0");
			++n;
		}
		else{
			int pos = 0;
			for (int i=idx; i<strlen(token); i++){
				a[n][pos] = token[i];
				pos++;
			}
			a[n][pos] = '\0';
			n++;
		}
		token = strtok(NULL, " ");
	}
	qsort(a, n, sizeof(a[0]), comp);
	for (int i=0; i<n; i++){
		printf("%s", a[i]);
	}
	
	return 0;
}
