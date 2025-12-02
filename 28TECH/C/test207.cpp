#include <stdio.h>
#include <math.h>
void swap (int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int snt(int n){
	for(int i=2; i<=sqrt(n); i++){
		if (n%i==0)
			return 0;
	}
	return n>1;
}



int main(){
	int n;
	scanf("%d", &n);
	int a[n][n];
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	int cheo[500], idx=0;
	for (int i=0; i<n; i++){
		cheo[idx++] = a[i][i];
	}
	
	for (int i=0; i<n; i++){
		if (n%2==1 && i == n/2) {
			continue;
		}
		cheo[idx++] = a[i][n-i-1];
	}
	int cnt=0;
	for (int i=0; i< idx; i++){
		if (snt(cheo[i])){
			int b=0;
			for (int j=0; j<i; j++){
				if (cheo[i] == cheo[j]) b++;
			}
			if (b==0) cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}
