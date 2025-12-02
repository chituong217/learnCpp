#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct word word;

struct word{
	char data[1000];
	int fre;
};

word x[10000];
int sl =0;

int findPos(char c[]){
	for (int i=0; i<sl; i++){
		if (strcmp(c, x[i].data) ==0){
			return i;
		}
	}
	return -1;
}


int main(){
	int t; scanf("%d", &t);
	getchar();
	while (t--){
		char c[1000];
		char a[1000][100] = {0};
		int n = 0;
		fgets(c, 1000, stdin);
		c[strlen(c) -1] = '\0';
		char *token = strtok(c, " ");
		while (token != NULL){
			for (int i=0; i<strlen(token); i++){
				token[i] = tolower(token[i]);
			}
			strcpy(a[n], token);
			n++;
			token = strtok(NULL, " ");
		}
		char name[1000];
		for (int i=0; i<strlen(a[n-2]); i++){
			name[i] = a[n-2][i];
		}
		int idx = strlen(a[n-2]);
		for (int i=0; i< n-2; i++){
			name[idx] = a[i][0];
			idx++;
		}
		name[idx] = '\0';
		int pos = findPos(name);
		if (pos == -1){
			strcpy(x[sl].data, name);
			x[sl].fre = 1;
			sl++;	
			printf("%s@xyz.edu.vn\n", name);
		
		}
		else{
			x[pos].fre++;
			printf("%s%d@xyz.edu.vn\n", name, x[pos].fre);
		}
	
		
		
		token = strtok(a[n-1], "/");
		while (token != NULL){
			int so = atoi(token);
			printf("%d", so);
			token = strtok(NULL, "/");
		}
		printf("\n");
	}
	return 0;
}
