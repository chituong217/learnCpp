#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node node;


node* makeNode(int n){
	node *newNode = (node *)malloc(sizeof(node));
	newNode->data = n;
	newNode->next = NULL;
	return newNode;
}

int size(node *head){
	int cnt = 0;
	while (head != NULL){
		cnt++;
		head = head->next;
	}
	return cnt;
}

void outputList(node *head){
	if (head == NULL){
		printf("EMPTY\n");
	}
	while (head != NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void push(node **head, int n){
	node *newNode = makeNode(n);
	newNode->next = (*head);
	(*head) = newNode;
}

void pop(node **head){
	if (*head == NULL){
		return;
	} 
	node *tmp = *head;
	*head = tmp->next;
	free(tmp);
}


int main(){
	node *head = NULL;
	int t;
	scanf("%d", &t);
//	getchar();
	while(t--){
		char thaotac[20];
		scanf("%s", &thaotac);
		if (strcmp(thaotac, "pop") == 0){
			pop(&head);
		}
		else if(strcmp(thaotac, "push") == 0){
			int x;
			scanf("%d", &x);
//			getchar();
			push(&head, x);
		}
		else if (strcmp(thaotac, "show") == 0){
			outputList(head);
		}
//		printf("DSLK now: "); outputList(head);
	}
	return 0;
}
