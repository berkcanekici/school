/*----------------------------------------------------------------------------
                                BERKCAN EKICI                               
                                  171044015                                 
                                                                            
 Description                                                                
    This homework consists of three parts. In the 1st part, recursive 
    calculations are made. A small game is requested in the 2nd part. 
    In the third part, the same letters are recursively deleted.  
                                                                            
 Notes                                                                      
    The 2nd part is not working correctly.                                                           
                                                                            
----------------------------------------------------------------------------*/
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
                                Includes
            ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                */
#include <stdio.h>
#include <math.h>
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
                            Preprocessor Macros
            ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                */
#define ARRAY_SIZE 500
#define MAX_STR_SIZE 512
#define N 8
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          
                         Function Prototypes                              
­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                            */
void menu();
void part_one_menu();
void generate_hofstadters_sequence(int *, int);
int find_max(int[], int, int);
int sum_array(int[]);
double std_array(int[], double *, int, int);
char *my_gets(char *); //  This function is for getting strings.
char *remove_duplicates(char *);
void install_pipes(int[][N], int, int, int);

int main()
{
    menu();
}

void menu()
{
    int choose;
    char str[MAX_STR_SIZE];
    int pipes[N][N] = {0};
    
    do {
        printf("Welcome to Homework 8, please choose one of the parts to continue\n"
            "-------------------------\n"
            "1) Execute Part 1\n"
            "2) Execute Part 2\n"
            "3) Execute Part 3\n"
            "4) Exit\n");
        scanf("%d", &choose);

        switch (choose) {
	        case 1:
	            part_one_menu();
	            break;
	        case 2:
	            install_pipes(pipes, 0, 0, 1);
	            break;
	        case 3:
	            printf("Please enter a string:\n");
	            my_gets(str);
	            my_gets(str);
	            printf("%s\n", remove_duplicates(str));
	            break;
	        case 4:
	            printf("Good Bye!\n");
	            break;
        }
    } while (choose != 4);
}

void part_one_menu()
{
    int choice;
    int sequence[ARRAY_SIZE] = { 0 };
    int n;
    double mean;

    do {
        printf("Please make your choice:\n"
               "---------------------\n"
               "1) Fill Array\n"
               "2) Find Biggest Number\n"
               "3) Calculate Sum\n"
               "4) Calculate Standard Deviation\n"
               "5) Exit\n");
        scanf("%d", &choice);

        switch (choice) {
	        case 1:
	            printf("Please enter n number:\n");
	            scanf("%d", &n);
	            generate_hofstadters_sequence(sequence, n);
	            break;
	        case 2:
	            printf("Max value: %d\n", find_max(sequence, 0, sequence[0]));
	            break;
	        case 3:
	            printf("Sum of array: %d\n", sum_array(sequence));
	            break;
	        case 4:
	            printf("Standard deviation: %f\n", std_array(sequence, &mean, n, 0));
	            break;
	        case 5:
	            break;
        }
    } while (choice != 5);
}

// In this function, the array is filled in.
void generate_hofstadters_sequence(int *arr, int n)
{
    static int index = 0; // This variable keeps track of which index we need to trade.

    if (index < n) {
        if (index == 0 || index == 1)
            arr[index] = 1;
        else
            arr[index] = arr[index - arr[index - 1]] + arr[index - arr[index - 2]];

        ++index;

        generate_hofstadters_sequence(arr, n);
    }

    if (n <= index && index < ARRAY_SIZE) {
        arr[index] = 0;
        ++index;
        generate_hofstadters_sequence(arr, n);
    }
}

// This function finds the biggest element in the array.
int find_max(int arr[], int index, int max_value)
{
    if (index == ARRAY_SIZE)
        return max_value;
    else {
        max_value = max_value > arr[index] ? max_value : arr[index];
        find_max(arr, index + 1, max_value);
    }
}
// This function calculates the sum of the elements in the array.
int sum_array(int arr[])
{   
    if (*arr != 0)
        return *arr + sum_array(arr+1);
}
// This function calculates standard deviation.
double std_array(int arr[], double *mean, int n, int index)
{
    double std_deviation = 0;
    static double sum = 0;
    static int flag = 0;
    static double sum_std;
    static int index_of_std = 0;

    if (index < n && flag != 1) {
        sum += arr[index];
        std_array(arr, mean, n, ++index);
    }

    if (index == n && flag != 1) {
        *mean = sum / index;
        flag = 1;
        ++index;
    }

    if (flag == 1 && index_of_std < n) {
        sum_std += (arr[index_of_std] - *mean) * (arr[index_of_std] - *mean);
        std_array(arr, mean, n, ++index_of_std);
    }

    if (index_of_std == n) {
        std_deviation = sum_std / (n - 1);
        return sqrt(std_deviation);
    }
}

// This function takes a string 
char *my_gets(char *p)
{
    int c;
    char *ptemp = p;

    while ((c = getchar()) != '\n')
        *p++ = c;

    *p = '\0';

    return ptemp;
}

// This function deletes the same elements in the string.
char *remove_duplicates(char *str)
{
    static int index = 0;

    if (str[index] == str[index + 1])
        for (int i = index; str[i] != '\0'; ++i) 
            str[i] = str[i + 1];
    else
        ++index;

    if (str[index] == '\0')
        return str;
    
    remove_duplicates(str);
}
// This function does not work correctly.
void install_pipes(int visited[N][N], int x, int y, int orientation)
{
    static int count = 0;

    switch (orientation) {
	    case 1:
	        if (((x + 2 < 8) && (y + 1 < 8)) && orientation == 1 && visited[x+2][y+1] == 0) {
	            visited[x + 2][y + 1] = 1;
	            x += 2;
	            y++;
	            ++count;
	            printf("x : %d y : %d ==>O1 \n", x, y);
	           //break;
	        }
	        orientation++;
	    case 2:
	        if (((x + 1 < 8) && (0 <= y - 2)) && orientation == 2 && visited[x + 1][y - 2] == 0) {
	            visited[x + 1][y - 2] = 2;
	            x++;
	            y -= 2;
	            ++count;

	            printf("x : %d y : %d ==>O2 \n", x, y);
	            break;
	        }
	        else
	            orientation++;
	    case 3:
	        if (((0 <= x - 2) && (0 <= y - 1)) && orientation == 3 && visited[x - 2][y - 1] == 0) {
	            visited[x - 2][y - 1] = 3;
	            x -= 2;
	            y--;
	            ++count;

	            printf("x : %d y : %d ==>O3 \n", x, y);
	            break;
	        }
	        else
	            orientation++;
	    case 4:
	        if (((0 <= x - 1) && (y + 2 < 8)) && orientation == 4 && visited[x - 1][y + 2] == 0) {
	            visited[x - 1][y + 2] = 4;
	            x--;
	            y += 2;
	            printf("x : %d y : %d ==>O4 \n", x, y);
	            ++count;
	            break;
	        }
	        else
	            orientation++;
	    case 5:
	        if (((x + 1 < 8) && (y + 2 < 8)) && orientation == 5 && visited[x + 1][y + 2] == 0) {
	            visited[x + 1][y + 2] = 5;
	            x++;
	            y += 2;
	            printf("x : %d y : %d ==>O5 \n", x, y);
	            ++count;
	            break;
	        }
	        else
	            orientation++;
	    case 6:
	        if (((x + 2 < 8) && (0 <= y - 1)) && orientation == 6 && visited[x + 2][y - 1] == 0) {
	            visited[x + 2][y - 1] = 6;
	            x += 2;
	            y--;
	            printf("x : %d y : %d ==>O6 \n", x, y);
	            ++count;
	            break;
	        }
	        else
	            orientation++;
	    case 7:
	        if (((0 <= x - 1) && (0 <= y - 2)) && orientation == 7 && visited[x - 1][y - 2] == 0) {
	            visited[x - 1][y - 2] = 7;
	            x--;
	            y -= 2;
	            printf("x : %d y : %d ==>O7 \n", x, y);
	            ++count;
	            break;
	        }
	        else
	            orientation++;
	    case 8:
	        if (((0 <= x - 2) && (y + 1 < 8)) && orientation == 8 && visited[x - 2][y + 1] == 0)
	        {
	            visited[x - 2][y + 1] = 8;
	            x -= 2;
	            y++;
	            ++count;

	            printf("x : %d y : %d ==>O8 \n", x,y);
	        	break;
	        }
	        else
	            orientation++;
    }

    if (orientation < 9 )
        install_pipes(visited, x, y, 1);
    else
        return;
}
/*##############################################################################################################*/
/*                                           End of 171044015.c                                                 */
/*##############################################################################################################*/