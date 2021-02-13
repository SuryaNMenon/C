#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* link;
};
struct Node* Insert(struct Node* head, int elem) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = elem;
	temp->link = NULL;
	if (head == NULL) {
		head = temp;
	}
	else {
		struct Node* temp1 = head;
		while (temp1->link != NULL) {
			temp1 = temp1->link;
		}
		temp1->link = temp;
	}
	return head;
}
void Print(struct Node* head) {
	struct Node* temp = head;
	while (temp != NULL) {
		printf(" %d", temp->data);
		temp = temp->link;
	}
	printf("\n");
}
void PrintRecursive(struct Node* head) {
	if (head == NULL) {
		printf("\n");
		return;
	}
	printf(" %d", head->data);
	PrintRecursive(head->link);
}
void PrintReverseRecursive(struct Node* head) {
	if (head == NULL) {
		printf("\n");
		return;
	}
	PrintReverseRecursive(head->link);
	printf(" %d", head->data);
}
int main() {
	struct Node* head = NULL;
	head = Insert(head, 3);
	head = Insert(head, 4);
	head = Insert(head, 5);
	head = Insert(head, 6);
	Print(head);
	PrintRecursive(head);
	PrintReverseRecursive(head);
}