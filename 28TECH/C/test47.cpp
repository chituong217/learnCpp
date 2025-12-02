#include <stdio.h>

double tong (int n){
	double tong=0;
	for (int i=1; i<=n; i++){
		tong += 1.00/i;
	}
	return tong;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%.2lf", tong(n));
	return 0;
}
