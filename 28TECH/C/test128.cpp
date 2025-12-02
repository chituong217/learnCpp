#include <stdio.h>
#define ll long long

void del(ll a[], ll n, ll x){
	int find=1e9;
	for (ll i=0; i<n; i++){
		if (a[i]==x){
			find= i;
			break;
		}
	}
	if (find==1e9) {
		printf("NOT FOUND");
		return;
	}
	for (ll i=find; i<n; i++){
		a[i]= a[i+1];
	}
	n--;
	for (ll i=0; i<n; i++){
		printf("%lld ", a[i]);
	}
}


int main(){
	ll n, x;
	scanf("%lld %lld", &n, &x);
	ll a[n];
	for (ll i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	del(a, n, x);
	return 0;
}
