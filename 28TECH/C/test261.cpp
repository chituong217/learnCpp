#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
	char id[20];
	char name[50];
	double gpa;
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
	while(head != NULL){
		printf("%s %s %.2lf\n", head->id, head->name, head->gpa);
		head = head->next;
	}
	printf("\n");
}

node* makeNode(char id[], char name[], double gpa){
	node *newNode = (node *)malloc(sizeof(node));
	strcpy(newNode->id, id);
	strcpy(newNode->name, name);
	newNode->gpa = gpa;
	newNode->next = NULL;
	return newNode;
}

void pushFront(node **head, char id[], char name[], double gpa){
	node *newNode = makeNode(id, name, gpa);
	newNode->next = (*head);
	(*head) = newNode;
}

void pushBack(node **head, char id[], char name[], double gpa){
	node *newNode = makeNode(id, name, gpa);
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

void insert(node **head, char id[], char name[], double gpa, int k){
	node *newNode = makeNode(id, name, gpa);
	int n = size(*head);
	if (k == 1){
		pushFront(head, id, name, gpa);
		return;
	}
	else if (k == n+1){
		pushBack(head, id, name, gpa);
		return;
	}
	node *tmp = (*head);
	for (int i=1; i<k-1; i++){
		tmp = tmp->next;
	}
	newNode->next = tmp->next;
	tmp->next = newNode;
}

int main(){
	node *head = NULL;
	int dem;
	scanf("%d", &dem);
	while(dem){
		int lc; scanf("%d", &lc);
		getchar();
		if (lc == 2){
			char id[20]; char name[50]; double gpa;
			fgets(id, 20, stdin);
			id[strlen(id) - 1] = '\0';
			fgets(name, 50, stdin);
			name[strlen(name) - 1] = '\0';
			scanf("%lf", &gpa);
			getchar();
			pushBack(&head, id, name, gpa);
		}
		else if (lc == 1){
			char id[20]; char name[50]; double gpa;
			fgets(id, 20, stdin);
			id[strlen(id) - 1] = '\0';
			fgets(name, 50, stdin);
			name[strlen(name) - 1] = '\0';
			scanf("%lf", &gpa);
			getchar();
			pushFront(&head, id, name, gpa);
		}
		else if (lc == 3){
			int k;
			scanf("%d", &k);
			getchar();
			char id[20]; char name[50]; double gpa;
			fgets(id, 20, stdin);
			id[strlen(id) - 1] = '\0';
			fgets(name, 50, stdin);
			name[strlen(name) - 1] = '\0';
			scanf("%lf", &gpa);
			getchar();
			insert(&head, id, name, gpa, k);
		}
		dem--;
	}
	outputList(head);
	return 0;
}
