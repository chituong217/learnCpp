#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

typedef struct node node;

node* makeNode(int x){
	node *newNode = (node *)malloc(sizeof(node));
	newNode->data = x;
	newNode->prev = NULL;
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

void outputNode(node *head){
	while (head != NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void pushBack(node **head, int x){
	node *newNode = makeNode(x);
	node *tmp = *head;
	if (tmp == NULL){
		(*head) = newNode;
		return;
	}
	while (tmp->next != NULL){
		tmp = tmp->next;
	}
	newNode->prev = tmp;
	tmp->next = newNode;
}


void duyetNguoc(node *head){
	if (head == NULL) return;
	while(head->next != NULL){
		head = head->next;
	}
	while(head != NULL){
		printf("%d ", head->data);
		head = head->prev;
	}
}

void sort(node **head){
	for (node *i = *head; i != NULL; i = i->next){
		node *min = i;
		for (node *j = i->next; j != NULL; j = j->next){
			if (j->data < min->data){
				min = j;
			}
		}
		int tmp = min->data;
		min->data = i->data;
		i->data = tmp;
	}
}

int main(){
	node *head = NULL;
	int n;
	scanf("%d", &n);
	while(n--){
		int x;
		scanf("%d", &x);
		pushBack(&head, x);
	}
	sort(&head);
	outputNode(head);
	duyetNguoc(head);
	return 0;
}
