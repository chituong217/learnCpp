#include <stdio.h>
#define ll long long

void kt(ll a[], ll n){
	if (a[0]*a[1]<0) printf("%lld ", a[0]);
	for (ll i=1; i<n-1; i++){
		 if ( a[i]*a[i-1]<0 || a[i]*a[i+1]<0) printf("%lld ", a[i]);
	}
	if (a[n-1]*a[n-2]<0) printf("%lld ", a[n-1]);
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
