/*
    CSE 108 - 12
    Name: Berkcan EKICI
    Id: 171044015
*/
// sondaki cikti hatali

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define    SIZE    3

struct node_list {
    int data;
    float number;
    char *name;
    struct node_list *next;
};

/*Do not modify the following function.*/

void insert_end(struct node_list **head, int val, float num, char *name_)
{
    struct node_list *newnode = malloc(sizeof(struct node_list));
    newnode->data = val;
    newnode->number = num;
    newnode->name = name_;
    newnode->next = NULL;

    if (*head == NULL)
        *head = newnode;
    else {
        struct node_list *lastnode = *head;

        while (lastnode->next != NULL)
            lastnode = lastnode->next;

        lastnode->next = newnode;
    }
}

/*Do not modify the following function.*/

void print_list(struct node_list *head)
{
    struct node_list *temp = head;

    while (temp != NULL) {
        printf("%d->", temp->data);
        printf("%lf->", temp->number);
        printf("%s", temp->name);
        printf("\t");
        temp = temp->next;
    }

    printf("NULL\n\n");
}

/*Do not modify the following function.*/

void print_array(struct node_list *array, int sizeof_array)
{
    int i;

    for (i = 0; i < sizeof_array; i++) {
        printf("%d->", (array + i)->data);
        printf("%lf->", (array + i)->number);
        printf("%s", (array + i)->name);
        printf("\t");
    }

    printf("NULL\n\n");
}

/*You can modify following functions.*/

struct node_list *merge_list(struct node_list *head_1, struct node_list *head_2)
{
    /*You can modify the entire body of the function including the return statement one line below.*/
    struct node_list *dummy = head_1;
    
    if (!head_1 || !head_2)
        return head_1;

    while (head_1) {
        if (head_1->next == NULL)
            break;
        head_1 = head_1->next;
    }

    head_1->next = head_2;

    return dummy;
    
}
// This function takes two linked lists and merges them according to a certain rule.
struct node_list *merge_interleaved(struct node_list *head_1, struct node_list *head_2)
{
    /*You can modify the entire body of the function including the return statement one line below.*/
    
    struct node_list *one_current = head_1, *two_current = head_2;

    while (one_current && two_current) {
        struct node_list *temp = one_current->next;
        one_current->next = two_current;
        two_current = temp;
        one_current = one_current->next;
    }

    return head_1;
}
// Merged Two Arrays
struct node_list *merge_array(struct node_list *a, int na, struct node_list *b, int nb)
{
    /*You can modify the entire body of the function including the return statement one line below.*/
    struct node_list *p = malloc((na + nb) * sizeof(struct node_list));

    int i = 0, j = 0, k = 0;

    while (i < na && j < nb) {
        if (a)
            p[k++] = a[i++];
        if (b)
            p[k++] = b[j++];
    }

    while (i < na)
        p[k++] = a[i++];

    while (j < nb)
        p[k++] = b[j++];

    free(a);
    free(b);

    return p;
}

int main()
{
    /*Do not modify anything between 95 and 130 lines.*/

    struct node_list *head_1 = NULL;
    struct node_list *head_2 = NULL;
    struct node_list *merged = NULL;
    struct node_list *interleaved = NULL;

    insert_end(&head_1, 10, 1.5, "hello1");
    insert_end(&head_1, 30, 3.5, "hello3");
    insert_end(&head_1, 50, 5.5, "hello5");

    insert_end(&head_2, 20, 2.5, "hello2");
    insert_end(&head_2, 40, 4.5, "hello4");
    insert_end(&head_2, 60, 6.5, "hello6");

    printf("Print List 1: \n");

    print_list(head_1);

    printf("Print List 2: \n");

    print_list(head_2);
    
    merged = merge_list(head_1, head_2);

    printf("Print List Merged: \n");

    print_list(merged);
    
    /*
	interleaved=merge_interleaved(head_1, head_2);
	
	printf("Print List Interleaved: \n");
	
	print_list(interleaved);
 	*/
    /*Do not modify anything between 95 and 130 lines.*/

    struct node_list *arr_1 = malloc(5 * sizeof(struct node_list));
    struct node_list *arr_2 = malloc(SIZE * sizeof(struct node_list));
    //struct node_list arr_1[SIZE];
    //struct node_list arr_2[SIZE];

    struct node_list a_1 = {1, 3., "malatya", NULL};
    struct node_list a_2 = {2, 3., "istanbul", NULL};
    struct node_list a_3 = {3, 3., "eskisehir", NULL};
    struct node_list a_4 = {2, 3., "istanbul", NULL};
    struct node_list a_5 = {3, 3., "eskisehir", NULL};

    struct node_list b_1 = {4, 3., "trabzon", NULL};
    struct node_list b_2 = {5, 3., "izmir", NULL};
    struct node_list b_3 = {6, 3., "ankara", NULL};
    
    arr_1[0] = a_1;
    arr_1[1] = a_2;
    arr_1[2] = a_3;
    arr_1[3] = a_3;
    arr_1[4] = a_3;
    arr_2[0] = b_1;
    arr_2[1] = b_2;
    arr_2[2] = b_3;

    print_array(arr_1, 5);
    print_array(arr_2, SIZE);

    struct node_list *p = merge_array(arr_1, 5, arr_2, SIZE);

    print_array(p, 8);
    
    return 0;
}
