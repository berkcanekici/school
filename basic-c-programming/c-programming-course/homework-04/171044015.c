/*##########################################################################*/
/* ­­­­­­­­­                            HW_04                                        */
/*                         BERKCAN EKICI                                    */
/*                           171044015                                      */
/* ­­­­­­­­­                                                                         */
/* Created on 24/03/2020 by Berkcan EKICI                                   */
/*                                                                          */
/* Description                                                              */
/* ­­­­­­­­­­­                                                                         */
/*    This program consists of four parts. In the first and the second      */
/*    part, we read a file of integers and decrypt the file due to          */
/*    formula in PDF.                                                       */
/*    In the third part, the program prints a 11*11 coordinate system,      */
/*    which shows the locations of the enemy's base and our base. Due to    */
/*    the enemy's base's coordinates, the program calculates the            */
/*    displacement of the enemy's base and the distance apart from our      */
/*    base. Finally in the last part, we encrypt the characters using       */
/*    the formula in the PDF, and print the resulting numbers to another    */
/*    file.                                                                 */
/*                                                                          */
/* Notes                                                                    */
/* ­­­­­                                                                         */
/*    This file is prepared and compressed in Ubuntu 18.04 LTS.             */
/*    Comments may be seem as corrupted on Windows OS.                      */
/*    Compiled and tested with GCC.                                         */
/*                                                                          */
/*##########################################################################*/
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
/*                               Includes                                   */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <math.h>
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
/*                         Preprocessor Macros                              */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
#define    SIZE    11
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
/*                         Function Prototypes                              */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
void randomize(); // Include srand function.                                
void menu();
void decrypt_and_print (char*);
char decrypt_numbers (int);
void deep_decrypt_and_print(char *);
void track_machine();
void refresh_position(int *, int *, double *, double *);
void encrypt_messages(char *);
int foo(char); // Returns a value to a character.                            

int main()
{
    randomize();
    menu();
}
void randomize() 
{
    srand((unsigned)time(NULL));
}
void menu() 
{
    int option;
    do {
        printf("1-) Decrypt and print encrypted_p1.img\n"
            "2-) Decrypt and print encrypted_p2.img\n"
            "3-) Switch on the tracking machine\n"
            "4-) Encrypt the message\n"
            "5-) Switch off\n\n"
            "Please make your choice\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                decrypt_and_print("encrypted_p1.img");
                break;
            case 2:
                deep_decrypt_and_print("encrypted_p2.img");
                break;
            case 3:
                track_machine();
                break;
            case 4:
                encrypt_messages("decrypted_p4.img");
                break;
            case 5:
                printf("Successfully exit.\n");
                break;
            default:
                printf("False selection. Please enter between 1-4 numbers.\n\n");
                break;
        }
    } while (option != 5);
}
// This function reads a character from the file. Converts the character that       
// have been read to its equivalent character and prints it on the console.         
void decrypt_and_print(char *file_path) 
{
    int number;
    FILE *fp = fopen(file_path, "r");

    while ((number = fgetc(fp)) != EOF) {
        if(number == '\n')
            putchar('\n');
        else
            putchar(decrypt_numbers(number));
    }
    fclose(fp);
}
// This function performs the conversion of the characters that have been read in
// the above function.                                                              
char decrypt_numbers(int number) 
{
    char chr;
    switch(number) {
        case 48: chr = ' '; break;
        case 49: chr = '-'; break;
        case 50: chr = '_'; break;
        case 51: chr = '|'; break;
        case 52: chr = '/'; break;
        case 53: chr = '\\'; break;
        case 54: chr = 'O'; break;
        default: break;
    }
    return chr;
}
// This function reads the characters in the file and according to a specific
// formula, converts them into other characters. The converted characters are       
// printed on the console.       
void deep_decrypt_and_print(char *file_path) 
{
    int result = 0; // This variable keeps the sum. 
    int count = 0;  // This variable is to know where the cursor is. 
    int number;     // This variable is the current character that have been read from the file. 
    int mode;       // This variable holds the result of the modula operation. 

    FILE *fp = fopen(file_path, "r");
    // This loops continues until the end of file.
    while ((number = fgetc(fp)) != EOF) {
        // If the current is '\n', print a new line and the values of the count and the result changed into 0. 
        if(number == '\n') {
            putchar('\n');
            count = 0;
            result = 0;
        }
        // If the current character is not current will be added to the result.
        else {
            result += number - 48;
            count++;
            // If the count reached to 3, result will be printed to the console. 
            // Move the cursor backwards by 2.
            if(3 == count) {
                mode = result % 7;
                putchar(decrypt_numbers(mode + 48));
                count = 0;
                result = 0;
                fseek(fp, -2, SEEK_CUR);
            }
        }
    }
    fclose(fp);
}
// This function creates a 11 * 11 coordinate system that shows the locations
// of the enemy, and our base.
// The position of the enemy is random and generates by the program. its 
// displacement and its distance from our position are calculated.   
void track_machine() 
{
    int x_our = 6;
    int y_our = 6;
    int x_enemy = 1;
    int y_enemy = 1;
    char select;
    double displacement = sqrt(pow(x_enemy - 1, 2) + pow(y_enemy - 1, 2));
    double distance = sqrt(pow((6 - x_enemy), 2) + pow((6 - y_enemy), 2));

    do {
        for (int i = 1; i <= SIZE; ++i) {
            for (int k = 1; k <= SIZE; ++k) {
                if (i == x_our && k == y_our)
                    printf("O\t");
                if (i == x_enemy && k == y_enemy)
                    printf("E\t");
                if (!(i == x_our && k == y_our) && !(i == x_enemy && k == y_enemy))
                    printf(".\t");
            }
            putchar('\n');
        }
        printf("Enemies X position: %d, Y position: %d, Displacement: %.2f, Distance to our camp: %.2f\n", 
        x_enemy, y_enemy, displacement, distance);
        printf("Command waiting...:");
        scanf(" %c", &select);
        if (select == 'R') {
            refresh_position(&x_enemy, &y_enemy, &displacement, &distance);
            if (x_enemy == 6 && y_enemy == 6) {
                printf("You cannot enter the country of the Turks ! You lost!\n");
                break;
            }
        }
    } while (select != 'E');
}
// This function generates two random numbers from 0 up to 11 for the coordinates
// of the enemy's base.
// Also it calculates the displacement and the distance quantities.
void refresh_position(int *X, int *Y, double *D, double *R) 
{
    int temp_x = *X;
    int temp_y = *Y;
    *X = rand() % SIZE + 1;
    *Y = rand() % SIZE + 1;    
    *D = sqrt((pow(*X - temp_x, 2) + pow(*Y - temp_y, 2)));
    *R = sqrt(pow((6 - *X), 2) + pow((6 - *Y), 2));
}
// In this function we convert to characters to integers due to he given format, 
// and print the resulting integers to another file.
void encrypt_messages(char *file_path) 
{

    int number;         // This variable holds the characters of the input file.
    int sum = 0;        // This variable holds the sum of each three characters.
    int line_count = 0; // This variable checks the first to characters of the input file.
    int count = 0;      // This flag checks if the cursor reached the third number or not.

    FILE *fp = fopen("decrypted_p4.img", "r");
    FILE *fout = fopen("encrypted_p4.txt", "w");
    // This loop continues until the end of the file.
    while ((number = fgetc(fp)) != EOF) {
        // Every current character will be added to the sum, and the count will be
        // increased by the number of the added caracers.                                                                
        sum += foo(number);
        count++;
        // If the cursor is on first two numbers of a line, 0 will be added to the sum.
        if (line_count < 2 && number != '\n') {
            fprintf(fout, "%d", sum);
            ++line_count;
        }
        // If the count is 3 and the current character is not '\n', sum will be 
        // printed to the output file. Move cursor backwards by two character.
        if (3 == count && number != '\n') {
            fprintf(fout, "%d", sum % 7);
            fseek(fp, -2, SEEK_CUR);
            sum = 0;
            count = 0;
        }
        // If the current is '\n', a new line character will be printed and all the variables 
        // will be changed into 0.
        else if (number == '\n') {
            fprintf(fout, "\n");
            line_count = 0;
            sum = 0;
            count = 0;
        }
    }
    fclose(fp);
    fclose(fout);
}
// This function, convert the characters that have been read in the above function due to 
// the given format.
int foo(char c) 
{
    int a;
    switch(c) {
        case ' ':  a = 0; break;
        case '-':  a = 1; break;
        case '_':  a = 2; break;
        case '|':  a = 3; break;
        case '/':  a = 4; break;
        case '\\': a = 5; break;
    }
    return a;
}
/*##############################################################################################################*/
/*                                           End of 171044015.c                                                 */
/*##############################################################################################################*/