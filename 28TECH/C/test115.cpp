#include <stdio.h>
#include <math.h>
#define ll long long

int snt(ll n){
	if (n<2) return 0;
	for (ll i=2; i<=sqrt(n); i++){
		if (n%i==0) return 0;
	}
	return 1;
}

void lke(int a[], ll n){
	for (ll i=0; i<n; i++){
		ll trai=0;
		ll phai=0;
		for (ll j=0; j<i; j++){
			trai+=a[j];
		}
		for (ll k=i+1; k<n; k++){
			phai+=a[k];
		}
		if (snt(trai)==1 && snt(phai)==1) printf("%lld ", i);
	}
}

int main(){
	ll n;
	scanf("%lld", &n);
	int a[n];
	for (ll i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	lke(a, n);
	return 0;
}
