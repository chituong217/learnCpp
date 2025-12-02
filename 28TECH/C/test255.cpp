#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct word word;

struct word{
	char data[100];
	int fre;
};

word a[1005];
int n=0;

int findPos(char x[]){
	for (int i=0; i<n; i++){
		if (strcmp(a[i].data, x) == 0){
			return i;
		}
	}
	return -1;
}

int checkFail(char c[]){
	for (int i=0; i < strlen(c); i++){
		if (c[i] == '/' || c[i] == ':'){
			return 0;
		}
	}
	return 1;
}


int comp(const void *a, const void *b){
	word *x = (word *)a;
	word *y = (word *)b;
	if (x->fre != y->fre){
		return y->fre - x->fre;
	}
	else{
		return strcmp(x->data, y->data);
	}
}


int main(){
	char tmp[100];
	while( scanf("%s", tmp) != -1){
		if (checkFail(tmp) == 1){
			if (findPos(tmp) == -1){
				strcpy(a[n].data, tmp);
				a[n].fre = 1;
				n++;
			}
			else{
				int pos = findPos(tmp);
				a[pos].fre++;
			}
		}
		
	}
	qsort(a, n, sizeof(a[0]), comp);
	for (int i=0; i<n; i++){
		printf("%s %d\n", a[i].data, a[i].fre);
	}
	return 0;
}
