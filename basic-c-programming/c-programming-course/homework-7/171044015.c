/*
    Description
        This program reads a file and gather some informations about video games and
        initialize an array with those informations. Since the size of the file is
        unknown, size is defined as a macro. The tasks in the PDF are dividev into
        functions. This tasks are executed due to the gathered informations.
        This program compiled and tested with GCC compiler.

                                BERKCAN EKICI
                                  171044015
*/
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                                            */
/*                                          Includes                                          */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                                            */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                                            */
/*                                    Preprocessor Macros                                     */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                                            */
#define MAX_LINE_LENGTH         200
#define MAX_GAME_NAME_LENGTH    100
#define MAX_LINE                5000
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                                            */
/*                                    Function Prototypes                                     */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                                            */
void menu(void); // Displaying the menu.
void get_all_information(float[][7], char[][100], char[][15], char[][15], int *, int *, int *); // An array initialized with all information from the file.
void games_through_the_years(float [][7], char[][100], int *); // Printing the name of the names due to the release years.
void get_all_information_single_game(float[][7], char[][100], char[][15], char[][15], int *); // Printing the all information about an intended game.
void calculates_average_user_score(float[][7], int *); // Calculating the average score of the users.
void georograhical_information_single_game(float[][7], char [][100], int *); // Prints the information about the popularity of the game due to the regions.
void frequence_genre(float[][7], char[][15], int *, int *); // Calculates the frequency of the genres.
void frequence_platform(float[][7], char[][15], int *, int *); // Calculates the frequency of the platforms.

int main()
{
    menu();
}

void menu()
{
    int option;
    int option_flag[8] = {0, 0, 0, 0, 0, 0, 0, 0}; // Flag of previuosly done options.
    char names[MAX_LINE][100]; // This array holds the names of the games.
    char genres[100][15]; // This array holds the genres of the games.
    char platforms[100][15]; // This array holds the platforms of the games.
    float data[MAX_LINE][7]; // This array holds all the informations.
    int genre_index, platform_index; // This variables hold the number of the genres and the platforms.
    int all_information_index; // This variable holds the number of lines in the read file.
    
    // All the information is gathered from this function.
    get_all_information(data, names, genres, platforms, &all_information_index, &genre_index, &platform_index);

    do
    {
        printf("\n0: List of the Genres\n"
               "1: List of the Platforms\n"
               "2: List of the Games Through the Years\n"
               "3: All Informations of a Single Game\n"
               "4: Average of the User Scores\n"
               "5: Georographical Information of a Single Game\n"
               "6: Frequence of the Genres\n"
               "7: Frequence of the Platforms\n"
               "8: Exit\n\n"
               "Please select an operation :");
        scanf("%d", &option);

        switch (option) {
        case 0:
            if (!option_flag[0]) {
                for (int i = 0; i < genre_index; ++i)
                    printf("%s\n", genres[i]);

                printf("\n\n");
                option_flag[0] = 1;
            }
            else
                printf("This option has already been made.\n");
            break;
        case 1:
            if (!option_flag[1]) {
                for (int i = 0; i < platform_index; ++i)
                    printf("%s\n", platforms[i]);

                printf("\n\n");
                option_flag[1] = 1;
            }
            else
                printf("This option has already been made.\n");
            break;
        case 2:
            if (!option_flag[2]) {
                games_through_the_years(data, names, &all_information_index);
                printf("\n\n");
                option_flag[2] = 1;
            }
            else
                printf("This option has already been made.\n");
            break;
        case 3:
            if (!option_flag[3]) {
                get_all_information_single_game(data, names, genres, platforms, &all_information_index);
                printf("\n\n");
                option_flag[3] = 1;
            }
            else
                printf("This option has already been made.\n");
            break;
        case 4:
            if (!option_flag[4]) {
                calculates_average_user_score(data, &all_information_index);
                printf("\n\n");
                option_flag[4] = 1;
            }
            else
                printf("This option has already been made.\n");
            break;
        case 5:
            if (!option_flag[5]) {
                georograhical_information_single_game(data, names, &all_information_index);
                printf("\n\n");
                option_flag[5] = 1;
            }
            else
                printf("This option has already been made.\n");
            break;
        case 6:
            if (!option_flag[6]) {
                frequence_genre(data, genres, &genre_index, &all_information_index);
                option_flag[6] = 1;
            }
            else
                printf("This option has already been made.\n");
            break;
        case 7:
            if (!option_flag[7]) {
                frequence_platform(data, platforms, &platform_index, &all_information_index);
                option_flag[7] = 1;
            }
            else
                printf("This option has already been made.\n");
            break;
        case 8:
            printf("Good Bye\n");
            break;
        default:
            printf("TRY AGAIN.\n\n");
        }
    } while (option != 8);
}
// All the information gathered through this function.
void get_all_information(float data[MAX_LINE][7], char names[MAX_LINE][100], char genres[100][15], char platforms[100][15], int *all_information_index, int *genre_number, int *platform_number)
{
    int first_line_flag = 0; // To skip the first line of the file.
    int data_count = 0;     // Number of the lines in the file.
    char line[MAX_LINE_LENGTH]; // Holds the line that is currently read from the file.
    int genres_index = 0;   // Number of genre variaty.
    int platforms_index = 0; // Number of platform variaty.
    int names_index = 0;   // Index of the names.

    FILE *f = fopen("Video_Games.txt", "r");

    // Name, genre and platform informations of the games is gathered in this loop.
    while (fscanf(f, "%s", line) != EOF)
    {
        int count = 0;
        char *token = strtok(line, ",");

        while (token != NULL) {
            // Read names copied to names array.
            if (count == 0 && first_line_flag != 0) {
                strcpy(names[names_index], token);
                names_index++;
            }
            // Read genre copied to genres array if it differ from the previously copied ones.
            if (count == 1 && first_line_flag != 0) {
                int i;

                for (i = 0; i < 100; ++i)
                    if (!strcmp(genres[i], token))
                        break;
                
                if (i == 100) {
                    strcpy(genres[genres_index], token);
                    ++genres_index;
                }
            }
            // Read platform copied to platforms array if it differ from the previously copied ones.
            if (count == 2 && first_line_flag != 0) {
                int i;

                for (i = 0; i < 100; ++i)
                    if (!strcmp(platforms[i], token))
                        break;

                if (i == 100) {
                    strcpy(platforms[platforms_index], token);
                    ++platforms_index;
                }
            }
            token = strtok(NULL, ",");
            ++count;
        }

        if (first_line_flag == 0)
            first_line_flag = 1;
    }
    // Calculating the number of genres and platforms for the printing process in the menu function.
    *genre_number = genres_index;
    *platform_number = platforms_index;

    // After the first three elements, an array initialized with all the informations.
    first_line_flag = 0;
    fseek(f, 0L, SEEK_SET);
    // Initializing the float array.
    while (fscanf(f, "%s", line) != EOF) {
        int count = 0;

        char *token = strtok(line, ",");

        while (token != NULL) {
            token = strtok(NULL, ",");
            // Genre indices are assigned to the float array's 0th index.
            if (count == 0 && first_line_flag != 0)
                for (int i = 0; i < genres_index; ++i) 
                    if (!strcmp(genres[i], token)) {
                        data[data_count][count] = i;
                        break;
                    }
            
            // Platform indices are assigned to the float array's 1st index.
            if (count == 1 && first_line_flag != 0)
                for (int i = 0; i < platforms_index; ++i)
                    if (!strcmp(platforms[i], token)) {
                        data[data_count][count] = i;
                        break;
                    }
                
            
            // Years are assigned to the float array's 2nd index.
            if (count == 2 && first_line_flag != 0)
                data[data_count][count] = strtod(token, NULL);
            
            // Sales in NA are assigned to the float array's 3rd index.
            if (count == 3 && first_line_flag != 0)
                data[data_count][count] = strtod(token, NULL);
            
            // Sales in EU are assigned to the float array's 4th index.
            if (count == 4 && first_line_flag != 0)
                data[data_count][count] = strtod(token, NULL);
            
            // Total Sales are assigned to the float array's 5th index.
            if (count == 5 && first_line_flag != 0)
                if (!strcmp(token, "not_available")) // If it is not_available, -1 is assigned for control intension.
                    data[data_count][count] = -1;
                else
                    data[data_count][count] = strtod(token, NULL);
                
            // User Scores are assinged to the float array's 6th index.
            if (count == 6 && first_line_flag != 0)
                data[data_count][count] = strtod(token, NULL);

            ++count;
        }

        if (first_line_flag == 0)
            first_line_flag = 1;
        else
            ++data_count;
    }
    // Number of the games in the file.
    *all_information_index = data_count;
    fclose(f);
}
// This function prints the name of the games due to their release years.
void games_through_the_years(float data[MAX_LINE][7], char names[MAX_LINE][100], int *all_idx)
{
    int year;
    int until_or_since;
    char game_name[MAX_GAME_NAME_LENGTH];

    printf("\nEnter a year:\n");
    scanf("%d", &year);
    printf("Until (0) or Since(1)   %d:", year);

    do {
        scanf("%d", &until_or_since);
        
        if (until_or_since != 0 && until_or_since != 1)
            printf("TRY AGAIN.\n");

    } while (until_or_since != 0 && until_or_since != 1);

    double convert_year;
    int game_count = 0;

    // Checking until the number of the rows is reached.
    for (int i = 0; i < *all_idx; ++i) {
        if (data[i][2] < year && until_or_since == 0) {
            printf("%s\n", names[i]);
            ++game_count;
        }

        if (year < data[i][2] && until_or_since == 1) {
            printf("%s\n", names[i]);
            ++game_count;
        }
    }
    // If there is  o such a game, function calls itself.
    if (game_count == 0) {
        printf("TRY AGAIN.\n");
        games_through_the_years(data, names, all_idx);
    }
}
// This funciton prints the all information about a wamted game.
void get_all_information_single_game(float data[MAX_LINE][7], char names[MAX_LINE][100], char genres[100][15], char platforms[100][15], int *all_idx)
{
    char game_name[MAX_GAME_NAME_LENGTH];
    int flag = 0;
    
    printf("\nPlease enter the name of the game:\n");
    scanf("%s", game_name);

    // Checking until the number of lines is reached.
    for (int i = 0; i < *all_idx; ++i)
        if (!strcmp(game_name, names[i])) {
            flag = 1;

            int genre_index = data[i][0];
            int platform_index = data[i][1];

            printf("Name:            %s\n", game_name);
            printf("Genre:           %s\n", genres[genre_index]);
            printf("Platform:        %s\n", platforms[platform_index]);
            printf("Year:            %.0f\n", data[i][2]);
            printf("Sales In NA:     %f\n", data[i][3]);
            printf("Sales In EU:     %f\n", data[i][4]);
            
            if (data[i][5] == -1)
                printf("Total Sales:     Not Available\n");
            else
                printf("Total Sales:     %f\n", data[i][5]);
            
            printf("User score:      %f\n", data[i][6]);
            
            break;
        }
    // If there is no such a game, function calls itself.
    if (flag == 0) {
        printf("\nThere is no such game name in the file. TRY AGAIN!\n");
        get_all_information_single_game(data, names, genres, platforms, all_idx);
    }
}

// This function calculates the average of the user scores of all the games.
void calculates_average_user_score(float data[MAX_LINE][7], int *all_index)
{
    double average = 0;

    for (int i = 0; i < *all_index; ++i) 
        average += data[i][6];

    printf("Average: %f\n", average / *all_index);
}

// This function determines the popularity of the game due to the regions.
void georograhical_information_single_game(float data[MAX_LINE][7], char names[MAX_LINE][100], int *all_idx)
{
    char game_name[MAX_GAME_NAME_LENGTH];
    int is_word_flag = 0;

    printf("\nPlease enter the name of the game:\n");
    scanf("%s", game_name);
    // Checking until the number of the lines is reached.
    for (int i = 0; i < *all_idx; ++i)
        if (!strcmp(names[i], game_name)) {
            is_word_flag = 1;

            if (data[i][3] > data[i][4])
                printf("This game was more popular in North America.\n");
            else if (data[i][4] > data[i][3])
                printf("This game was more popular in Europe.\n");
            else
                printf("The popularity of this game in Europe and North America was equal.\n");

            break;
        }
    // If there is no such a game, the function calls itself.
    if (is_word_flag == 0) {
        printf("\nThere is no such game name in the file. TRY AGAIN!\n");
        georograhical_information_single_game(data, names, all_idx);
    }
}
// This function calculates the number of the games that have the same genre.
void frequence_genre(float data[MAX_LINE][7], char genres[100][15], int *genre_num, int *all_index)
{
    int genres_count[100];
    int count = 0;

    // Outer loop checks for every genre.
    for (int i = 0; i < *genre_num; ++i)
    {
        // Inner loop checks al the lines for a genre.
        for (int k = 0; k < *all_index; ++k)
        {
            if ((int)data[k][0] == i)
            {
                count++;
            }
        }
        genres_count[i] = count;
        printf("%-24s%d\n", genres[i], genres_count[i]);
        count = 0;
    }
    printf("\n\n");
}
// This function calculates the number of the games that have the same platform.
void frequence_platform(float data[MAX_LINE][7], char platforms[100][15], int *platform_num, int *all_index)
{
    int platforms_count[100];
    int count = 0;

    //  Outer loop checks for every platform
    for (int i = 0; i < *platform_num; ++i) {
        // Inner loop checks all the lines for a platform.
        for (int k = 0; k < *all_index; ++k)
            if ((int)data[k][1] == i)
                count++;

        platforms_count[i] = count;

        printf("%-24s%d\n", platforms[i], count);
        
        count = 0;
    }
    
    printf("\n\n");
}

/*##################################################################################################*/
/*                                      End of 171044015.c                                          */
/*##################################################################################################*/
