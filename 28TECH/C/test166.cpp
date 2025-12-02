#include <stdio.h>
#include <math.h>

int snt(int n){
	if (n<2) return 0;
	for (int i=2; i<=sqrt(n); i++){
		if (n%i==0) return 0;
	}
	return 1;
}

int main(){
	int n=0, tmp;
	int val[10001]={0};
	int cnt[10001]={0};
	while (scanf("%d", &tmp) != -1){
		if (snt(tmp)==1){
			int first=0;
			for (int i=0; i<n; i++){
				if (val[i]==tmp){
					cnt[i]++;
					first=1;
					break;
				}
			}
			if (first == 0){
				val[n] = tmp;
				cnt[n] =1;
				n++;
			}
		}
	}
	for (int i=0; i<n; i++){
		printf("%d %d\n", val[i], cnt[i]);
	}
	return 0;
}
