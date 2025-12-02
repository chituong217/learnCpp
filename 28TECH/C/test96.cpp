#include <stdio.h>
#define ll long long

void hexa(ll n){
	if (n>=16){
		hexa(n/16);
		if (n%16 <10){
			printf("%lld", n%16);
		}
		else printf("%c", (int)(n%16 + 55));
	}
	else {
		if (n<10) printf("%lld", n);
		else printf("%c", (int)(n+ 55));
	}
}

int main(){
	ll n;
	scanf("%lld", &n);
	hexa(n);
	return 0;
}
