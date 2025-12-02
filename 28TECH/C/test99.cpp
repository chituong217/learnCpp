#include <stdio.h>
#define ll long long

int tong(ll n){
	if (n<10) return n;
	else return tong(n/10) +n%10;
}

int main(){
	ll n;
	scanf("%lld", &n);
	printf("%d", tong(n));
	return 0;
}
