#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node node;

node* makeNode(int x){
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void pushFront(node **head, int x){
	node *newNode = makeNode(x);
	newNode->next = (*head);
	(*head) = newNode;
}

void pushBack(node **head, int x){
	node *newNode = makeNode(x);
	if (*head == NULL){
		*head = newNode; return;
	}
	node *tmp = *head;
	while ((tmp)->next != NULL){
		(tmp) = (tmp)->next;
	}
	(tmp)->next = newNode;
}

void duyet(node *head){
	while (head != NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int size(node *head){
	int cnt = 0;
	while (head != NULL){
		cnt++;
		head = head->next;
	}
	return cnt;
}

void insert(node **head, int k, int x){
	int n = sizeof(*head);
	if (k < 1 || k > n+1){
		printf("Vi tri chen khong hop le!\n");
	}
	if (k == 1){
		pushFront(head, x);
	}
	else if (k == n+1){
		pushBack(head, x);
	}
	else{
		node *newNode = makeNode(x);
		node *tmp = (*head);
		for (int i=1; i < k-1; i++){
			tmp = tmp->next;
		}
		newNode->next = tmp->next;
		tmp->next = newNode;
	}
	
}

int main(){
	node *head = NULL;
	while(1){
		printf("---------------------------------------------------------------\n");
		printf("1. Them vao cuoi DSLK\n");
		printf("2. Them vao dau DSLK\n");
		printf("3. Chen vao DSLK\n");
		printf("4. Duyet DSLK\n");
		printf("0. Exit\n");
		int lc; scanf("%d", &lc);
		if (lc == 1){
			int x;
			printf("Hay nhap vao x:"); scanf("%d", &x);
			pushBack(&head, x);
		}
		else if (lc == 2){
			int x;
			printf("Hay nhap vao x:"); scanf("%d", &x);
			pushFront(&head, x);
		}
		else if (lc == 3){
			int k, x;
			printf("Hay nhap vao vi tri chen k va x:"); scanf("%d%d", &k, &x);
			insert(&head, k, x);
		}
		else if(lc == 4){
			duyet(head);
		}
		else if (lc == 0){
			break;
		}
	}
	return 0; 
}
