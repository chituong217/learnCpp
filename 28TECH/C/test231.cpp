#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//	Ham check co phai xau thuan nghich khong
int isreverse(char c[]){
	int l = 0, r = strlen(c) - 1;
	while (l <= r){
		if (c[l] != c[r]){
			return 0;
		}
		l++;
		r--;
	}
	return 1;
}

//	Ham comp so sanh chieu dai cua 2 xau ki tu
int lencomp(const void *a, const void *b){
	char *x = (char *)a;
	char *y = (char *)b;
	if (strlen(x) != strlen(y)){
		return strlen(x) - strlen(y);
	}
	else{
//		Neu co cung chieu dai se in ra xau co dia chi be hon, tuc la xuat hien truoc
		return x-y;
	}
}

int main(){
//	Nhap xau ki tu
	char c[100001];
	fgets(c, 100001, stdin);
	c[strlen(c) - 1] = '\0';
//	Tach cac tu thuan nghich ra va luu vao mang memo
	char memo[10000][100] = {0};
	int n=0;
	char *word = strtok(c, " ");
	while (word != NULL){
		if (isreverse(word)){
//			Kiem tra tu do da xuat hien chua?
			int checker = 1;
			for (int j=0; j<n; j++){
				if (strcmp(memo[j], word) ==0){
					checker=0;
				}
			}
			if (checker ==1){
				strcpy(memo[n++], word);
			}
		}
		word = strtok(NULL, " ");
	}
	qsort(memo, n, sizeof(memo[0]), lencomp);
	for (int i=0; i<n; i++){
		printf("%s ", memo[i]);
	}
	return 0;
}
