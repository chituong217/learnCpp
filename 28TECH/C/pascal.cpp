#include <stdio.h>

long long th(int k, int n){
	long long th=1;
	for (int i=1; i<=k; i++){
		th *=(n-i+1);
		th /= i;
	}
	return th;
}

void pascal(int cc){
	for (int i=0; i<cc; i++){
		for (int j=0; j<=i; j++){
			printf("%lld ", th(j, i));
		}
		printf("\n");
	}
}

int main(){
	int cc; 
	scanf("%d", &cc);
	pascal(cc);
	return 0;
}
