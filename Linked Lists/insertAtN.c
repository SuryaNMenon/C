//C Program to insert elements at nth position in a Linked List
#define _CRT_SECURE_NO_DEPRECATE 1
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* link;
};
struct Node* head;
void Insert(int elem, int pos) {
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp1->data = elem;
	temp1->link = NULL;
	if (pos == 1) {
		temp1->link = head;
		head = temp1;
		return;
	}
	struct Node* temp2 = head;
	int i;
	for (i = 0; i < pos-2; i++) {
		temp2 = temp2->link;
	}
	temp1->link = temp2->link;
	temp2->link = temp1;
}
void Print() {
	struct Node* temp = head;
	while (temp != NULL) {
		printf(" %d", temp->data);
		temp = temp->link;
	}
}
int main() {
	head = NULL; // list = empty
	Insert(3, 1); // list = 3
	Insert(2, 2); // list = 3 2
	Insert(5, 1); // list = 5 3 2
	Insert(6, 4); // list = 5 3 6 2
	Print();
}