#include <stdio.h>
#define ll long long

void hexa(ll n){
	if (n>=16){
		if (n%16 <10){
			printf("%lld", n%16);
		}
		else printf("%c", (int)n%16 + 55);
		hexa(n/16);
	}
	else printf("%lld", n);
}

int main(){
	ll n;
	scanf("%lld", &n);
	hexa(n);
	return 0;
}
