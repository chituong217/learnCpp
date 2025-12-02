#include <stdio.h>
#define ll long long

void trans(ll n){
	if (n){
		trans(n/2);
		printf("%lld", n%2);
	}
}

int main(){
	ll n;
	scanf("%lld", &n);
	trans(n);
	if (n==0) printf("0");
	return 0;
}
