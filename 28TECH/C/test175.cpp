#include <stdio.h>
#define ll long long

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	int len=1;
	ll cnt=a[0];
	int len1=1;
	ll cnt1=a[0];
	int l=0, r=0;
	int start=0;
	for (int i=1; i<n; i++){
		if (a[i]!=a[i-1]){
			len++;
			cnt+=a[i];
		}
		else{
			if (len > len1 || (len == len1 && cnt > cnt1)){
				cnt1=cnt;
				l=start;
				r=i-1;
				len1=len;
			}
				cnt=a[i];
				start=i;
				len=1;
			}
		}
	
	if (len > len1 || (len == len1 && cnt > cnt1)){
		cnt1=cnt;
		l=start;
		r=n-1;
		len1=len;
	}
	
	printf("%d\n", len1);
	for (int i=l; i<=r; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
