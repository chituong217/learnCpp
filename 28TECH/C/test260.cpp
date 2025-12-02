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

void pushFront(node **head, int x){
	node *newNode = makeNode(x);
	if (*head != NULL){
		(*head)->prev = newNode;
	}
	newNode->next = (*head);
	(*head) = newNode;
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

void insert(node **head, int k, int x){
	node *newNode = makeNode(x);
	int n = size(*head);
	if (k < 1 || k > n + 1){
		printf("Vi tri chen khong hop le\n");
		return;
	}
	else if (k == 1){
		pushFront(head, x);
	}
	else if (k == n+1){
		pushBack(head, x);
	}
	else{
		node *tmp = (*head);
		for (int i = 1; i < k - 1; i++){
			tmp = tmp->next;
		}
		newNode->next = tmp->next;
		(tmp->next)->prev = newNode;
		newNode->prev = tmp;
		tmp->next = newNode;
	}
}

void popFront(node **head){
	if (*head == NULL) return;
	node *tmp = *head;
	(*head) = tmp->next;
	if (*head != NULL){
		(*head)->prev = NULL;
	}
	free(tmp);
}

void popBack(node **head){
	if (*head == NULL) return;
	node *tmp = *head;
	if (tmp->next == NULL){
		(*head) = NULL;
		free(tmp);
		return;
	}
	while (tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->prev->next = NULL;
	free(tmp);
}

void erase(node **head, int k){
	int n = size(*head);
	if (k < 1 || k > n){
		printf("Vi tri xoa khong hop le\n");
		return;
	}
	else if (k == 1){
		popFront(head);
	}
	else if (k == n){
		popBack(head);
	}
	else{
		node *tmp = *head;
		for (int i=1; i<k; i++){
			tmp = tmp->next;
		}
		tmp->prev->next = tmp->next;
		if (tmp->next != NULL){
			tmp->next->prev = tmp->prev;
		}
		free(tmp);
	}
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
	while(1){
		printf("---------------------------------------------------------------\n");
		printf("1. Them vao cuoi DSLK\n");
		printf("2. Them vao dau DSLK\n");
		printf("3. Chen vao DSLK\n");
		printf("4. Xoa dau DSLK\n");
		printf("5. Xoa giua DSLK\n");
		printf("6. Xoa cuoi DSLK\n");
		printf("7. Sap xep DSLK\n");
		printf("8. Duyet DSLK\n");
		printf("9. Duyet nguoc DSLK\n");
		printf("0. Exit\n");
		printf("---------------------------------------------------------------\n");
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
			popFront(&head);
		}
		else if(lc == 5){
			int k;
			printf("Hay nhap vao vi tri xoa: ");
			scanf("%d", &k);
			erase(&head, k);
		}
		else if(lc == 6){
			popBack(&head);
		}
		else if (lc == 7){
			sort(&head);
		}
		else if(lc == 8){
			outputNode(head);
		}
		else if (lc == 9){
			duyetNguoc(head);
		}
		else if (lc == 0){
			break;
		}
	}
	return 0;
}
