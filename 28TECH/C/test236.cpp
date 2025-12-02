#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


//	Ham viet thuong xau ki tu
void lower(char c[]){
	for (int i=0; i<strlen(c); i++){
		c[i] = tolower(c[i]);
	}
}

int main(){
	char name[3000];
	
//	Nhap vao ten va date
	fgets(name, 3000, stdin);
	name[strlen(name) - 1] = '\0';
//	Tao mang luu ten duoc nhap vao, va bien n de luu chi so
	char memo_name[100][100] = {0};
	int n = 0;
//	Tach cac tu bang strtok va luu vao mang memo_name
	char *word = strtok(name, " ");
	while (word != NULL){
		lower(word);
		word[0] = toupper(word[0]);
		strcpy(memo_name[n++], word);
		word = strtok(NULL, " ");
	}
//	Toupper ten, phan tu cuoi cung cua mang memo_name
	for (int i=0; i<strlen(memo_name[n-1]); i++){
		memo_name[n-1][i] = toupper(memo_name[n-1][i]);
	}
//	In ra theo kieu thu nhat
	for (int i=0; i< n-1; i++){
		
		if (i == n-2){
			printf("%s", memo_name[i]);
		}
		else{
			printf("%s ", memo_name[i]);
		}
	}
	printf(", %s\n", memo_name[n-1]);
//	In ra theo kieu thu hai
	printf("%s, ", memo_name[n-1]);
	for (int i=0; i< n-1; i++){
		printf("%s ", memo_name[i]);
	}
	return 0;
}
