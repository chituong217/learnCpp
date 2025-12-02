#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>


int main(){
	char c[100001];
	int memo[256] = {0};
	fgets(c, 100001, stdin);
	c[strlen(c) - 1] = '\0';
	int min = 1e9, max = -1e9;
//	luu vao mang ki tu
	for (int i=0; i<strlen(c); i++){
		memo[c[i]]++;
	}
//	tim kiem chi so min max
	for (int i=0; i<256; i++){
		if (memo[i] > 0){
			min = fmin(min, memo[i]);
			max = fmax(max, memo[i]);
		}
	}
//	In ra cac ki tu co chi so = min va max
	for (int i=255; i>=0; i--){
		if ( memo[i] == max){
			printf("%c %d", i, memo[i]);
			break;
		}
	}
	
	printf("\n");
	
	for (int i=255; i>=0; i--){
		if ( memo[i] == min){
			printf("%c %d", i, memo[i]);
			break;
		}
	}
	return 0;
}
