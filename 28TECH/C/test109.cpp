#include <stdio.h>
#include <math.h>
#define ll long long

int snt(int n){
	if (n<2) return 0;
	for (int i=2;i <=sqrt(n); i++){
		if (n%i==0) return 0;
	}
	return 1;
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	ll sum=0;
	ll dem=0;
	for (int i=0; i<n; i++){
		if (snt(a[i])==1){
			
			sum+= a[i];
			++dem;
		}
	}
	double tbc= (1.00*sum)/(1.00*dem);
	printf("%.3lf", tbc);
	return 0;
}
