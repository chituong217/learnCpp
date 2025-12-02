#include <stdio.h>
#include <math.h>
#include <algorithm>
int main(){
	int n;
	scanf("%d", &n);
	int giaithua=1;
	for (int i=1; i<=n; i++){
		giaithua *=i;
	}
	printf("%d", giaithua);
	return 0;
}
