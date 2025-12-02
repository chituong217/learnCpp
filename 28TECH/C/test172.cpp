#include <stdio.h>
#define ll long long
int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	int a[n];
	ll sum[n];
	sum[0]=0;
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
		sum[i+1] = sum[i] + a[i];
	}
	int l, r;
	while (q){
		q--;
		scanf("%d %d", &l, &r);
		printf("%lld\n", sum[r] - sum[l-1]);
	}
	return 0;
}
