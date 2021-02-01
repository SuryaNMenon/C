#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* link;
};
struct Node* head=NULL;
void Insert(int elem) {
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp1->data = elem;
	temp1->link = NULL;
	if (head == NULL) {
		head = temp1;
		return;
	}
	struct Node* temp2 = head;
	while (temp2->link != NULL) {
		temp2 = temp2->link;
	}
	temp2->link = temp1;
}
void Print() {
	struct Node* temp = head;
	if (temp != NULL) {
		printf(" %d", temp->data);
		temp = temp->link;
	}
}
void Delete(int delpos) {
	struct Node* temp1= head;
	if (delpos == 1) {
		head = temp1->link;
		free(temp1);
		return;
	}
	int i;
	for (i = 0; i < delpos - 2; i++) {
		temp1 = temp1->link;
	}
	struct Node* temp2 = temp1->link;
	temp1->link = temp2->link;
	free(temp2);
	}

int main() {
	Insert(3);
	Insert(6);
	Insert(7);
	Insert(1);
	Insert(12);
	Print();
	int delpos;
	printf("Enter the position where an element is to be deleted");
	scanf("%d", &delpos);
	Delete(delpos);
	Print();
}