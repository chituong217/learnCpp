#include <stdio.h>
#include <math.h>

int snt(int n){
	for (int i=2; i<=sqrt(n); i++){
		if (n%i==0) return 0;
	}
	return 1;
}

int tong(int n){
	int tong=0;
	while(n){
		tong+= n%10;
		n/=10;
	}
	return tong;
}


int smith(int n){
	if(snt(n)==1) return 0;
	int tong1=0, tong2=0;
	tong1 = tong(n);
	
	for (int i=2; i<=sqrt(n); i++){
		if (n%i==0){
			while(n%i==0);
			tong2 += tong(i);
			n/=i;
		}
	}
	
	return tong2==tong1;
}

int main(){
	int n;
	scanf("%d", &n);
	if (smith(n)==1){
		printf("YES");
	}
	else printf("NO");
	return 0;
}
