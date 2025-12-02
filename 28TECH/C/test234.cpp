#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//	Sap xep cac tu trong mang memo theo thu tu tu dien, dung ham comparator
int comp(const void *a, const void *b){
	char *x = (char *)a;
	char *y = (char *)b;
	return strcmp(x, y);
}

char memo[10000][1000] = {0};

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
		strcpy(memo[n++], word);
		word = strtok(NULL, " ");
	}
//	Sort mang memo theo thu tu tu dien
	qsort(memo, n, sizeof(memo[0]), comp);
//	Tim tri so max, min
	int min = 1e9, max = -1e9, imin=0, imax=0;
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
//		Chi so cua max va min
		if (cnt <= min){
			min = cnt;
			imin = i;
		}
		if (cnt >= max){
			max = cnt;
			imax = i;
		}
	}
//	In ra tu co chi so max va min va tan suat xuan hien
	for (int i=n-1; i>=0; i--){
		if (i == imax){
			printf("%s %d\n", memo[i], max);
			break;
		}
	}
	for (int i=n-1; i>=0; i--){
		if (i == imin){
			printf("%s %d\n", memo[i], min);
			break;
		}
	}
	return 0;
}
