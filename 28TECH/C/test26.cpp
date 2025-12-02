#include <stdio.h>
int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	int max = n;
	int min;
	int du = m- min%m;	
	int duu;

	if (n%2==0){
		int min = n/2;
	}
	else
		int min = n/2 +1;
	if (min%m==0){
		printf("%d", min);
	}
	else {
		if (du%2==0){
			int duu = du/2;
	}
		else
		int duu = du/2 +1;
	}
		printf("%d", min + duu);
	
}
