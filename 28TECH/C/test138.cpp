#include <stdio.h>
#define ll long long
#include <algorithm>

int main(){
	int n;
	scanf("%d", &n);
	int cnt=-1;
	for (int i= n/5; i>=0; i--){
		if ((n-5*i) %3==0) {
			cnt = i + (n-5*i)/3;
			break;
		}
	}
	printf("%d", cnt);
	return 0;
}
