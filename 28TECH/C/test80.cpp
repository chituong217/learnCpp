#include <stdio.h>

int ktra(int n){
	while (n>=111){
		n-=111;
	}
	while (n>=11){
		n-=11;
	}
	if (n==0) return 1;
	return 0;
}

int main(){
	int n;
	scanf("%d", &n);
	if (ktra(n)==1){
		printf("YES\n");
	}
	else printf("NO\n");
	return 0;
}
