#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *link;
};
struct Node *head = NULL;
int linkedListLength = 0;
void insertNode()
{
    int value = 0;
    printf("Enter the value to be inserted : ");
    scanf("%d", &value);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
    printf("Linked List Length = %d.\n\nEnter postion = 1 to insert at the begining.\n\nEnter the postion to insert the element : ", linkedListLength);
    int postion = 0;
    scanf("%d", &postion);
    if (postion > linkedListLength + 1)
    {
        printf("Invalid position");
        return;
    }
    temp->data = value;
    if (head == NULL || postion == 1)
    {
        temp->link = head;
        head = temp;
        linkedListLength++;
        return;
    }
    struct Node *temp2 = head;
    for (int i = 0; i < postion - 2; i++)
        temp2 = temp2->link;
    temp->link = temp2->link;
    temp2->link = temp;
    linkedListLength++;
    return;
}
void delete ()
{
    printf("Linked List Length = %d.\n\nEnter postion = 1 to delete from the begining.\n\nEnter the postion of the element to be deleted : ", linkedListLength);
    int postion = 0;
    scanf("%d", &postion);
    if (postion > linkedListLength)
    {
        printf("Invalid position");
        return;
    }
    struct Node *temp = head;
    if (postion == 1)
    {
        head = temp->link;
        free(temp);
        linkedListLength--;
        return;
    }
    for (int i = 0; i < postion - 2; i++)
        temp = temp->link;
    struct Node *temp2 = temp->link;
    temp->link = temp2->link;
    linkedListLength--;
    free(temp2);
    return;
}
void display()
{
    if (head == NULL)
    {
        printf("The linked list is empty");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    return;
}
void search()
{
    printf("Enter the element to be searched for : ");
    int elt = 0, count = 0;
    scanf("%d", &elt);
    struct Node *temp = head;
    while (temp != NULL)
    {
        count++;
        if (temp->data == elt)
        {
            printf("Element found at postion : %d\n", count);
            return;
        }
        temp = temp->link;
    }
    printf("Element not found\n");
}
int main()
{
    int choice = 0;
    printf("Enter your choice : \n");
    printf("1.Insert\n2.Display\n3.Delete\n4.Search\n5.Exit\n");
    scanf("%d", &choice);
    while (choice != 5)
    {
        if (choice == 1)
            insertNode();
        if (choice == 2)
            display();
        if (choice == 3)
            delete ();
        if (choice == 4)
            search();
        printf("\nEnter your choice : \n");
        printf("1.Insert\n2.Display\n3.Delete\n4.Search\n5.Exit\n");
        scanf("%d", &choice);
    }
    return 0;
}
