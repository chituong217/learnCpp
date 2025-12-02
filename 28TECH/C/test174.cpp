#include <stdio.h>

int dem[1000000]={0};
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	int object1[10000]={0};
	int object2[10000]={0};
	int idx=0;
	int start =0;
	for (int i=0; i<n; i++){
		for (int j=0; j<i; j++){
			if (a[i]==a[j]){
				object1[idx]=start;
				object2[idx]=i;
				idx++;
				start=i+1;
			}
		}
		dem[idx]++;
	}
	int max=-1e9;
	for (int i=0; i<=idx; i++){
		if (dem[i]>max) max = dem[i];
	}
	int pos;
	long long sum =0;
	long long tmp;
	for (int i=0; i<=idx; i++){
		if (dem[i]==max){
			tmp=0;
			for (int j= object1[i]; j< object2[i]; j++){
				tmp += a[j];
			}
			if (tmp > sum){
				sum = tmp;
				pos = i;
			}
		}
	}
	
	printf("%d\n", dem[pos]);
	for (int i = object1[pos]; i< object2[pos]; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
