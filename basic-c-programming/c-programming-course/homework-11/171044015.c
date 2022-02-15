/*----------------------------------------------------------------------------
                                BERKCAN EKICI                               
                                  171044015                                 
                                                                            
 Description                                                                
    Homework consists of two parties. In the first part, a dynamic array 
    and linked list are created. They are filled with numbers read from 
    the file. Then transactions are made. In the second part, a dynamic 
    array and linked list are created. These are filled with numbers received 
    from the user and compared.                                                                        
 Notes                                                                      
    It was compiled with the GCC compiler.                                                          
----------------------------------------------------------------------------*/
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
                                Includes
            ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
                                Structs
            ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                */
typedef struct node {
    int number;
    struct node *pnext;
} Node;

typedef struct {
    int n1, n2;
} Wrong;
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
                            Global Variables
            ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                */
Node *gpfirst = NULL;
Node *gpfirst2 = NULL;
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
                          Function Prototypes
            ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                */
int *read_array(const char *filename, int *heap);
Node *read_linkedlist(const char *filename, int *size_list);
float *stats_array(const int *pd);
float *stats_linkedlist(Node *gpfirst, const int *size_list);
Wrong *dynamic_and_list(int *p, Node *, int *) ;

int main()
{
    int array_heap = 0;
    int size_list = 0;
    int p2_size = 0;
    int *p = NULL; //2. part dynamic array
    double sec1 = 0, sec2 = 0, sec3 = 0, sec4 = 0;
    Node *pnewnode = NULL;
    Wrong *my_arr = NULL;

    clock_t start = clock();
    int *arr = read_array("list.txt", &array_heap);
    clock_t end = clock();
    array_heap = 0;
    sec1 += (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    Node *linked_list = read_linkedlist("list.txt", &size_list);
    end = clock();
    size_list = 0;
    gpfirst = NULL;
    sec2 += (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    linked_list = read_linkedlist("list.txt", &size_list);
    end = clock();
    size_list = 0;
    gpfirst = NULL;
    sec2 += (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    arr = read_array("list.txt", &array_heap);
    end = clock();
    array_heap = 0;
    sec1 += (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    arr = read_array("list.txt", &array_heap);
    end = clock();
    array_heap = 0;
    sec1 += (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    linked_list = read_linkedlist("list.txt", &size_list);
    end = clock();
    size_list = 0;
    gpfirst = NULL;
    sec2 += (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    linked_list = read_linkedlist("list.txt", &size_list);
    end = clock();
    sec2 += (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    arr = read_array("list.txt", &array_heap);
    end = clock();
    sec1 += (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    float *array = stats_array(arr);
    end = clock();
    sec3 += (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    float *list = stats_linkedlist(linked_list, &size_list);
    end = clock();
    sec4 += (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nFor read_array funtion:\t\t\t"
           "For read_linkedlist funtion:\n"
           "Number of byte used:%d\t\t"
           "Number of byte used:%d\n"
           "Min:%.2f\t\t\t\t"
           "Min:%.2f\n"
           "Max:%.2f\t\t\t\t"
           "Max:%.2f\n"
           "Mean:%.2f\t\t\t\t"
           "Mean:%.2f\n"
           "STD:%.2f\t\t\t\t"
           "STD:%.2f\n",
           array_heap, size_list * 8, array[0],
           list[0], array[1], list[1], array[2], list[2], array[3], list[3]);

    printf("\nread_array(s) : %f\n", sec1 / 4);
    printf("read_linkedlist(s) : %f\n", sec2 / 4);
    printf("stats_array(s) : %f\n", sec3);
    printf("stats_linkedlist(s) : %f\n", sec4);

    my_arr = dynamic_and_list(p, pnewnode, &p2_size);
    
    for (int i = 0; i < p2_size; ++i)
        printf("%d and %d\n", (my_arr + i)->n1, (my_arr + i)->n2);

    
}
// In this function, the file is read and the information is assigned to a dynamic array.
int *read_array(const char *filename, int *heap)
{
    char c;
    int cnt = 0;              // The index of the dynamic array where numbers are held
    int count = 0;            // Index until comma
    int sum = 0;
    int *pd = NULL;           // Numbers are stored.
    int *digits_count = NULL; // The int value of each character is kept.
    FILE *f = fopen(filename, "r");

    while ((c = fgetc(f)) != EOF) {
        if (c != ',') {
            digits_count = (int *)realloc(digits_count, ((count + 1) * sizeof(int)));
            digits_count[count] = c - 48;
            count++;
        }

        if (c == ',') {
            for (int i = 0; i < count; ++i)
                sum += (pow(10, i) * digits_count[count - i - 1]);

            pd = (int *)realloc(pd, (cnt + 1) * sizeof(int));
            *heap += sizeof(int);

            if (!pd) {
                printf("Memory leak.\n");
                exit(EXIT_FAILURE);
            }

            pd[cnt++] = sum;
            count = 0;
            sum = 0;
        }
    }

    pd[cnt] = -1; // -1 is assigned, the size of the array appears to be 4 bytes more.
    
    *heap += sizeof(int);

    fclose(f);
    free(digits_count);
    
    return pd;    
}

// This function does some mathematical operations on the dynamic array.
float *stats_array(const int *pd) 
{
    float *info_array = (float *)malloc(4*sizeof(float));
    int cnt = 0;
    int max = pd[0];
    int min = pd[0];
    float sum = 0;

    // The max and min values are calculated.
    while (pd[cnt] != -1) {
        if (max < pd[cnt])
            max = pd[cnt];

        if (min > pd[cnt])
            min = pd[cnt];

        sum += pd[cnt];
        ++cnt;
    }
    
    // The mean calculated.
    float mean = sum / cnt;
    cnt = 0;
    
    float subt_sum = 0;
    // STD calculated.
    while (pd[cnt] != -1) {
        int subt = mean - pd[cnt];
        subt_sum += pow(subt, 2);
        ++cnt;
    }

    subt_sum /= (cnt-1);
    
    info_array[0] = min;
    info_array[1] = max;
    info_array[2] = sum / cnt;
    info_array[3] = sqrt(subt_sum);
    return info_array;
}
// This function reads the file and creates and fills the linked list.
Node *read_linkedlist(const char *filename, int *size_list) 
{
    char c;
    int count = 0;
    int sum = 0;
    int heap = 0;
    int *digits_count = NULL;
    Node *pnewnode = NULL;

    FILE *f = fopen(filename, "r");

    while ((c = fgetc(f)) != EOF) {
        if (c != ',') {
            digits_count = (int *)realloc(digits_count, ((count + 1) * sizeof(int)));
            digits_count[count] = c - 48;
            count++;
        }

        if(c == ',') {
            for (int i = 0; i < count; ++i)
                sum += (pow(10, i) * digits_count[count - i - 1]);

            pnewnode = (Node *)malloc(sizeof(Node));
            pnewnode->number = sum;
            pnewnode->pnext = gpfirst;
            gpfirst = pnewnode;
            
            ++*size_list;
            count = 0;
            sum = 0;            
        }
    }

    return gpfirst;
}

// This function does some mathematical operations in the linked list.
float *stats_linkedlist(Node *gpfirst, const int *size_list) 
{
    float *info_array = malloc(4*sizeof(float));
    Node *temp_ptr = gpfirst;

    float max = temp_ptr->number; // The first element of the linked list is assigned to this expression
    float min = temp_ptr->number; // The first element of the linked list is assigned to this expression
    float sum = 0;
    float mean = 0;
    
    // The max and min values are calculated.
    while(temp_ptr) {
        if(max < temp_ptr->number) {
            max = temp_ptr->number;
        }
        if(min > temp_ptr->number) {
            min = temp_ptr->number;
        }
        sum += temp_ptr->number;
        temp_ptr = temp_ptr->pnext;
    }
    // The mean calculated.
    mean = sum / *size_list;

    // The STD calculated.
    float sum_subt = 0;

    while (gpfirst) {
        sum_subt += pow(mean - (gpfirst->number), 2);
        gpfirst = gpfirst->pnext;
    }

    info_array[0] = min;
    info_array[1] = max;
    info_array[2] = mean;
    info_array[3] = sqrt(sum_subt / (*size_list - 1));

    return info_array;
}
// This function is the second part of the assignment. Displays the wrong elements on the screen.
Wrong *dynamic_and_list(int *p, Node *pnewnode, int *p2_size) 
{
    int cnt = 0;
    int array_and_list_size;
    int num;

    printf("\n\nHow many elements will the dynamic array and linked list consist of ?\n");
    scanf("%d", &array_and_list_size);
    printf("Please enter the elements of the dynamic array:\n");

    for (int i = 0; i < array_and_list_size; ++i) {
        scanf("%d", &num);
        
        p = (int *)realloc(p, (cnt+1)*sizeof(int));
        p[cnt++] = num;
    }

    printf("Please enter the elements of the linked list:\n");

    for (int i = 0; i < array_and_list_size; ++i) {
        scanf("%d", &num);
        
        pnewnode = (Node *)malloc(sizeof(Node));
        pnewnode ->number = num;
        pnewnode ->pnext = gpfirst2;
        gpfirst2 = pnewnode;
    }

    Node *temp = gpfirst2;
    Wrong *dynamic_arr = NULL;
    int count = 0;

    // Non-overlapping elements are calculated.
    for (int i = array_and_list_size-1; 0 <= i; --i) {
        if (*(p + i) != temp->number) {
            dynamic_arr = (Wrong *)realloc(dynamic_arr, (count + 1)*sizeof(Wrong));
            (dynamic_arr+count)->n1 = *(p + i);
            (dynamic_arr+count)->n2 = temp->number;
            ++count;
        }
        temp = temp->pnext;
    }

    *p2_size = count;
    
    return dynamic_arr;
}