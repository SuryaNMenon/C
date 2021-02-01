#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* link;
};
struct Node* head;
void Insert(int elem) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = elem;
	temp->link = head;
	head = temp;
}
void Reverse() {
	struct Node *prev, *current, *next;
	current = head;
	while (current != NULL) {
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	head = prev;
}
void Print() {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	while (temp != NULL) {
		printf(" %d", temp->data);
		temp = temp->link;
	}
	printf("\n");
}
int main(){
	head = NULL;
	Insert(3);
	Insert(5);
	Insert(7);
	Insert(9); // 9 7 5 3
	printf("Current linkedlist is:");
	Print();
	Reverse();
	printf("Linkedlist after reversal is:");
	Print();
}