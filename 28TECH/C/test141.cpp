#include <stdio.h>
#include <math.h>
int m=10000000;
int prime[10000001];
void sieve(int prime[], int m){
	for (int i=0; i<m; i++){
		prime[i]=1;
	}
	prime[0]=prime[1]=0;
	for (int i=0; i<sqrt(m); i++){
		if (prime[i]==1){
			for(int j=i*i; j<=m; j+=i){
				prime[j]=0;
			}
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	sieve(prime, m);
	for (int i=0; i< n; i++){
		if (prime[a[i]]==1) printf("1 ");
		else printf("0 ");
	}
	return 0;
}
