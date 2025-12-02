#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

typedef struct node node;

node* makeNode(int n){
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = n;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void pushBack(node** head, int x){
	node *newNode = makeNode(x);
	if ((*head) == NULL){
		(*head) = newNode;
		return;
	}
	node *tmp = (*head);
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = newNode;
	newNode->prev = tmp;
}

void duyetNguoc(node *head){
	if (head == NULL) return;
	while (head->next != NULL){
		head = head->next;
	}
	while (head != NULL){
		printf("%d ", head->data);
		head = head->prev;
	}
}

int main(){
	node *head = NULL;
	int t;
	scanf("%d", &t);
	while (t--){
		int x; scanf("%d", &x);
		pushBack(&head, x);
	}
	duyetNguoc(head);
	return 0;
}
