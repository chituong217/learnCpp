#include <stdio.h>
#include <math.h>

int untln(int n){
	int uoc =0;
	for (int i=2; i<=sqrt(n); i++){
		if (n%i==0){
			while(n%i==0){
				uoc = i;
				n/=i;
			}
		}
	}
	if (n!=1) uoc=n;
	return uoc;
}

int main(){
	int t,n;
	scanf("%d", &t);
	while(t){
		scanf("%d", &n);
		printf("%d\n", untln(n));
		t--;
	}
	return 0;
}
