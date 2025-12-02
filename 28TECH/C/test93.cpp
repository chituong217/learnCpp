#include <stdio.h>
#include <math.h>
#define ll long long
#define mod 1000000007

ll lt(ll a, ll b){
	if (b==0) return 1;
	ll X = lt(a, b/2);
	if (b%2==0) return X*X%mod;
	else if (b%2==1) return X*X%mod*a%mod;
}

int main(){
	ll a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld", lt(a, b));
	return 0;
}
