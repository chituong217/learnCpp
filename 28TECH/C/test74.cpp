#include <stdio.h>
#include <math.h>

int snt(int n){
	for (int i=2; i<=sqrt(n); i++){
		if (n%i==0) return 0;
	}
	return 1;
}

int last(int n){
	int last = n%10;
	n/=10;
	while (n){
		if (n%10 > last) return 0;
		n/=10;
	}
	return 1;
}

int main(){
	int n;
	scanf("%d", &n);
	int cnt=0;
	for (int i=2; i<=n; i++){
		if ((last(i)==1) && snt(i)==1){
			printf("%d ", i);
			cnt++;
		}
	}
	printf("\n%d", cnt);
	return 0;
}
