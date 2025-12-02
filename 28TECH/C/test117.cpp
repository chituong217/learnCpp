#include <stdio.h>
#define ll long long

void min(ll a[], ll n){
	ll min=1e9;
	for (ll i=0; i<n; i++){
		if (a[i]<min){
			min = a[i];
		}
	}
	for (ll i=0; i<n; i++){
		if (a[i]==min){
			int test=0;
			for (ll j=i+1; j<n; j++){
				if (a[j]==min) test++;
			}
			if (test<1) printf("%lld ", i);
		}
	}
}

void max(ll a[], ll n){
	ll max= -1e9;
	for (ll i=0; i<n; i++){
		if (a[i]>max) max=a[i];
	}
	for (ll i=0; i<n; i++){
		if (a[i]==max){
			int test=0;
			for (ll j=0; j<i; j++){
				if (a[j]==max) test++;
			}
			if (test<1) printf("%lld ", i);
		}
	}
}

int main(){
	ll n;
	scanf("%lld", &n);
	ll a[n];
	for (ll i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	min(a, n);
	max(a, n);
}
