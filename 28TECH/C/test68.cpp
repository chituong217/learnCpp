#include <stdio.h>
#include <math.h>
#define ll long long 

int main(){
	ll cnt=0;
	ll a, b;
	scanf("%lld %lld", &a, &b);
	for (ll i=ceil(sqrt(a)); i<=sqrt(b); i++){
		cnt++;
	}
	printf("%lld", cnt);
	return 0;
}
