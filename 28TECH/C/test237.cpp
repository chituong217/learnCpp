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
	int n;
	scanf("%d", &n);
	getchar();
	char memo_mail[2000][100] = {0};
	int idx_mail = 0;
	while (n>=0){
		char c[2000];
		fgets(c, 2000, stdin);
		c[strlen(c) - 1] = '\0';
//		Luu cac phan tu vao trong 2 mang word va date
		char memo_name[2000][100] = {0};
		char memo_date[3][100] = {0};
		int idx_name = 0, idx_date = 0;
		char *word = strtok(c, " /");
		while (word != NULL){
			if (isdigit(word[0])){
				strcpy(memo_date[idx_date++], word);
			}
			else if (isalpha(word[0])){
				lower(word);
				strcpy(memo_name[idx_name++], word);
			}
			word = strtok(NULL, " /");
		}
		
//		Bat dau xu li tung mang
//		Kiem tra su xuat hien phia truoc trung ten hay khong

//		for (int i=0; i<idx_name; i++){
//			if (i == idx_name - 1){
//				for (int j=0; j<strlen(memo_name[idx_name-1]); j++){
//					memo_mail[idx_mail][i+j] = memo_name[idx_name-1][j];
//				}
//				printf("%s@xyz.edu.vn\n", memo_mail[idx_mail]);
//				idx_mail++;
//			}
//			else{
//				memo_mail[idx_mail][i] = memo_name[i][0];
//			}
//			
//		}
		
		for (int i=0; i<strlen(memo_name[idx_name])-1; i++){
			memo_mail[idx_mail][i] = memo_name[idx_name][i];
		}
		int tmp = strlen(memo_name[idx_name])-1;
		for (int i=0; i<idx_name -1; i++){
			memo_mail[idx_mail][tmp] = memo_name[i][0];
			if (i == idx_name -2){
				printf("%s@xyz.edu.vn\n", memo_mail[idx_mail]);
				idx_mail++;
			}
		}
		
//		printf("%s", memo_name[idx_name-1]);
//		for (int i=0; i<idx_name -1; i++){
//			printf("%c", memo_name[i][0]);
//			if (i == idx_name -2){
//				printf("@xyz.edu.vn\n");
//			}
//		}
		
		
		
//		Xu li ngay thang nam sinh
		for (int i=0; i < idx_date; i++){
			if (i == idx_date -1){
				printf("%s\n", memo_date[idx_date-1]);
			}
			else if (memo_date[i][0] == 48){
				printf("%c", memo_date[i][1]);
			}
			else{
				printf("%s", memo_date[i]);
			}
		}
		n--;
	}
	return 0;
}
