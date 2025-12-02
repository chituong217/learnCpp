#include <stdio.h>

double tong(int n){
	if (n==1) return 1;
	else return tong(n-1) + 1.00/n;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%.3lf", tong(n));
	return 0;
}
