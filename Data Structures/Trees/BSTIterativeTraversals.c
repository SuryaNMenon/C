#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};
#define MAX 100
struct Node* stack[MAX]; // Implicit stack - here it is an array of pointers of struct Node* datatype.
int top = -1;

int isEmpty(){
    if(top == -1) return 1;
    else return 0;
}

void Push(struct Node* item){
    if(top == MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

struct Node* Pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return;
    }
    return stack[top--];
}

struct Node* GetNewNode(struct Node* root, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* Insert(struct Node* root, int data){
    if(root == NULL) root = GetNewNode(root, data);
    else if(data <= root->data) root = Insert(root->left, data);
    else root = Insert(root->right, data);
    return root;
}

void Preorder(struct Node* root){
    struct Node* ptr = root;
    if(root == NULL){
        printf("Empty Tree\n");
        return;
    }
    Push(ptr);
    while(!isEmpty()){
        ptr = Pop();
        printf("%d ", ptr->data);
        if(ptr->right != NULL) Push(ptr->right);
        if(ptr->left != NULL) Push(ptr->left);
    }
    printf("\n");
}

void Inorder(struct Node* root){
    struct Node* ptr = root;
    if(ptr == NULL){
        printf("Empty Tree\n");
        return;
    }
    while(1){
        while(ptr->left != NULL){
            Push(ptr->left);
            ptr = ptr->left;
        }
        while(ptr->right == NULL){
            printf("%d ", ptr->data);
            if(isEmpty) return;
            ptr = Pop();
        }
        printf("%d ", ptr->data);
        ptr = ptr->right;
    }
}

void Postorder(struct Node* root){
    struct Node* ptr = root;
    if(ptr == NULL){
        printf("Empty Tree\n");
        return;
    }
    struct Node* q = ptr;
    while(ptr->left != NULL){
        Push(ptr);
        ptr = ptr->left;
    }
    while(ptr->right == NULL || ptr->right == q){
        printf("%d ", ptr->data);
        q = ptr;
        if(isEmpty()) return;
        ptr = Pop();
    }
    Push(ptr);
    ptr = ptr->right;
}

void main(){
    struct Node* root = NULL;
    int choice, data;
    while(1){
        printf("\tMenu\n");
        printf("1. Insert Element\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = Insert(root, data);
                break;
            case 2:
                printf("Preorder traversal is: ");
                Preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder traversal is: ");
                Inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal is: ");
                Postorder(root);
                printf("\n");
                break;
            case 5:
                exit(1);
                break;
            default: printf("Invalid choice\n");
        }
    }
}