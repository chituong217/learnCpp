#include <stdio.h>
#include <math.h>

int snt(int n){
	if (n<2) return 0;
	for (int i=2; i<=sqrt(n); i++){
		if (n%i==0){
			return 0;
		}
	}
	return 1;
}

void goldbach (int n){
	for (int i=1; i<=(n/2); i++){
		if (snt(i)==1){
			int q = n-i;
			if (snt(q)==1){
				printf("%d %d\n", i, q);
			}
		}
	}
}

int main (){
	int t, n;
	scanf("%d", &t);
	while (t){
		scanf("%d", &n);
		goldbach(n);
		t--;
	}
	return 0;
}
