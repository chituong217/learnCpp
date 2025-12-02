#include <stdio.h>
#include <math.h>
#define ll long long

int snt(int n){
	if (n<2) return 0;
	for (int i=2; i<=sqrt(n); i++){
		if (n%i==0) return 0;
	}
	return 1;
}

int main(){
	int t,n;
	scanf("%d", &t);
	while (t){
		scanf("%d", &n);
		if (snt(n)==0){
			printf("NO\n");
		}
		else printf("YES\n");
		t--;
	}
	return 0;
}
