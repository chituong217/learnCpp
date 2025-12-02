#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int bac;
	int heso;
	struct node *next;
};

typedef struct node node;

node *makeNode(int heso, int bac){
	node *newNode = (node *)malloc(sizeof(node));
	newNode->bac = bac;
	newNode->heso = heso;
	newNode->next = NULL;
	return newNode;
}

void duyet(node *head){
	while(head != NULL){
		printf("%dx^%d ", head->heso, head->bac);
		if (head->next != NULL){
			printf("+ ");
		}
		head = head->next;
	}
	printf("\n");
}

void update(node **head, int heso, int bac){
	if (*head == NULL){
		node *newNode = makeNode(heso, bac);
		(*head) = newNode;
		return;
	}
	node *tmp = *head;
	node *prev = tmp;
	while (tmp != NULL){
		if (bac == tmp->bac){
			tmp->heso += heso;
			return;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	node *newNode = makeNode(heso, bac);
	prev->next = newNode;
}

void sort(node **head){
	for (node *i = *head; i != NULL; i = i->next){
		node *max = i;
		for (node *j = i->next; j != NULL; j = j->next){
			if (max->bac < j->bac){
				max = j;
			}
		}
		int tmp1 = max->bac;
		int tmp2 = max->heso;
		max->bac = i->bac;
		max->heso = i->heso;
		i->bac = tmp1;
		i->heso = tmp2;
	}
}

int main(){
	node *head = NULL;
	char a[10000], b[10000];
	fgets(a, 10000, stdin);
	a[strlen(a) - 1] = '\0';
	fgets(b, 10000, stdin);
	b[strlen(b) - 1] = '\0';
	int bac, heso;
	
	char *token = strtok(a, " +");
	while (token != NULL){
		heso = 0; bac = 0;
		char *pos_x = strchr(token, 'x');
		char *pos_mu = strchr(token, '^');
		bac = atoi(pos_mu +1);
		char heso_str[100];
		int len = pos_x - token;
		strncpy(heso_str, token, len);
		heso_str[len] = '\0';
		heso = atoi(heso_str);
		update(&head, heso, bac);
		token = strtok(NULL, " +");
	}
	
	token = strtok(b, " +");
		while (token != NULL){
			heso = 0; bac = 0;
			char *pos_x = strchr(token, 'x');
			char *pos_mu = strchr(token, '^');
			bac = atoi(pos_mu +1);
			char heso_str[100];
			int len = pos_x - token;
			strncpy(heso_str, token, len);
			heso_str[len] = '\0';
			heso = atoi(heso_str);
			update(&head, heso, bac);
			token = strtok(NULL, " +");
		}
	
	sort(&head);
	duyet(head);
	return 0;
}
