#include <stdio.h>
#include <math.h>
#define ll long long

ll ucln(ll a, ll b){
	while (b){
		ll r =a%b;
		a=b;
		b=r;
	}
	return a;
}

ll bcnn (ll a, ll b){
	return a/ucln(a,b) *b;
}

int main(){
	ll a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld %lld", ucln(a,b), bcnn(a, b));
	return 0;
}
