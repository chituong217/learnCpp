#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char c[10001], digit[10001], alpha[10001];
	fgets(c, 10001, stdin);
	int memory[255] = {0};
	for (int i=0; i<strlen(c); i++){
		memory[c[i]]++;
		if (memory[c[i]] >=2){
			printf("%c", c[i]);
			break;
		}
		if (i== strlen(c)-1) printf("NONE");
	}
	return 0;
}
