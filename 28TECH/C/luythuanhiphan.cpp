#include <stdio.h>

long long lt (int a, int b){
	long long res =1;
	while (b){
		if (b%2==1){
			res*=a;
		}
		b/=2;
		a*=a;
	}
	return res;
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%lld", lt(a,b));
	return 0;
}
