#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
	char c[1000];
	fgets(c, 1000, stdin);
	c[strlen(c) - 1] = '\0';
	char memo_word[100][100] = {0};
	char memo_date[100][100] = {0};
	int idx_word = 0, idx_date = 0;
	char *word = strtok(c, " /");
	while (word != NULL){
		if (isdigit(word[0])){
			strcpy(memo_date[idx_date++], word);
		}
		else if (isalpha(word[0])){
			strcpy(memo_word[idx_word++], word);
		}
		word = strtok(NULL, " /");
	}
	
	printf("Day la nhung phan tu trong mang memo_word :\n");
	for (int i=0; i<idx_word; i++){
		printf("%s\n", memo_word[i]);
	}
	printf("Day la nhung phan tu trong mang memo_date :\n");
	for (int i=0; i<idx_date; i++){
		printf("%s\n", memo_date[i]);
	}
	return 0;
}
