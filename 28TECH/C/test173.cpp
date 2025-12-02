#include <stdio.h>
#include <math.h>
int cnt[1000001];

long long th(int n, int k){
	k = fmin(k, n-k);
	long long tich =1;
	for (int i=1; i<=k; i++){
		tich *= (n-i+1);
		tich/=i;
	}
	return tich;
}


int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	int max=-1e9;
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
		cnt[a[i]]++;
		if (a[i] >max) max=a[i];
	}
	long long dem=0;
	for (int i=0; i<=max; i++){
		if (cnt[i]>=2){
			dem += th(cnt[i], 2);
		}
	}
	printf("%lld", dem);
	return 0;
}
