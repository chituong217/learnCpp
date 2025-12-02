#include <stdio.h>

long long th(int n, int k){
	if (k==0 || k==n) return 1;
	else return th(n-1, k-1) + th(n-1, k);
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%lld", th(n,k));
	return 0;
}
