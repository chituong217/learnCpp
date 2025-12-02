#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
//	Nhap vao 2 xau ki tu
	char c1[100001], c2[100001];
	fgets(c1, 100001, stdin);
	fgets(c2, 100001, stdin);
	c1[strlen(c1) - 1] = '\0';
	c2[strlen(c2) - 1] = '\0';
//	Tao 2 mang de luu cac ki tu
	int memo1[256] = {0}, memo2[256] = {0};
//	Luu vao 2 mang
	for (int i=0; i<strlen(c1); i++){
		memo1[c1[i]] = 1;
	}
	for (int i=0; i<strlen(c2); i++){
		memo2[c2[i]] = 1;
	}
//	Kiem tra va in ra ki tu xuat hien o xau 1 ma khong xuat hien o xau 2
	for (int i=0; i<256; i++){
		if (memo1[i] == 1 && memo2[i] == 0){
			printf("%c", i);
		}
	}
	printf("\n");
//	Kiem tra va in ra ki tu xuat hien o xau 2 ma khong xuat hien o xau 1
	for (int i=0; i<256; i++){
		if (memo1[i] == 0 && memo2[i] == 1){
			printf("%c", i);
		}
	}
	return 0;
}
