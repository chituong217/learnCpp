#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	double tong = 0;
	for (int i=0; i<=(n-1); i++){
		if (i==0){
			tong+=1;
		}
		else {
			long long tich =1;
			for (int j=1; j<=i; j++){
				tich*=j;
			}
			tong+= 1.00/(tich);
		}
	}
	printf("%.4lf", tong);
}
