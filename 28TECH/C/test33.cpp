#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	if (n%2==0){
		printf("%d\n", n/2);
		while (n){
			printf("2 ");
			n-=2;
		}
	}
	else if (n%2!=0){
		printf("%d\n", n/2);
		while (n){
			if (n==3){
				n-=3;
				printf("3 ");
				continue;
			}
			n-=2;
			printf("2 ");
		}
	}
	else {
		printf("-1");
	}
	return 0;
}
