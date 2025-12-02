#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

typedef struct node node;

node *makeNode(int n){
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = n;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void update(node **head, int n){
	if (*head == NULL){
		node *newNode = makeNode(n);
		(*head) = newNode;
	}
	else{
		node *tmp = (*head);
		node *prev = tmp;
		while (tmp != NULL){
			if (tmp->data == n){
				return;
			}
			prev = tmp;
			tmp = tmp->next;
		}
		node *newNode = makeNode(n);
		prev->next = newNode;
		newNode->prev = prev;
	}
}

void duyet(node *head){
	while (head != NULL){
		printf("%d ", head->data);
		head = head->next;
	}
}

int main(){
	node *head = NULL;
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		update(&head, n);
	}
	duyet(head);
	return 0;
}
