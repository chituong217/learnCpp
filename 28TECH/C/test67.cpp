#include <stdio.h>
#include <math.h>
#define ll long long

int scp(ll n){
	if ((ll)sqrt(n)*sqrt(n) == n){
		return 1;
	}
	else return 0;
}

int main(){
	ll n;
	scanf("%lld", &n);
	if (scp(n)==1) printf("YES\n");
	else printf("NO\n");
	return 0;
}
