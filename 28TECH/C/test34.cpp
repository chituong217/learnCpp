#include <stdio.h>
int main (){
	int n;
	scanf("%d", &n);
	printf("%d\n", n/2);
	while (n){
		if (n==3) break;
		printf("2 ");
		n-=2;
	}
	if (n%2!=0){
		printf("3");
	}
	return 0;
}
