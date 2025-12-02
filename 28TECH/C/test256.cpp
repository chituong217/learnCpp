#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checkReverse(char x[]){
	int l = 0, r = strlen(x)-1;
	while (l <= r){
		int sol = x[l] - '0', sor = x[r] - '0';
		if (x[l] != x[r] || sol%2!=0 || sor%2!=0){
			return 0;
		}
		l++; r--;
	}
	return 1;
}

int main(){
	char a[20];
	scanf("%s", a);
	if (checkReverse(a) == 1){
		printf("YES");
	}
	else{
		printf("NO");
	}
}
