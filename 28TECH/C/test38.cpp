#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int dem = 1;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			printf("%d ", dem);
			++dem;
		}
		printf("\n");
	}
	printf("\n");
	
	
	dem =1;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			printf("%d ", dem);
			++dem;
		}
		printf("\n");
		dem = i+1;
	}
	printf("\n");
	
	for (int i=1; i<=n; i++){
		for (int k=n-i; k>=1; k--){
			printf("~");
		}
		for (int j=1; j<=i; j++){
			printf("%d", i);
		}
		printf("\n");
	}
	printf("\n");
	
	for (int i=1; i<=n; i++){
		int dem =i;
		int dan =n;
		for (int j=1; j<=i; j++){
			if (j==1){
				printf("%d ", dem);
			} else{
				--dan;
				dem += dan;
			printf("%d ", dem);
			}
		}
		printf("\n");
	}
	printf ("\n");
	return 0;
}
