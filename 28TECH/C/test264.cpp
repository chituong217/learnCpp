#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
	int data;
	struct node *next;
};

node *makeNode(int n){
	node *newNode = (node *)malloc(sizeof(node));
	newNode->data = n;
	newNode->next = NULL;
	return newNode;
}

void outputFront(node *head){
	if (head == NULL){
		printf("EMPTY\n");
		return;
	}
	else{
		printf("%d\n", head->data);
	}
}

void pushBack(node **head, int x){
	node *newNode = makeNode(x);
	if (*head == NULL){
		(*head) = newNode;
		return;
	}
	node *tmp = (*head);
	while (tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = newNode;
}

void popFront(node **head){
	if (*head == NULL){
		return;
	}
	node *tmp = *head;
	(*head) = (*head)->next;
	free(tmp);
}

int main(){
	node *head = NULL;
	int t;
	scanf("%d", &t);
	while(t--){
		char cmd[10];
		scanf("%s", cmd);
		if (strcmp(cmd, "push") == 0){
			int x;
			scanf("%d", &x);
			pushBack(&head, x);
		}
		else if(strcmp(cmd, "pop")==0){
			popFront(&head);
		}
		else if(strcmp(cmd, "front")==0){
			outputFront(head);
		}
	}
	return 0;
}
