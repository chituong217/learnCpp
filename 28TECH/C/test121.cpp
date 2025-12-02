#include <stdio.h>
#define ll long long

void max(ll a[], ll n){
	ll max1=-1e9;
	ll cs=0;
	for (ll i=0; i<n; i++){
		if (a[i]>max1){
			max1=a[i];
			cs=i;
		}
	}
	ll max2=-1e9;
	for (ll i=0; i<n; i++){
		if (i==cs) continue;
			if (a[i]>max2){
			max2=a[i];
		}
	}
	printf("%lld %lld", max1, max2);
}

int main(){
	ll n;
	scanf("%lld", &n);
	ll a[n];
	for (ll i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	max(a, n);
	return 0;
}
