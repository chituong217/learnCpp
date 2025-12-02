#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    char id[100];
    char name[100];
    double gpa;
    struct node *next;
};

typedef struct node node;

node *makeNode(char id[], char name[], double gpa){
	node *newNode = (node *)malloc(sizeof(node));
	strcpy(newNode->id, id);
	strcpy(newNode->name, name);
	newNode->gpa = gpa;
	newNode->next = NULL;
	return newNode;
}

void pushBack(node **head, char id[], char name[], double gpa){
	if ((*head) == NULL){
		node *newNode = makeNode(id, name, gpa);
		(*head) = newNode;
	}
	else{
		node *tmp = (*head);
		while (tmp->next != NULL){
			tmp = tmp->next;
		}
		node *newNode = makeNode(id, name, gpa);
		tmp->next = newNode;
	}
}

void max(node *head){
	double max = 0;
	node *tmp = head;
	while (tmp != NULL){
		if (tmp->gpa > max){
			max = tmp->gpa;
		}
		tmp = tmp->next;
	}
	while (head != NULL){
		if (head->gpa == max){
			printf("%s %s %.2lf\n", head->id, head->name, head->gpa);
		}
		head = head->next;
	}
}

int main(){
	node *head = NULL;
	int t;
	scanf("%d", &t);
	getchar();
	while(t--){
		char id[100];
    	char name[100];
    	double gpa;
    	fgets(id, 100, stdin);
    	id[strlen(id) - 1] = '\0';
    	fgets(name, 100, stdin);
    	name[strlen(name) - 1] = '\0';
    	scanf("%lf", &gpa);
    	getchar();
    	pushBack(&head, id, name, gpa);
	}
	max(head);
	return 0;
}
