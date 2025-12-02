#include <stdio.h>
int main(){
	int T;
	long long kt=1;
	scanf("%d", &T);
	for (int i=1; i<=T; i++){
		int n;
		scanf("%d", &n);
		if (n%2==0){
			kt*=2;
		}
		else kt*=3;
	}
	while (kt){
		if (kt%2==0){
			printf("EVEN\n");
			kt/=2;
		}
		else if (kt%2!=0){
			printf("ODD\n");
			kt/=3;
		}
	}
	return 0;
}
