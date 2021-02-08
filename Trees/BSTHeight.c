#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct BstNode{
    int data;
    struct BstNode *left, *right;
};

struct BstNode* GetNewNode(int data){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data= data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct BstNode* Insert(struct BstNode* root,int data){
    if(root==NULL) root = GetNewNode(data);
    else if(data<=root->data) root->left = Insert(root->left,data);
    else root->right = Insert(root->right,data);
    return root;
}

int Height(struct BstNode* root){
    if(root == NULL) return -1;
     else {
        int left = Height(root->left);
        int right = Height(root->right);

        int height = (left < right) ? right+1 : left+1;
        return height;
            }        
}   
void main(){
    struct BstNode* root = NULL;
    int choice, elem;
    while(1){
        printf("Enter your choice\n1)Add element to Tree\n2)Height of Tree\n3)Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter element\n");
                scanf("%d",&elem);
                Insert(root, elem);
                break;
            case 2:
                printf("Height of Tree is %d\n",Height(root));
                break;
            default: printf("Incorrect Choice\n");
        }
    }
}