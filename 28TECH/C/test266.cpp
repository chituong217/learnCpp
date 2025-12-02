#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	char data[100];
	int fre;
	struct node *next;
};

typedef struct node node;

node *makeNode(char c[]){
	node *newNode = (node*)malloc(sizeof(node));
	strcpy(newNode->data, c);
	newNode->fre = 1;
	newNode->next = NULL;
	return newNode;
}

void update(node **head, char c[]){
	node *newNode = makeNode(c);
	if ((*head) == NULL){
		(*head) = newNode; return;
	}
	node *tmp = (*head);
	node *prev = tmp;
	while (tmp != NULL){
		if (strcmp(tmp->data, c) == 0){
			tmp->fre +=1;
			return;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = newNode;
}

void outputNode(node *head){
	if (head == NULL) return;
	while (head != NULL){
		printf("%s %d\n", head->data, head->fre);
		head = head->next;
	}
}

int main(){
	node *head = NULL;
	char c[100];
	while(scanf("%s", c) != -1){
		update(&head, c);
	}
	outputNode(head);
	return 0;
}


