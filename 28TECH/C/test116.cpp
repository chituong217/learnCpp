#include <stdio.h>
#define ll long long 

int ktFibo(ll n){
	if (n==0 || n==1) return 1;
	ll f1=0;
	ll f2=1;
	ll f;
	for (ll i=2; i<=92; i++){
		f= f1+f2;
		if (n==f) return 1;
		f1=f2;
		f2=f;
	}
	 return 0;
}

void kt(ll a[], ll n){
	for (ll i=0; i<n; i++){
		if (ktFibo(a[i])==1) printf("%lld ", a[i]);
	}
}

int main(){
	ll n;
	scanf("%lld", &n);
	ll a[n];
	for (ll i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	kt(a, n);
	return 0;
}
