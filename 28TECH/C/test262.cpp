#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node node;

int size(node *head){
	int cnt = 0;
	while(head != NULL){
		cnt++;
		head = head->next;
	}
	return cnt;
}

void outputList(node *head){
	if (head == NULL){
		printf("EMPTY");
		return;
	}
	while(head != NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

node* makeNode(int x){
	node *newNode = (node *)malloc(sizeof(node));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
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

//
//void popFront(node **head){
//	if (*head == NULL){
//		return;
//	} 
//	node *tmp = *head;
//	*head = tmp->next;
//	free(tmp);
//}
//
//void popBack(node **head){
//	if (*head == NULL){
//		return;
//	}
//	node *tmp = *head;
//	if (tmp->next == NULL){
//		*head = NULL;
//		free(tmp);
//		return;
//	}
//	while ((tmp->next)->next != NULL){
//		tmp = tmp->next;
//	}
//	node *last = tmp->next;
//	tmp->next = NULL;
//	free(last);
//}
//
//void erase(node **head, int k){
//	if (k == 1){
//		popFront(head);
//	}
//	else{
//		if (*head == NULL){
//			return;
//		}
//		node *tmp = *head;
//		if (tmp->next == NULL){
//			*head = NULL;
//			free(tmp);
//			return;
//		}
//		for (int i=1; i<k-1; i++){
//			tmp = tmp->next;
//		}
//		node *del = tmp->next;
//		tmp->next = del->next;
//		free(del);
//	}
//}

void deleteAll(node **head, int x){
	while ((*head)!=NULL && (*head)->data == x){
		node *tmp = (*head);
		(*head) = (*head)->next;
		free(tmp);
	}
	node *tmp = (*head);
	node *prev = tmp;
	while (tmp != NULL){
		if (tmp->data == x){
			prev->next = tmp->next;
			free(tmp);
			tmp = prev;
		}
		else{
			prev = tmp;
			tmp = tmp->next;
		}
		
	}
}

int main(){
	node *head = NULL;
	int n, x;
	scanf("%d %d", &n, &x);
	for (int i=1; i<=n; i++){
		int nhap;
		scanf("%d", &nhap);
		pushBack(&head, nhap);
	}
	deleteAll(&head, x);
	outputList(head);
	return 0;
}

