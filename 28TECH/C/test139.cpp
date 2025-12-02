#include <stdio.h>
#include <math.h>

int dem(int n){
	int dem =0;
	while (n){
		dem++;
		n/=10;
	}
	return dem;
}

int tong(int n){
	int tong=0;
	while(n){
		tong+=n%10;
		n/=10;
	}
	return tong;
}

int main(){
	int n;
	scanf("%d", &n);
	int kq=0;
	for (int i = n- 9*dem(n); i<n; i++){
		if (n== i + tong(i)){
			kq=i;
			break;
		}
	}
	printf("%d", kq);
	return 0;
}
