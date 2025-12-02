#include <stdio.h>
int main(){
	int m,n,a;
	scanf("%d %d %d", &m, &n, &a);
	if (m%a==0 && n%a==0){
		printf("%lld", 1ll*(m/a)*(n/a));
}
	else if (m%a!=0 && n%a==0){
		printf("%lld", 1ll*(m/a)*(n/a) + n/a);
	}
	else if (m%a==0 && n%a!=0){
		printf("%lld", 1ll*(m/a)*(n/a) + m/a);
	}
	else if (m%a!=0 && n%a!=0){
		printf("%lld", 1ll*(m/a)*(n/a) + m/a + n/a +1);
	}
	return 0;
}
