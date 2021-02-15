#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

struct Node* InsertEmpty(struct Node* last, int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    last = temp;
    last->link = last;
    return last;
}

struct Node* InsertEnd(struct Node* last, int data){
    if(last == NULL){
        last = InsertEmpty(last, data);
        return last;
    }
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->link = last->link;
    last->link = temp;
    last = temp;
    return last;
}

struct Node* InsertBeginning(struct Node* last, int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(last == NULL){
        last = InsertEmpty(last, data);
        return last;
    }
    temp->data = data;
    temp->link = last->link;
    last->link = temp;
    return last;
}

struct Node* InsertBetween(struct Node* last, int data, int item){
    struct Node *temp, *p;
    if(last == NULL){
        last = InsertEmpty(last, data);
        return last;
    }
    p=last->link;
    do{
        if(p->data == item){
            temp = (struct Node*)malloc(sizeof(struct Node));
            temp->data=data;
            temp->link = p->link;
            p->link = temp;
        //     if(last == NULL){
        //         last = temp;
        //         return last
        //     }
        //Add these lines if lines 42-47 were not present
            return last;
        }
        p=p->link;
    }while(p!=last->link);
    printf("%d not present in the Linked List.\n",item);
    return last;
}

struct Node* Delete(struct Node* last, int data){
    if(last == NULL){
        printf("Empty Linked List\n");
        return last;
    }
    struct Node *temp, *p;
    if(last->link == last && last->data == data){
        p = last;
        last = NULL;
        free(p);
        return last;
    }
    if(last->link->data == data){
        p=last->link;
        last->link = p->link;
        free(p);
        return last;
    }
    p=last->link;
    while(p->link != last){
        if(p->link->data == data){
            struct Node* temp = p->link;
            p->link = temp->link;
            free(temp);
            return last;
        }
        p=p->link;
    }
    if(last->data == data){
        struct Node* temp = last;
        p->link = temp->link;
        last = p;
        free(temp);
        return last;
    }
    printf("Element not present in Linked List");
    return last;
}

struct Node* CreateList(struct Node* last){
    int i,n,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    last = NULL;
    if(n==0) return last;
    printf("Enter element to be inserted: ");
    scanf("%d",&data);
    last = InsertEmpty(last, data);
    for(i=2;i<=n;i++){
        printf("Enter the element to be inserted: ");
        scanf("%d",&data);
        last = InsertEnd(last, data);
    }
    return last;
}

void DisplayList(struct Node* last){
    if(last == NULL){
        printf("Linked List is empty");
        return;
    }
    int i;
    struct Node* temp = last->link;
    printf("Linked list is: ");
    do{
        printf("%d ",temp->data);
        temp=temp->link;
    }while(temp!=last->link);
    printf("\n");
}

void main(){
    int choice, data, item;
    struct Node* last = NULL;
    while(1){
        printf("Enter your choice:\n1)Create List\n2)Insert element in the beginning\n3)Insert element in the end\n4)Insert element after particular element\n5)Delete element\n6)Display\n7)Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            last = CreateList(last);
            DisplayList(last);
            break;
            case 2:
            printf("Enter the element to be inserted: ");
            scanf("%d",&data);
            last = InsertBeginning(last, data);
            DisplayList(last);
            break;
            case 3:
            printf("Enter the element to be inserted: ");
            scanf("%d",&data);
            last = InsertEnd(last, data);
            DisplayList(last);
            break;
            case 4:
            printf("Enter element to be inserted and the element after which it is to be inserted: ");
            scanf("%d %d",&data,&item);
            last = InsertBetween(last, data, item);
            DisplayList(last);
            break;
            case 5:
            printf("Enter the element to be deleted: ");
            scanf("%d",&data);
            last = Delete(last, data);
            DisplayList(last);
            break;
            case 6:
            DisplayList(last);
            break;
            case 7:
            exit(1);
            break;
            default: printf("Wrong Choice");
        }
    }    
}
