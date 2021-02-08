#include<stdio.h>
#include<stdlib.h>
struct BstNode{
    int data;
    struct Bstnode *left, *right;
};

struct BstNode* GetNewNode(int data){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right= NULL;
    return newNode;
}

struct BstNode* Insert(struct BstNode* root, int data){
    if(root == NULL){
        root = GetNewNode(data);
    }
    else if (data <= root->data) root->left = Insert(root->left, data);
    else root->right =  Insert(root->right, data);
    return root;
}

int findMinElemRecursive(struct BstNode* root){
    if(root == NULL){
        printf("ERROR ");
        return -1;
    }
    else if(root->left==NULL){
        return root->data;
    }
    return findMaxElemRecursive(root->left);
}

int findMaxElemRecursive(struct BstNode* root){
    if(root == NULL){
        printf("ERROR ");
        return -1;
    }
    else if(root->right == NULL){
        return root->data;
    }
    return findMaxElemRecursive(root->right);
}

int findMinElemIter(struct BstNode* root){
    if(root == NULL){
        printf("ERROR ");
        return -1;
    }
    struct BstNode* current = root;
    while(current->left!=NULL){
        current = current->left;
    }
    return current->data;
}

int findMaxElemIter(struct BstNode* root){
    if(root == NULL){
        printf("ERROR ");
        return -1;
    }
    struct BstNode* current = root;
    while(current->right!=NULL){
        current = current->right;
    }
    return current->data;
}

void main(){
    struct BstNode* root = NULL;
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root, 5);
    root = Insert(root, 2);
    root = Insert(root, 7);
    root = Insert(root, 15);
    root = Insert(root, 25);
    printf("Min element via iteration is: %d\n",findMinElemIter(root));
    printf("Max element via iteration is: %d\n",findMaxElemIter(root));
    printf("Min element via recursion is: %d\n",findMinElemRecursive(root));
    printf("Max element via recursion is: %d\n",findMaxElemRecursive(root));
}