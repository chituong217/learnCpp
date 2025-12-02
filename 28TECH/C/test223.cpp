#include <stdio.h>

int main(){
	int so_xe;
	scanf("%d", &so_xe);
	int n = so_xe, sum=0;
	while (n){
		sum += n%10;
		n/=10;
	}
	printf("So nut = %d", sum%10);
	return 0;
}
