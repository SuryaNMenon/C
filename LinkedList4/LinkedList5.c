/*Program to insert values into a linked list of user defined length
and to perform deletion function in a position defined by the user
and print the linked list at each stage of operation.*/
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* link;
};
struct Node* head;
void Insert(int elem,int pos) {
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp1->data = elem;
	int i;
	if (pos == 1) {
		temp1->link = head;
		head = temp1;
		return;
	}
	struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node));
	temp2 = head;
	for (i = 0; i < pos - 2; i++) {
		temp2 = temp2->link;
	}
	temp1->link = temp2->link;
	temp2->link = temp1;
	return;
}
void Delete(pos) {
	struct Node* temp1 = head;
	int i;
	if (pos == 1) {
		head = temp1->link;
		free(temp1);
		return;
	}
	for (i = 0; i < pos - 2; i++) {
		temp1 = temp1->link;
	}
	struct Node* temp2 = temp1->link;
	temp1->link = temp2->link;
	free(temp2);
	return;
}
void Print() {
	struct Node* temp = head;
	while (temp != NULL) {
		printf(" %d", temp->data);
		temp = temp->link;
	}
	printf("\n");
	return;
}
void Search(int elem) {
	struct Node* temp = head;
	int count = 0,flag = 0;
	while (temp != NULL) {
		count++;
		if (temp->data == elem) {
			flag++;
			printf("Element %d found at position %d\n", elem, count);
		}
		temp = temp->link;
	}
	if (flag == 0){
		printf("Element not found\n");
	}
	return;
}
int main() {
	head = NULL;
	int linkedlistlength = 0, i, elem,pos,choice=0;
	printf("Enter the size of the linkedlist\n"); // Initialization of the Linked List
	scanf("%d", &linkedlistlength);
	for (i = 0; i < linkedlistlength; i++) {
		pos = 1;
		printf("Enter value of an element and a position. Default value of position = 1\n");
		scanf("%d%d", &elem, &pos);
		Insert(elem, pos);
		printf("Current Linked List is:");
		Print();
		printf("\n");
	}
	printf("Final Linked List is:");
	Print();
	while(choice != 5){
		if (choice == 1){
			printf("Enter the element to be inserted and the position.");
			scanf("%d%d", &elem, &pos);
			Insert(elem, pos);
		}
		if (choice == 2) {
			printf("Enter the position where the element is to be deleted");
			scanf("%d", &pos);
			Delete(pos);
		}
		if (choice == 3) {
			printf("Enter the element to be searched");
			scanf("%d", &elem);
			Search(elem);
		}
		if (choice == 4) {
			Print();
		}
		printf("Enter your choice: \n1)Insertion\n2)Deletion\n3)Searching\n4)Display\n5)Quit");
		scanf("%d", &choice);
	}
}

