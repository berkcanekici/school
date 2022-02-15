/* This program aims to create a puzzle map and fill it with 10 randomly chosen words.
After the creation of the map, the program allows the user to play the puzzle game
by entering a word and a coordinate. if the user's guess is right, the found word's letters
are cahbged into all caps. if the all 10 words are found or the user enters "EXIT", the program ends 
                                BERKCAN EKICI
                                  171044015
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define    SIZE    100
#define    ROW     20
#define    COL     20

void randomize();
void rand_word_generator(char *, char [][20]);
void rand_word_placement(char[][20]);
int game_play(char[][20], char[][20]);
char *sgets(char *);

int main()
{
    char words[SIZE][20];
    randomize();
    rand_word_generator("words.txt", words);
    rand_word_placement(words);
}
// this function seeds the pseudo-random number generator used by rand() with the value seed.
void randomize()
{
    srand((unsigned)time(NULL));
}
// this function reads all the words in "words.txt" and assign them into the words array.
void rand_word_generator(char *file_path, char arr[][20])
{
    char c;

    FILE *f = fopen(file_path, "r");

    for (int i = 0; i < SIZE; ++i)
        fgets(arr[i], 20, f);
    
    fclose(f);
}
// this function choose random 10 words and place them into the game area in 8 directions.
void rand_word_placement(char arr[SIZE][20])
{
    char rand_words[10][20];
    char area[ROW][COL];

    randomize();

    // initializing the game area with '.' characters to prevent from the placed words overlaps in any point.
    for (int i = 0; i < ROW; ++i)
        for (int k = 0; k < COL; ++k)
            area[i][k] = '.';

    // 10 random words is chosed
    for (int i = 0; i < 10; ++i) {
        int randnum = rand() % 100;
        strcpy(rand_words[i], arr[randnum]);
    }

    for (int i = 0; i < 10; ++i) {
        int length = strlen(rand_words[i]) - 2;
        int rand_x = rand() % 20;
        int rand_y = rand() % 20;
        int direction = rand() % 8 + 1;
        printf("%s", rand_words[i]);
        // determining coordinates for left to right word placecement
        if (1 == direction)
        {
            while (rand_y + length > 19)
                rand_y = rand() % 20;
        }
        // determining coordinates for right to left word placecement
        else if (2 == direction)
        {
            while (rand_y - length < 0)
                rand_y = rand() % 20;
        }
        // determining coordinates for top to bottom word placecement
        else if (3 == direction)
        {
            while (rand_x + length > 19)
            {
                rand_x = rand() % 20;
            }
        }
        // determining coordinates for bottom to top word placecement
        else if (4 == direction)
        {
            while (rand_x - length < 0)
            {
                rand_x = rand() % 20;
            }
        }
        // determining coordinates for top-left to bottom-right word placecement
        else if (5 == direction)
        {
            while ((rand_x + length > 19) || (rand_y + length > 19))
            {
                rand_x = rand() % 20;
                rand_y = rand() % 20;
            }
        }
        // determining coordinates for top-right to bottom-left word placecement
        else if (6 == direction)
        {
            while ((rand_x + length > 19) || (rand_y - length < 0))
            {
                rand_x = rand() % 20;
                rand_y = rand() % 20;
            }
        }
        // determining coordinates for bottom-left to top-right word placecement
        else if (7 == direction)
        {
            while ((rand_x - length < 0) || (rand_y + length > 19))
            {
                rand_x = rand() % 20;
                rand_y = rand() % 20;
            }
        }
        // determining coordinates for bottom-right to top-left word placecement
        else if (8 == direction)
        {
            while ((rand_x - length < 0) || (rand_y - length < 0))
            {
                rand_x = rand() % 20;
                rand_y = rand() % 20;
            }
        }
        int rand_y_temp;
        int rand_x_temp;
        switch (direction)
        {
            case 1: // left to right word placecement
                // this loop checks if the word to be placed overlaps the already placed words
                while(1) {
                    int k = 0;
                    rand_y_temp = rand_y;
                    for(k = 0; k < length; ++k) {
                        if(area[rand_x][rand_y] == '.') {
                            ++rand_y;
                        }
                        else {
                            break;
                        }
                    }

                    if(k == length) {
                        break;
                    }
                    else {
                        while (1) // this loop checks if the length of the placed word exceeds the length of the game area in the detemined coordinate.
                        {
                            rand_x = rand() % 20;
                            rand_y = rand() % 20;
                            if (rand_y + length <= 19) {
                                break;
                            }
                        }
                    }
                }
                // this loop places the word to be placed if it provides the convinient conditions.
                for(int k = 0; k < length; ++k) {
                    area[rand_x][rand_y_temp] = rand_words[i][k];
                    ++rand_y_temp;
                }
                break;
            case 2: // sagdan sola left to right word placecement
                // this loop checks if the word to be placed overlaps the already placed words
                while (1)
                {
                    int k = 0;
                    rand_y_temp = rand_y;
                    for (k = 0; k < length; ++k)
                    {
                        if (area[rand_x][rand_y] == '.')
                        {
                            --rand_y;
                        }
                        else
                        {
                            break;
                        }
                    }

                    if (k == length)
                    {
                        break;
                    }
                    else
                    {
                        while (1) // this loop checks if the length of the placed word exceeds the length of the game area in the detemined coordinate.
                        {
                            rand_x = rand() % 20;
                            rand_y = rand() % 20;
                            if (rand_y - length >= 0)
                            {
                                break;
                            }
                        }
                    }
                }
                // this loop places the word to be placed if it provides the convinient conditions.
                for(int k = 0; k < length; ++k) {
                    area[rand_x][rand_y_temp] = rand_words[i][k];
                    --rand_y_temp;
                }
                break;
            case 3: // yukaridan asagiya left to right word placecement
                // this loop checks if the word to be placed overlaps the already placed words
                while (1)
                {
                    int k = 0;
                    rand_x_temp = rand_x;
                    for (k = 0; k < length; ++k)
                    {
                        if (area[rand_x][rand_y] == '.')
                        {
                            ++rand_x;
                        }
                        else
                        {
                            break;
                        }
                    }

                    if (k == length)
                    {
                        break;
                    }
                    else
                    {
                        while (1) // this loop checks if the length of the placed word exceeds the length of the game area in the detemined coordinate.
                        {
                            rand_x = rand() % 20;
                            rand_y = rand() % 20;
                            if (rand_x + length <= 19)
                            {
                                break;
                            }
                        }
                    }
                }
                // this loop places the word to be placed if it provides the convinient conditions.
                for(int k = 0; k < length; ++k) {
                    area[rand_x_temp][rand_y] = rand_words[i][k];
                    ++rand_x_temp;
                }
                break;
            case 4: // asagidan yukariya left to right word placecement
                // this loop checks if the word to be placed overlaps the already placed words
                while (1)
                {
                    int k = 0;
                    rand_x_temp = rand_x;
                    for (k = 0; k < length; ++k)
                    {
                        if (area[rand_x][rand_y] == '.')
                        {
                            --rand_x;
                        }
                        else
                        {
                            break;
                        }
                    }

                    if (k == length)
                    {
                        break;
                    }
                    else
                    {
                        while (1) // this loop checks if the length of the placed word exceeds the length of the game area in the detemined coordinate.
                        {
                            rand_x = rand() % 20;
                            rand_y = rand() % 20;
                            if (rand_x - length >= 0)
                            {
                                break;
                            }
                        }
                    }
                }
                // this loop places the word to be placed if it provides the convinient conditions.
                for(int k = 0; k < length; ++k) {
                    area[rand_x_temp][rand_y] = rand_words[i][k];
                    --rand_x_temp;
                }
                break;
            case 5: // yukaridan sag asagiya left to right word placecement
                // this loop checks if the word to be placed overlaps the already placed words
                while (1)
                {
                    int k = 0;
                    rand_x_temp = rand_x;
                    rand_y_temp = rand_y;
                    for (k = 0; k < length; ++k)
                    {
                        if (area[rand_x][rand_y] == '.')
                        {
                            ++rand_x;
                            ++rand_y;
                        }
                        else
                        {
                            break;
                        }
                    }

                    if (k == length)
                    {
                        break;
                    }
                    else
                    {
                        while (1) // this loop checks if the length of the placed word exceeds the length of the game area in the detemined coordinate.
                        {
                            rand_x = rand() % 20;
                            rand_y = rand() % 20;
                            if ((rand_x + length <= 19) && (rand_y + length <= 19))
                            {
                                break;
                            }
                        }
                    }
                }
                // this loop places the word to be placed if it provides the convinient conditions.
                for(int k = 0; k < length; ++k) {
                    area[rand_x_temp][rand_y_temp] = rand_words[i][k];
                    ++rand_x_temp;
                    ++rand_y_temp;
                }
                break;
            case 6: // left to right word placement
                // this loop checks if the word to be placed overlaps the already placed words
                while (1)
                {
                    int k = 0;
                    rand_x_temp = rand_x;
                    rand_y_temp = rand_y;
                    for (k = 0; k < length; ++k)
                    {
                        if (area[rand_x][rand_y] == '.')
                        {
                            ++rand_x;
                            --rand_y;
                        }
                        else
                        {
                            break;
                        }
                    }

                    if (k == length)
                    {
                        break;
                    }
                    else
                    {
                        while (1) // this loop checks if the length of the placed word exceeds the length of the game area in the detemined coordinate.
                        {
                            rand_x = rand() % 20;
                            rand_y = rand() % 20;
                            if ((rand_x + length <= 19) && (rand_y - length >= 0))
                            {
                                break;
                            }
                        }
                    }
                }
                // this loop places the word to be placed if it provides the convinient conditions.
                for(int k = 0; k < length; ++k) {
                    area[rand_x_temp][rand_y_temp] = rand_words[i][k];
                    ++rand_x_temp;
                    --rand_y_temp;
                }
                break;
            case 7: // left to right word placement
                // this loop checks if the word to be placed overlaps the already placed words
                while (1)
                {
                    int k = 0;
                    rand_x_temp = rand_x;
                    rand_y_temp = rand_y;
                    for (k = 0; k < length; ++k)
                    {
                        if (area[rand_x][rand_y] == '.')
                        {
                            --rand_x;
                            ++rand_y;
                        }
                        else
                        {
                            break;
                        }
                    }

                    if (k == length)
                    {
                        break;
                    }
                    else
                    {
                        while (1) // this loop checks if the length of the placed word exceeds the length of the game area in the detemined coordinate.
                        {
                            rand_x = rand() % 20;
                            rand_y = rand() % 20;
                            if ((rand_x - length >= 0) && (rand_y + length <= 19))
                            {
                                break;
                            }
                        }
                    }
                }
                // this loop places the word to be placed if it provides the convinient conditions.
                for(int k = 0; k < length; ++k) {
                    area[rand_x_temp][rand_y_temp] = rand_words[i][k];
                    --rand_x_temp;
                    ++rand_y_temp;
                }
                break;
            case 8: // left to right word placecement
                // this loop checks if the word to be placed overlaps the already placed words
                while (1)
                {
                    int k = 0;
                    rand_x_temp = rand_x;
                    rand_y_temp = rand_y;
                    for (k = 0; k < length; ++k)
                    {
                        if (area[rand_x][rand_y] == '.')
                        {
                            --rand_x;
                            --rand_y;
                        }
                        else
                        {
                            break;
                        }
                    }

                    if (k == length)
                    {
                        break;
                    }
                    else
                    {
                        while (1) // this loop checks if the length of the placed word exceeds the length of the game area in the detemined coordinate.
                        {
                            rand_x = rand() % 20;
                            rand_y = rand() % 20;
                            if ((rand_x - length >= 0) && (rand_y - length >= 0))
                            {
                                break;
                            }
                        }
                    }
                }
                // this loop places the word to be placed if it provides the convinient conditions.
                for(int k = 0; k < length; ++k) {
                    area[rand_x_temp][rand_y_temp] = rand_words[i][k];
                    --rand_x_temp;
                    --rand_y_temp;
                }
                break;
            default:
                break;
        }
    }
    int count = 0; //number of the words that is found by the user
    for(;;) {
        // displaying the game area
        printf("  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 \n");
        for (int i = 0; i < ROW; ++i)
        {
            for (int k = 0; k < COL; ++k)
            {
                if(0 == k)
                    printf("%c ", 'A'+ i);
                if(area[i][k] == '.')
                    printf("%c  ", 'A' + (rand()%26));
                else
                    printf("%c  ", area[i][k]);
            }

            printf("\n\n");
        }
        if (10 == count)
        {
            printf("Congratulations, you won the game.\n");
            break;
        }
        if (game_play(area, rand_words)) {
            printf("Congratulations you found the word.\n");
            count++;
        }
    }
}
// this function asks user to enter a coordinate and a word. in the entered coordinate, the program searches for the entered word in the all 8 direction.
// if the word is found, the program change it's letters to all caps.
int game_play(char area[][20], char rand_words[][20]) {
    char horizontal_dir;
    int vertical_dir;
    char word[20];
    // assigning alphabetic characters of the coordinates that still contains the '.' character.
    for(int i = 0; i < 10; ++i) {
        for(int k = 0; k < strlen(rand_words[i]); ++k) {
            printf("%c", rand_words[i][k]);
        }
    }
    printf("\nPlease enter the coordinate and word: \n");
    scanf(" %c%d ", &horizontal_dir, &vertical_dir);
    sgets(word);
    if(horizontal_dir == 'E' && !strcmp(word, "XIT")) {
        exit(EXIT_SUCCESS);
    }
    int length = strlen(word);
    // checking if the entered word is the same with at least one of the randomly chosen words.
    int i;
    for(i = 0; i < 10; ++i) {
        if(!strncmp(rand_words[i], word, strlen(rand_words[i])-2)) {
            length = strlen(rand_words[i]) -2;
            break;
        }
    }
    // if not, function ends
    if(i == 10) {
        printf("There is no such word.\n");
        return 0;
    }

    // searching the directions
    int dir = 1;
    int flag = 0;
    if(1 == dir) { // searching from left to right
        for(int i = 0; i < length; ++i) {
            if(area[horizontal_dir - 65][vertical_dir - 1 + i] == word[i]) {
                flag = 1;
            }
            else {
                flag = 0;
                break;
            }
        }
        if(1 == flag) { // make the letters all caps
            for(int i = 0; i < length; ++i) {
                area[horizontal_dir - 65][vertical_dir - 1 + i] = area[horizontal_dir - 65][vertical_dir - 1 + i]-32;
            }
            return 1;
        }
        else {
            dir = 2;
        }
    }
    if(2 == dir) { // searching from right to left
        for(int i = 0; i < length; ++i) {
            if(area[horizontal_dir-65][vertical_dir-1-i] == word[i]) {
                flag = 1;
            }
            else {
                flag = 0;
                break;
            }
        }
        if(1 == flag) { // make the letters all caps
            for (int i = 0; i < length; ++i) {
                area[horizontal_dir - 65][vertical_dir - 1 - i] = area[horizontal_dir - 65][vertical_dir - 1 - i] - 32;
            }
            return 1;
        }
        else {
            dir = 3;
        }
    }
    if(3 == dir) { // searching from top to bottom
        for (int i = 0; i < length; ++i)
        {
            if (area[horizontal_dir - 65 + i][vertical_dir - 1] == word[i])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if(1 == flag) { // make the letters all caps
            for(int i = 0; i < length; ++i) {
                area[horizontal_dir - 65 + i][vertical_dir - 1] = area[horizontal_dir - 65 + i][vertical_dir - 1] - 32;
            }
            return 1;
        }
        else {
            dir = 4;
        }
    }
    if(4 == dir) { // searching from bottom to top
        for (int i = 0; i < length; ++i)
        {
            if (area[horizontal_dir - 65 - i][vertical_dir - 1] == word[i])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if(1 == flag) { // make the letters all caps
            for (int i = 0; i < length; ++i)
            {
                area[horizontal_dir - 65 - i][vertical_dir - 1] = area[horizontal_dir - 65 - i][vertical_dir - 1] - 32;
            }
            return 1;
        }
        else
        {
            dir = 5;
        }
    }
    if(5 == dir) { // searching from top-left to bottom-right
        for (int i = 0; i < length; ++i)
        {
            if (area[horizontal_dir - 65 + i][vertical_dir - 1 + i] == word[i])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (1 == flag) // make the letters all caps
        {
            for (int i = 0; i < length; ++i)
            {
                area[horizontal_dir - 65 + i][vertical_dir - 1 + i] = area[horizontal_dir - 65 + i][vertical_dir - 1 + i] - 32;
            }
            return 1;
        }
        else
        {
            dir = 6;
        }
    }
    if(6 == dir) { // searching from top-right to bottom-left
        for (int i = 0; i < length; ++i)
        {
            if (area[horizontal_dir - 65 + i][vertical_dir - 1 - i] == word[i])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (1 == flag) // make the letters all caps
        {
            for (int i = 0; i < length; ++i)
            {
                area[horizontal_dir - 65 + i][vertical_dir - 1 - i] = area[horizontal_dir - 65 + i][vertical_dir - 1 - i] - 32;
            }
            return 1;
        }
        else
        {
            dir = 7;
        }
    }
    if(7 == dir) { // searching from the bottom-left to top-right
        for (int i = 0; i < length; ++i)
        {
            if (area[horizontal_dir - 65 - i][vertical_dir - 1 + i] == word[i])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (1 == flag) // make the letters all caps
        {
            for (int i = 0; i < length; ++i)
            {
                area[horizontal_dir - 65 - i][vertical_dir - 1 + i] = area[horizontal_dir - 65 - i][vertical_dir - 1 + i] - 32;
            }
            return 1;
        }
        else
        {
            dir = 8;
        }
    }
    if(8 == dir) { // searching from the bottom-right to top-left
        for (int i = 0; i < length; ++i)
        {
            if (area[horizontal_dir - 65 - i][vertical_dir - 1 - i] == word[i])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }
        if (1 == flag) // make the letters all caps
        {
            for (int i = 0; i < length; ++i)
            {
                area[horizontal_dir - 65 - i][vertical_dir - 1 - i] = area[horizontal_dir - 65 - i][vertical_dir - 1 - i] - 32;
            }
            return 1;
        }
        else
        {
            printf("There is no such word.\n");
            return 0; // function ends here.
        }
    }
}
// this function get a word from the user
char *sgets(char *p)
{
    int c;
    char *ptemp = p;

    while ((c = getchar()) != '\n')
        *p++ = c;

    *p = '\0';

    return ptemp;
}
