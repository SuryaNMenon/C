#include <stdio.h>
#include<stdlib.h>
struct BstNode{
    int data;
    struct BstNode *left, *right;
};
struct BstNode* GetNewNode(int data){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}
struct BstNode* Insert(struct BstNode* root, int data){
    if(root == NULL) root = GetNewNode(data);
    else if (data <= root->data) root->left = Insert(root->left,data);
    else root->right = Insert(root->right,data);
    return root;
}

void Preorder(struct BstNode* root){
    if(root == NULL) return;
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(struct BstNode* root){
    if(root == NULL) return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}

void Postorder(struct BstNode* root){
    if(root == NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);
}

void main(){
    struct BstNode* root = NULL;
    int choice,data;
    while(1){
        printf("Enter your choice\n1)Add element to Tree\n2)Preorder traversal\n3)Inorder traversal\n4)Postorder traversal\n5)Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter element");
            scanf("%d",&data);
            root = Insert(root,data);
            break;
            case 2:
            printf("Elements are: ");
            Preorder(root);
            break;
            case 3:
            printf("Elements are: ");
            Inorder(root);
            break;
            case 4:
            printf("Elements are: ");
            Postorder(root);
            break;
            case 5:
            exit(1);
            default: printf("Wrong choice");
        }
    }
}