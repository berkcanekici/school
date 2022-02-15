/*----------------------------------------------------------------------------
                                BERKCAN EKICI                               
                                  171044015                                 
                                                                            
 Description                                                                
    This homework consists of three parts. In the first part, the program   
    reads the files that wanted to read. The second part lists all the      
    read news files. And finally in the last part, the program makes some   
    calculations due to the given functions by using the magic numbers in   
    the files.                                                              
                                                                            
 Notes                                                                      
    Since the string.h library is prohibited, i wrote my own string         
    functions.                                                              
                                                                            
----------------------------------------------------------------------------*/
/*
­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          
                               Includes                                   
­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                            */
#include <stdio.h>
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          
                         Function Prototypes                              
­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                            */
void menu();
void read_news(char [], char [], int); // the third parameter is the is_Only_Title. it changes in the source file.
void append_file(char *, char );
void print_readed_news(char *);
void read_magic_numbers(char [], char []);
double f_func(int );
double g_func(double(*)(int), int);
int check_file(char *, char); // this function checks if the file has been read before.
void my_strcat(char *, const char *); // implementation of the strcat function. it is void because no return value has been used.
void my_memset(void *, int, int); // implementation of the memset function. it is void because no return value has been used.
int my_strcmp(const char *, const char *); // implementation of the strcmp function. if two strings are the same, the function returns 0.

int main() 
{
    menu();
}

void menu() 
{
    char option; // choice of ending or continuing the program.
    char select; // selection of the menu's alternatives.
    char new_select; // holds the information of which news is going to be read.
    char magic_select; // holds the information of which file is going to be read while calculating the result of magic numbers.
    char buffer[500]; // holds the text in the read file.
    char file_path[10]; // holds the file names.
    int read_again; // holds the information of which file has been read before.


    do {
        printf("\n\n**********Daily Press**************\n\n"
            "Today's news are listed for you :\n\n");
        read_news(buffer, "1.txt", 1);     // first file sent to the function to be read.
        printf("\n");
        read_news(buffer, "2.txt", 1);     // second file sent to the function to be read.
        printf("\n");
        read_news(buffer, "3.txt", 1);     // third file sent to the function to be read.
        printf("\n");
        read_news(buffer, "4.txt", 1);   // fourth file sent to the function to be read.
        printf("\n\nWhat do you want to do?\n"
            "a.Read a new\n"
            "b.List the readed news\n"
            "c.Get decrypted information from the news\n");
        scanf(" %c", &select);

        switch (select) {
            case 'a':
                printf("Which news do you want to read ?");
                scanf(" %c", &new_select);
                // if the file has not been read before, index of the file added to the "readed_news_id.txt".
                if(check_file("readed_news_id.txt", new_select) == 0) {
                    append_file("readed_news_id.txt", new_select);
                    file_path[0] = new_select; // the index of the file that desired to be read is kept in an array.
                    my_strcat(file_path, ".txt"); // ".txt" added to the end of the index of the file that desired to be read.
                    read_news(buffer, file_path, 0); // file is read.
                    my_memset(file_path, 0, sizeof(file_path)); // clear the array.
                }
                // program asks the user if he/she wants to read that file again, if the file has been read.
                else if (check_file("readed_news_id.txt", new_select) == 1) {
                    printf("\nThis new is readed. Do you want to read again? Yes(1) / No(0)\n");
                    scanf("%d", &read_again);
                    // if the answer is 1, the file is read again, but its index is not added to the "readed_news_id.txt"
                    if (read_again == 1) {
                        file_path[0] = new_select;
                        my_strcat(file_path, ".txt");
                        read_news(buffer, file_path, 0);
                        my_memset(file_path, 0, sizeof(file_path));
                    }
                }
                break;
            case 'b':
                printf("Readed news are listed below:\n");
                print_readed_news("readed_news_id.txt");
                break;
            case 'c':
                printf("Which news would you like to decrypt?");
                scanf(" %c", &magic_select); // get the file name that desired to decrypt.
                file_path[0] = magic_select; // the file name is kept in an array.
                my_strcat(file_path, ".txt"); // ".txt" added to the end of the file name.
                read_magic_numbers(file_path, buffer);
                my_memset(file_path, 0, sizeof(file_path)); // clear array from the file name.
        }

        printf("\nDo you want to continue? Yes(y)/No(n):\n");
        scanf(" %c", &option);

        if (option == 'n')
            printf("Good Bye!\n");
        
    } while (option != 'n');
}

void read_news(char buffer[500], char file_path[10], int is_Only_Title) 
{
    int i = 0;
    char full_dir[20] = "./news/"; // directory name is kept in an array.
    my_strcat(full_dir, file_path); // file name is added to the end of the directory name

    FILE *fp= fopen(full_dir, "r");
    if (is_Only_Title == 1) {
        while ((buffer[i] = fgetc(fp)) != '\n') {
            putchar(buffer[i]);
            ++i;
        }
    }
    else if(is_Only_Title == 0) {
        while((buffer[i] = fgetc(fp)) != EOF)
            putchar(buffer[i]);
            ++i;
    }
    fclose(fp);
}

void append_file(char *file_path, char c) 
{
    FILE *fp = fopen(file_path, "a"); // file is opened in append mode to not to delete the previous file names.
    fprintf(fp, "%c\n", c);
    fclose(fp);
}

// checks if the file has been read before.
int check_file(char *file_path, char c) 
{
    char check;

    FILE *fp = fopen(file_path, "r");

    while ((fscanf(fp, "%c", &check)) != EOF) {
        if (check == c)
            return 1; // if the file has been read before, the function returns 1.
    }

    fclose(fp);
    return 0; // if not, the function returns 0.
}

// this function lists the names of the files that have been read before.
void print_readed_news(char *file_path) 
{
    char news;

    FILE *fp = fopen(file_path, "r");

    while ((news = fgetc(fp)) != EOF) {
        if (news != ' ' && news != '\n')
            printf("%c. new readed\n", news);
    }

    fclose(fp);
}

// this function finds the magic numbers and calculates the result due to the formula that has been given.
void read_magic_numbers(char buffer_magic[10], char buffer_news[500]) 
{
    int flag = 0;
    int i = 0;
    double sum = 0;
    char full_dir[20] = "./news/"; // directory name is kept in an array.
    
    my_strcat(full_dir, buffer_magic); // file name is added to the end of the directory name.
    
    FILE *fp = fopen(full_dir, "r");

    while ((buffer_news[i] = fgetc(fp)) != EOF) {
        putchar(buffer_news[i]);
        if (buffer_news[i] == '#') {
            flag = 1;
            continue; // to read the character after the '#' sign.
        }
        if (1 == flag) {
            flag = 0;
            sum += g_func(&f_func, (buffer_news[i]-48));
        }
        ++i;
    }
    printf("\n");
    // the results are printed due to the file names.
    if (my_strcmp(buffer_magic, "1.txt") == 0) {
        printf("number of tests performed:%lf\n", sum);
    }
    else if (my_strcmp(buffer_magic, "2.txt") == 0) {
        printf("number of sick people:%lf\n", sum);
    }
    else if (my_strcmp(buffer_magic, "3.txt") == 0) {
        printf("number of deaths:%lf\n", sum);
    }
    else if (my_strcmp(buffer_magic, "4.txt") == 0) {
        printf("expected number of sick people:%lf\n", sum);
    }

    fclose(fp);
}

// this function applies the calculationg in the pdf to the magic numbers in the read file.
double f_func(int x) 
{
    return (x*x*x) - (x*x) + 2;
}

// this function applies the calculationg in the pdf to the magic numbers in the read file. the first parameter is an address of a function. the second parameter is a magic number.
double g_func(double(*f)(int), int a) 
{
    return f(a) * f(a);
}

// this function sets a memory space. i used this function to clear the arrays that kept the file names. therefore it does not return an address.
void my_memset(void *vp, int val, int n) 
{
    unsigned char *p = vp;

    while (n--)
        *p++ = (unsigned char)val;
    
}

//implementation of the strcat function. no return value is needed so it's type is void.
void my_strcat(char *pdest, const char *psource) 
{
    char *ptemp = pdest;

    while (*pdest)
        pdest++;
    while (*pdest++ = *psource++)
        ;
}

// string comparison function.
int my_strcmp(const char *p1, const char *p2) 
{	
    while (*p1 == *p2) {
		if (*p1 == '\0')
			return 0;
		++p1;
		++p2;
	}

	return *p1 - *p2;
}
/*##############################################################################################################*/
/*                                           End of 171044015.c                                                 */
/*##############################################################################################################*/