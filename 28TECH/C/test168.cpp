#include <stdio.h>
#define ll long long

int main(){
	ll n;
	ll cnt=0;
	scanf("%lld", &n);
	int a[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
	for (int i=0; i<10; i++){
		if (n==0) break;
		if (n>= a[i]){
			cnt += n/a[i];
			n%=a[i];
		}
	}
	printf("%lld", cnt);
	return 0;
}
