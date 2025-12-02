#include <stdio.h>
#define ll long long

void change(ll a[], ll n){
	ll f[n];
	for (ll i=0; i<n; i++){
		f[i]=0;
		for (ll j=0; j<=i; j++){
			f[i]+= a[j];
		}
	}
	for (ll i=0; i<n; i++){
		printf("%lld ", f[i]);
	}
}


int main(){
	ll n;
	scanf("%lld", &n);
	ll a[n];
	for (ll i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	change(a, n);
	return 0;
}
