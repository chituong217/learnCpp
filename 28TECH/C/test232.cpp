#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//	Sap xep cac tu trong mang memo theo thu tu tu dien, dung ham comparator
int comp(const void *a, const void *b){
	char *x = (char *)a;
	char *y = (char *)b;
	return strcmp(x, y);
}

char memo[10000][1000] = {0}, memo1[10000][1000] = {0};

int main(){
//	Nhap vao xau ki tu c
	char c[100001];
	fgets(c, 100001, stdin);
//	Cho ki tu enter ma fgets lum phai tro thanh NULL '\0'
	c[strlen(c) - 1] = '\0';
	int n = 0;
//	Tach cac tu bang strtok va luu vao mang memo va mang memo1
	char *word = strtok(c, " ");
	while (word != NULL){
		strcpy(memo1[n], word);
		strcpy(memo[n++], word);
		word = strtok(NULL, " ");
	}
//	Sort mang memo theo thu tu tu dien
	qsort(memo, n, sizeof(memo[0]), comp);
//	In ra mang memo theo thu tu tu dien
	for (int i=0; i<n; i++){
//		Neu da tung xuat hien truoc do roi thi bo qua
		int checker = 1;
		for (int j=0; j<i; j++){
			if (strcmp(memo[i], memo[j]) == 0){
				checker = 0;
			}
		}
		if (checker == 0){
			continue;
		}
//		Dem so lan xuat hien phia sau no
		int cnt = 1;
		for (int j=i+1; j<n; j++){
			if (strcmp(memo[i], memo[j]) == 0){
				cnt++;
			}
		}
		printf("%s %d\n", memo[i], cnt);
	}
	printf("\n");
//	In ra mang memo1 theo thu tu xuat hien tang dan
	for (int i=0; i<n; i++){
//		Neu da tung xuat hien truoc do roi thi bo qua
		int checker = 1;
		for (int j=0; j<i; j++){
			if (strcmp(memo1[i], memo1[j]) == 0){
				checker = 0;
			}
		}
		if (checker == 0){
			continue;
		}
//		Dem so lan xuat hien phia sau no
		int cnt = 1;
		for (int j=i+1; j<n; j++){
			if (strcmp(memo1[i], memo1[j]) == 0){
				cnt++;
			}
		}
		printf("%s %d\n", memo1[i], cnt);
	}
	return 0;
}
