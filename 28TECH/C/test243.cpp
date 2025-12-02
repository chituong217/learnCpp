#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Binary Search mang ki tu
int bS(char c[][100], char x[], int n){
	int l = 0, r = n-1;
	while (l <= r){
		int m = l + (r-l)/2;
		if (strcmp(c[m], x) == 0){
			return 1;
		}
		else if (strcmp(c[m], x) == -1){
			l = m+1;
		}
		else{
			r = m-1;
		}
	}
	return 0;
}
//Function in thuong
void inthuong(char c[]){
	for (int i=0; i<strlen(c); i++){
		c[i] = tolower(c[i]);
	}
}
//Comparator
int comp(const void *a, const void *b){
	char *x = (char *)a;
	char *y = (char *)b;
	return strcmp(x, y);
}

char a1[10001][100] = {0};
char b1[10001][100] = {0}; 
char res1[10001][100] = {0};

int main(){
	char a[10001], b[10001];
	int idx1=0;
	int idx2=0;
	fgets(a, 10001, stdin);
	a[strlen(a) -1] = '\0';
	fgets(b, 10001, stdin);
	b[strlen(b) -1] = '\0';
	
//	Tach tu
	char *token = strtok(a, " ");
	while (token != NULL){
		inthuong(token);
		strcpy(a1[idx1], token);
		idx1++;
		token = strtok(NULL, " ");
	}
	token = strtok(b, " ");
	while (token != NULL){
		inthuong(token);
		strcpy(b1[idx2], token);
		idx2++;
		token = strtok(NULL, " ");
	}
	
//	Sort
	qsort(a1, idx1, sizeof(a1[0]), comp);
	qsort(b1, idx2, sizeof(b1[0]), comp);

//	Loc con xuat hien 1 lan
	int idxS=0;
	if (idx1>0){
		strcpy(res1[idxS++], a1[0]);
		for (int i=1; i<idx1; i++){
			if (strcmp(a1[i-1], a1[i]) != 0){
				strcpy(res1[idxS++], a1[i]);
			}
		}
	}
//	So sanh voi mang T
	for (int i=0; i<idxS; i++){
		if (bS(b1, res1[i], idx2) == 0){
			printf("%s ", res1[i]);
		}
	}
	
	return 0;
}
