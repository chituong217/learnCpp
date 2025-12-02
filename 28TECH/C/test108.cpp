#include <stdio.h>
#define ll long long

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n;i++){
		scanf("%d", &a[i]);
	}
	ll chan=0, le=0, sumc=0, suml=0;
	for (int i=0; i<n; i++){
		if (a[i]%2==0){
			chan++;
			sumc+=a[i];
		}
		else {
			le++;
			suml+=a[i];
		}
	}
	printf("%lld\n%lld\n%lld\n%lld\n", chan, le, sumc, suml);
	return 0;
}
