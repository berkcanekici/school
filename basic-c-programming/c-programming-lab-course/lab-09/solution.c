/*
    CSE 108 - 9
    Name: Berkcan EKICI
    Id: 171044015
*/
#include <stdio.h>
#include <string.h>

// Macros:
#define    STUDENTS_NUMBER    2
#define    GAME_NUMBER    2

// Struct Declarations:
struct line {
    float x1, y1;
    float x2, y2;
    float x3, y3;
    float m;
};

struct grades {
    float midterm;
    float final;
    float homework;
};

struct students {
    int id;
    char name[30];
    struct grades _grades;
};

struct games {
    char name[30];
    char platform[10];
    float score;
};

// Function declarations:
char *sgets(char *);
void part_one();
void print_part_one(const struct line *);
void calculate_part_one(struct line *);
void part_two();
void part_two_read_informations(struct students *);
void part_two_calculate_averages(const struct students *, struct grades *);
void part_two_print_averages(const struct grades *);
void part_two_search_id(const struct students *);
void part_three();
void part_three_read_informations(struct games *);
void part_three_calculate_averages(const struct games *);
void part_three_list_of_games(const struct games *);

int main()
{
    part_one();
    part_two();  
    part_three();  
}

// Sgets function 
char *sgets(char *p)
{
    char *pret = p;
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
        *p++ = (char)c;
    *p = '\0';

    return pret;
}

// fflush function:
void flushstdin(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Part one function:
void part_one()
{
    struct line my_line;

    printf("Please enter the x1, y1\n");
    scanf("%f%f", &my_line.x1, &my_line.y1);

    printf("Please enter the x2, y2\n");
    scanf("%f%f", &my_line.x2, &my_line.y2);

    printf("Please enter the x3\n");
    scanf("%f", &my_line.x3);

    calculate_part_one(&my_line);
    print_part_one(&my_line);
}

// Calculate m
void calculate_part_one(struct line *l_ptr)
{
    l_ptr->m = (l_ptr->y2 - l_ptr->y1 ) / (l_ptr->x2 - l_ptr->x1);
    l_ptr->y3 = l_ptr->m * (l_ptr->x3 - l_ptr->x2) + l_ptr->y2;
}

// Print part one
void print_part_one(const struct line *l_ptr)
{
    printf("x1: %.2f y1: %.2f\n", l_ptr->x1, l_ptr->y1);
    printf("x2: %.2f y2: %.2f\n", l_ptr->x2, l_ptr->y2);
    printf("x3: %.2f y3: %.2f\n", l_ptr->x3, l_ptr->y3);
    printf("Slope: %.2f\n", l_ptr->m);
}

// Part two function:
void part_two()
{
    struct students arr[STUDENTS_NUMBER];
    struct grades averages;
    
    part_two_read_informations(arr);
    part_two_calculate_averages(arr, &averages);
    part_two_print_averages(&averages);
    part_two_search_id(arr);
}

// Part two read informations:
void part_two_read_informations(struct students *p)
{
    for (int i = 0; i < STUDENTS_NUMBER; ++i) {
        char name[30];
        printf("Please enter the student's id: ");
        scanf("%d", &p[i].id);
        //fflush(stdin);
        //scanf("%[^\n]%*c", p[i].name);
        printf("Please enter the student's name-surname: ");
        flushstdin();
        sgets(name);
        strcpy(p[i].name, name);
        printf("Please enter the midterm-final-homework note: ");
        scanf("%f%f%f", &p[i]._grades.midterm, &p[i]._grades.final, 
                        &p[i]._grades.homework);
    }
}

// Part two calculate averages:
void part_two_calculate_averages(const struct students *sp, struct grades *gp)
{
    float average_midterm = 0.;
    float average_final = 0.;
    float average_homeworks = 0.;

    for (int i = 0; i < STUDENTS_NUMBER; ++i) {
        average_midterm += sp[i]._grades.midterm;
        average_final += sp[i]._grades.final;
        average_homeworks += sp[i]._grades.homework;
    }

    gp->midterm = average_midterm / STUDENTS_NUMBER;
    gp->final = average_final / STUDENTS_NUMBER;
    gp->homework = average_homeworks / STUDENTS_NUMBER;
}

// Part two print:
void part_two_print_averages(const struct grades *gp)
{
    printf("Average of midterm: %.2f\n", gp->midterm);
    printf("Average of final: %.2f\n", gp->final);
    printf("Average of homeworks: %.2f\n", gp->homework);
}

// Part two search id:
void part_two_search_id(const struct students *sp)
{
    int id;

    printf("Please enter an id: ");
    scanf("%d", &id);

    for (int i = 0; i < STUDENTS_NUMBER; ++i) {
        if (sp[i].id == id) {
            printf("Id: %d\n", sp[i].id);
            printf("Name: %s\n", sp[i].name);
            printf("Midterm: %.2f\n", sp[i]._grades.midterm);
            printf("Final: %.2f\n", sp[i]._grades.final);
            printf("Homeworks: %.2f\n", sp[i]._grades.homework);
            return;
        }
    }

    printf("Such a student could not be found\n");
}

// Part three function:
void part_three()
{
    struct games arr[GAME_NUMBER];
    part_three_read_informations(arr);
    part_three_calculate_averages(arr);
    part_three_list_of_games(arr);

}

// Part three read informations:
void part_three_read_informations(struct games *gp)
{
    for (int i = 0; i < GAME_NUMBER; ++i) {
        flushstdin();
        printf("Please enter the game's name: ");
        sgets(gp[i].name);
        printf("Please enter the game's platform: ");
        sgets(gp[i].platform);
        printf("Please enter the score: ");
        scanf("%f", &gp[i].score);
    }
}

// Part three calculate averages:
void part_three_calculate_averages(const struct games *gp)
{
    float average = 0.;
    for (int i = 0; i < GAME_NUMBER; ++i) 
        average += gp[i].score;
    
    printf("Games average: %f\n", average / GAME_NUMBER);
}

// Part three list of platforms:
// hata duzeltilecek:
void part_three_list_of_games(const struct games *gp)
{
    char platforms[GAME_NUMBER][10];
    int count = 0;
    int flag = 0;

    for (int i = 0; i < GAME_NUMBER; ++i) {
        for (int k = 0; k < count + 1; ++k) {
            if (!strcmp(platforms[i], gp[i].platform)) {
                flag = 1;
                break;
            }
        }
        
        if (flag == 0) {
            strcpy(platforms[count], gp[i].platform);
            ++count;
            flag = 0;
        }
    }
   
    for (int i = 0; i < count; ++i) {
        printf("%s games: ", platforms[i]);
        for (int k = 0; k < GAME_NUMBER; ++k) {
            if (!strcmp(gp[k].platform, platforms[i])) {
                printf("%s ", gp[i].name);
            }
        }
    }
}