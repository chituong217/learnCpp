#include <stdio.h>
#define ll long long

void thuan(ll n){
	if (n<10) printf("%lld ", n);
	else {
		thuan(n/10);
		printf("%lld ", n%10);
	}
}

void nghich(ll n){
	if (n<10) {
		printf("%lld ", n);
		return;
	}
	else {
		printf("%lld ", n%10);
		nghich(n/10);
	}
}

int main(){
	ll n;
	scanf("%lld", &n);
	thuan(n);
	printf("\n");
	nghich(n);
	return 0;
}
