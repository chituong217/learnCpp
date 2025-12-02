#include <stdio.h>
#define ll long long

void kt(ll a[], ll n){
	for (ll i=1; i<n-1; i++){
		 if ( a[i]>a[i-1] && a[i]>a[i+1]) printf("%lld ", a[i]);
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
