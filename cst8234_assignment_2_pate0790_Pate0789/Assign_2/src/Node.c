#include <stdio.h>
#include <stdlib.h>
#include "Node.h"


void removeFromStart(node_t **head) {
	if (head == NULL)
		return;
	node_t *charecter = *head;
	*head = (node_t*) charecter->new;
	free(charecter);
}

void addToStart(node_t **head, student_t *student) {
	node_t *iHead = (node_t*) malloc(sizeof(node_t));
	iHead->info = student;
	iHead->new = *head;
	*head = iHead;

}
void removeLast(node_t **head) {
	if (head == NULL)
		return;
	node_t *remove = *head;
	node_t *last = *head;
	while (remove->new != NULL) {
		last = remove;
		remove = (node_t*) remove->new;

	}
	if (remove == *head) {
		*head = NULL;

	} else {
		last->new = NULL;
	}
	free(remove);
}

void addToEnd(node_t **head, student_t *student) {
	node_t *node = (node_t*) malloc(sizeof(node_t));
	node_t *last = *head;
	node->info = student;
	//so make next NULL
	node->new = NULL;
	//if linklist is empty. then make new node as head
	if (*head == NULL) {
		*head = node;
		return;
	}
	while (last->new != NULL) {
		last = (node_t*) last->new;
	}
	last->new = node;
	return;
}
void removeByIndex(node_t **head, int n) {
	node_t *charecter = *head;
	node_t *prev;
	if (charecter == NULL) {
		return;
	}
	if (n == 1) {
		*head = (node_t*) charecter->new;
		free(charecter);
		return;
	}
	for (int i = 1; i != n; i++) {
		prev = charecter;
		charecter = (node_t*) charecter->new;

	}
	if (charecter == NULL) {
		printf("\nData not present!\n");
		return;
	} else {
		prev->new = charecter->new;
		free(charecter);
	}

}

void printList(node_t *head) {
	node_t *head_O = head;
	while (head_O != NULL) {
		printf("%s,%s\n", head_O->info->last_N, head_O->info->first_N);
		head_O= (node_t*) head_O->new;
	}
}
