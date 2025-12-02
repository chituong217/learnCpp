#include <stdio.h>
#include <math.h>

long long tong(int n){
	if (n==1) return -1;
	else if (n%2==0) return n + tong(n-1);
	else if (n%2!=0) return  tong(n-1) - n;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%lld", tong(n));
	return 0;
}
