#include <stdio.h>

long long ucln(long long a, long long b){
	if (b==0) return a;
	else return ucln (b, a%b);
}

int main(){
	long long a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld %lld", ucln(a,b), a/ucln(a,b)*b);
	return 0;
}
