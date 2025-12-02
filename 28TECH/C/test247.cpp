#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
typedef struct find find;

struct find{
	char ch[10000];
	int len;
};

find a[100005] = {0};
int idx = 0;

int comp(const void *a, const void *b){
	find *x = (find *)a;
	find *y = (find *)b;
	return strcmp((x->ch), (y->ch));
}

int main(){
	char c[100005];
	fgets(c, 100005, stdin);
	c[strlen(c) -1] = '\0';
	char name[10000] = {0};
	int cnt=0;
	for (int i=1; i<strlen(c); i++){
		if (i==0 || c[i] == c[i-1]){
			strcpy(a[idx].ch, name);
			a[idx].len = strlen(name);
			idx++;
			name = {0}; 
			cnt=0;
			name[cnt] = c[i];
			cnt++;
		}
		else{
			name[cnt] = c[i];
			cnt++;
		}
	}
	
//	qsort(a, idx+1, sizeof(find), comp);
//	int max = -1e9;
//	for (int i=0; i <= idx; i++){
//		max = fmax(max, a[i].len);
//	}
//	int found=-1;
//	for (int i=0; i <= idx; i++){
//		
//	}
	for (int i=0; i <= idx; i++){
		printf("%s %d\n", a[i].ch, a[i].len);
	}
	return 0;
}
