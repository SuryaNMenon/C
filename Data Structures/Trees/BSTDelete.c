#include<stdio.h>
#include<stdlib.h>
struct BstNode{
    int data;
    struct BstNode *left, *right;
};

struct BstNode* FindMax(struct BstNode* root){
    while(root->right != NULL) root = root->right;
    return root;
}

struct BstNode* FindMin(struct BstNode* root){
    while(root->left != NULL) root = root->left;
    return root;
}

struct BstNode* GetNewNode(int data){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct BstNode* Insert(struct BstNode* root, int data){
    if (root==NULL) root = GetNewNode(data);
    else if(data<=root->data) root->left = Insert(root->left,data);
    else root->right = Insert(root->right, data);
    return root;
}

struct BstNode* Delete(struct BstNode* root, int data){
    if(root == NULL) return root;
    else if(data < root->data) root->left = Delete(root->left, data);
    else if(data > root->data) root->right = Delete(root->right,data);
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if(root ->left == NULL){
            struct BstNode* temp = root;
            root=root->right;
            free(temp);
        }
        else if(root->right == NULL){
            struct BstNode* temp = root;
            root= root->left;
            free(temp);
        }
        else {
            struct BstNode* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);        
            }
        return root;
    }
}

void Inorder(struct BstNode* root){
    if(root == NULL) return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}

void main(){
    struct BstNode* root = NULL;
    int choice, elem;
    while(1){
        printf("Enter your choice\n1)Add element to Tree\n2)Delete element in tree\n3)Print elements in order\n6)Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter element: ");
            scanf("%d",&elem);
            root = Insert(root, elem);
            break;
            case 2:
            printf("Enter element: ");
            scanf("%d",&elem);
            root = Delete(root,elem);
            break;
            case 3:
            printf("Elements in order are: ");
            Inorder(root);
            break;
            default: printf("Incorrect choice");
        }
    }
}
