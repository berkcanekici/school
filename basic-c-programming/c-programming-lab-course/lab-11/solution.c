/*
    CSE 108 - 11
    Name: Berkcan EKICI
    Id: 171044015
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*
    Struct declaration
*/
struct node
{
    int data;
    float number;
    char *name;
    struct node *next;
};

// Insert function
void insert_end(struct node **head, int val, float num, char *name_)
{
    //create a new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->number = num;
    newNode->name = name_;
    newNode->next = NULL;

    //if head is NULL, it is an empty list
    if (*head == NULL)
        *head = newNode;
    //Otherwise, find the last node and add the newNode
    else {
        struct node *lastNode = *head;

        //last node's next address will be NULL.
        while (lastNode->next != NULL)
            lastNode = lastNode->next;

        //add the newNode at the end of the linked list
        lastNode->next = newNode;
    }
}

// Prints the list on the consol with the help of a loop.
void printList_withLoop(struct node *head)
{
    //iterate the entire linked list and print the data with loop
    for (struct node *ptr = head; head != NULL; head = head->next)
        printf("%d->%f->%s,\n", head->data, head->number, head->name);

    printf("NULL\n");
}

// Prints the list on the consol with the help of recursive.
void printList_withRecursiveHelper(struct node *list)
{
    //iterate the entire linked list and print the data with recursive
    if (list == NULL)
        return;

    if (list->next != NULL)
        printf("%d->%f->%s, ", list->data, list->number, list->name);
    else
        printf("%d->%f->%s", list->data, list->number, list->name);

    printList_withRecursiveHelper(list->next);
}
// Wrapper function.
void printList_withRecursive(struct node *list)
{
    putchar('[');
    printList_withRecursiveHelper(list);
    putchar(']');
}

// Sorted insert function.
void sortedInsert(struct node **head_ref, struct node *new_node)
{
    // Sort according to string into the node struct.
    // It's name is "name".
    // You will sort ascending order.

    struct node *current = NULL;

    // If the list is empty or the name of the first node is bigger
    if (*head_ref == NULL || strcmp((*head_ref)->name, new_node->name) >= 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else {
        current = *head_ref;
        while (current->next != NULL && strcmp(current->next->name, new_node->name) < 0)
            current = current->next;
        new_node->next = current->next;
        current->next = new_node;
    }
}

/* A utility function to create a new node */
struct node *newNode(int new_data, float num, char *name_)
{
    /* allocate node */
    struct node *p = (struct node *)malloc(sizeof(struct node));

    /* put in the data  */
    p->data = new_data;
    p->number = num;
    p->name =  name_;
    p->next = NULL;

    return p;
}

// Search according to "data" which defined in node struct.
bool search(struct node *head, int x)
{
    // NULL pointer control.
    if (head == NULL)
        return 0;
    
    // You will control x number comparision with "data" which struct element.
    while (head) {
        if (head->data == x)
            return 1;
        head = head->next;
    }
    
    return 0; 
}

int main()
{
    struct node *head = NULL;

    insert_end(&head, 10, 5.5, "hello1");
    insert_end(&head, 20, 5.5, "hello2");
    insert_end(&head, 30, 5.5, "hello3");

    printf("Print List with Loop: \n");
    printList_withLoop(head);

    struct node *new_node = newNode(1, 5.5, "a");
    sortedInsert(&head, new_node);

    new_node = newNode(3, 5.5, "c");
    sortedInsert(&head, new_node);

    new_node = newNode(2, 5.5, "d");
    sortedInsert(&head, new_node);

    new_node = newNode(2, 5.5, "b");
    sortedInsert(&head, new_node);

    printf("Print List with Recursive: \n");
    printList_withRecursive(head);

    printf("\nIs 20 belong this linked list?: ");
    printf(search(head, 20) ? "YES \n" : "NO \n");

    printf("\nIs 18 belong this linked list?: ");
    printf(search(head, 18) ? "YES \n" : "NO \n");

    return 0;
}