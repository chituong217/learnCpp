#include <stdio.h>
#include <math.h>
int main(){
	int n;
	scanf("%d", &n);
	int dem = 0;
	for (int i=1; i<=sqrt(n); i++){
		if (n%i==0){
			dem+=1;
			if (n/i!=i){
				dem++;
			}
		}
	}
	printf("%d\n", dem);
	for (int i=1; i<=sqrt(n); i++){
		if (n%i==0){
			printf("%d ",i);
		}
	}
	for (int i=sqrt(n); i>=1; i--){
		if (n%i==0){
			if(n/i!=i){
				printf("%d ", (n/i));
			}
		}
	}
	return 0;
}
