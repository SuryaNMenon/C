#include<stdio.h>
#include<stdlib.h>
struct BstNode{
    int data;
    struct BstNode *left, *right;
};

struct BstNode* GetNewNode(int data){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data=data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct BstNode* Insert(struct BstNode* root, int data){
    if(root == NULL) root = GetNewNode(data);
    else if (data <= root->data) root->left = Insert(root->left,data);
    else root->right = Insert(root->right,data);
    return root;
}

int Search(struct BstNode* root, int elem){
    if(root == NULL){
        printf("Not found");
        exit(1);
    }
    if(elem == root->data){
        printf("Element found");
        exit(1);
    }
    else if(elem <=root->data) Search(root->left, elem);
    else Search(root->right,elem);
}
void main(){
    struct BstNode* root = NULL;
    root = Insert(root,5);
    root = Insert(root,6);
    root = Insert(root,7);
    root = Insert(root,8);
    printf("Enter element");
    int elem;
    scanf("%d",&elem);
    Search(root, elem);
}
