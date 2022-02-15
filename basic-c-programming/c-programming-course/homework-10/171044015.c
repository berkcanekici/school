/*----------------------------------------------------------------------------
                                BERKCAN EKICI                               
                                  171044015                                 
                                                                            
 Description                                                                
    This assignment reads some information from one file and writes it to another. 
    The information read is stored in different structures.
                                                                            
 Notes                                                                      
    I couldn't do the operations involving polygons. I'm sorry, sir.                                                           
                                                                            
----------------------------------------------------------------------------*/
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
                                Includes
            ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
                            Preprocessor Macros
            ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                */
#define MAX_LINE_LENGTH 100
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
                               Structures
            ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                */
typedef struct point {
    double x[100];
    double y[100];
} points;

typedef struct line {
    double x[2];
    double y[2];
    char line_name[100];
} lines;

typedef struct polygon {
    points a[20];
    lines b[20];
    char polygon_name[100];
} polygons;
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          
                         Function Prototypes                              
­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                            */
void read_file(const char *); // In this function, points and truths are calculated and stored in two different structures.
void calculations(points, lines[100], char *); // Mathematical operations are performed in this function.

int main()
{
    read_file("commands.txt");
}

void read_file(const char *filename)
{
    int count = 0;   // Used to cross the first 2 lines.
    int p_count = 0; // Dot or line flag
    int l_count = 0; // Dot or line flag
    int pg_count = 0;
    int p_index = 0;
    int l_index = 0;
    int data_num = 0; // Calculate whether to get the data number correctly.
    int lines_count = 0;
    int polygons_count = 0;
    int slash_flag = 0;

    char *cp;
    char line[MAX_LINE_LENGTH];
    char temp_line[MAX_LINE_LENGTH];

    lines lines_index[100];
    points points_index;
    polygons polygons_index[100];
    FILE *f = fopen(filename, "r");

    while (1) {
        cp = fgets(line, sizeof(line), f);

        if (cp == NULL)
            break;

        if (!strncmp(line, "actions", strlen("actions")))
            break;

        cp = strstr(line, "//");

        if (cp != NULL) {
            slash_flag = 1;
            *cp++ = '\n';
            *cp = 0;
        }

        count++;

        if (count == 2)
            data_num = atoi(line);

        // Determines what the row contains.
        if (count > 2) {
            strcpy(temp_line, line);
            
            char *token = strtok(line, " ");

            while (token) {
                if (strchr(token, 'P'))
                    ++p_count;

                if (strchr(token, 'L'))
                    ++l_count;
                
                if (strchr(token, 'P') && strchr(token, 'G'))
                    ++pg_count;
                
                token = strtok(NULL, " ");
            }
        }

        if (1 == p_count && 0 == l_count) {                                         
            char *token = strtok(temp_line, " "); // The X coordinate is obtained by this process.
            double temp_x = atoi(token);

            token = strtok(NULL, " "); // The Y coordinate is obtained by this process.
            double temp_y = atoi(token);

            token = strtok(NULL, " "); // This process, the number of points is calculated.
            for (int i = 0; i < strlen(token); ++i)
                token[i] = token[i + 1];

            int index = atoi(token); // Index is assigned.

            points_index.x[index - 1] = temp_x;
            points_index.y[index - 1] = temp_y;
        }

        if (2 == p_count && 1 == l_count) { // This is a line.
            char *token = strtok(temp_line, " ");

            for (int i = 0; i < strlen(token); ++i)
                token[i] = token[i + 1];

            int first_p_index = atoi(token);
            lines_index[lines_count].x[0] = points_index.x[first_p_index - 1];
            lines_index[lines_count].y[0] = points_index.y[first_p_index - 1];
            
            token = strtok(NULL, " ");
            for (int i = 0; i < strlen(token); ++i)
                token[i] = token[i + 1];

            int second_p_index = atoi(token);
            lines_index[lines_count].x[1] = points_index.x[second_p_index - 1];
            lines_index[lines_count].y[1] = points_index.y[second_p_index - 1];
            
            token = strtok(NULL, " ");
            strcpy(lines_index[lines_count].line_name, token);
            ++lines_count;
        }

        if (1 == pg_count) { // This is a polygon. But it doesn't work correctly.
            char *token = strtok(temp_line, " ,\n");
            
            if (strchr(token, 'P') && !strchr(token, 'G')) {
                for (int i = 0; i < strlen(token); ++i)
                    token[i] = token[i + 1];

                polygons_index[polygons_count].a[polygons_count].x[p_index] = points_index.x[atoi(token) - 1];
                polygons_index[polygons_count].a[polygons_count].y[p_index] = points_index.y[atoi(token) - 1];
                
                ++p_index;
            }

            if (strchr(token, 'L')) {
                int i;
                for (i = 0; i < lines_count; ++i) {
                    if (!strncmp(token, lines_index[i].line_name, 3))
                        break;

                polygons_index[polygons_count].b[l_index].x[0] = lines_index[i].x[0];
                polygons_index[polygons_count].b[l_index].x[1] = lines_index[i].x[1];
                polygons_index[polygons_count].b[l_index].y[0] = lines_index[i].y[0];
                polygons_index[polygons_count].b[l_index].y[1] = lines_index[i].y[1];
                
                strcpy(polygons_index[polygons_count].b[l_index].line_name, lines_index[i].line_name);
                
                ++l_index;
            }

            if (strchr(token, 'P') && strchr(token, 'G')) {
                strcpy(polygons_index[polygons_count].polygon_name, token);
                polygons_count++;
            }

            while (token) {
                if (strstr(token, "PG"))
                    break;

                token = strtok(NULL, " ,\n");
                if (strchr(token, 'P') && !strchr(token, 'G')) {
                    for (int i = 0; i < strlen(token); ++i)
                        token[i] = token[i + 1];
                    
                    polygons_index[polygons_count].a[polygons_count].x[p_index] = points_index.x[atoi(token) - 1];
                    polygons_index[polygons_count].a[polygons_count].y[p_index] = points_index.y[atoi(token) - 1];
                    ++p_index;
                }

                if (strchr(token, 'L')) {
                    int i;
                    for (i = 0; i < lines_count; ++i)
                        if (!strncmp(token, lines_index[i].line_name, 3))
                            break;

                    polygons_index[polygons_count].b[l_index].x[0] = lines_index[i].x[0];
                    polygons_index[polygons_count].b[l_index].x[1] = lines_index[i].x[1];
                    polygons_index[polygons_count].b[l_index].y[0] = lines_index[i].y[0];
                    polygons_index[polygons_count].b[l_index].y[1] = lines_index[i].y[1];
                    
                    strcpy(polygons_index[polygons_count].b[l_index].line_name, lines_index[i].line_name);
                    
                    ++l_index;
                }

                if (strchr(token, 'P') && strchr(token, 'G')) {
                    strcpy(polygons_index[polygons_count].polygon_name, token);
                    polygons_count++;
                }
            }
        }

        p_count = 0;
        l_count = 0;
        pg_count = 0;
        l_index = 0;
        p_index = 0;
    }

    // This part for I deleted in the beginning.(//)
    for (int i = 0; i < lines_count; ++i)
        if (!strchr(lines_index[i].line_name, '\n'))
        {
            int len = strlen(lines_index[i].line_name);

            lines_index[i].line_name[len] = '\n';
        }

    fclose(f);

    calculations(points_index, lines_index, filename); // The information I store in the structure is processed.
}

void calculations(points points_index, lines lines_index[100], char *filename)
{
    int count = 0;
    int actions_flag = 0;
    int actions_count;
    int flag_actions_count = 0;
    int p_count = 0;
    int l_count = 0;

    char *cp;
    char first_temp_token[MAX_LINE_LENGTH];
    char second_temp_token[MAX_LINE_LENGTH];

    char outputs_name[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char temp_line[MAX_LINE_LENGTH];

    FILE *f = fopen(filename, "r");
    FILE *fp; // For output file.

    while (1) {
        cp = fgets(line, sizeof(line), f);
        
        if (cp == NULL)
            break;
        
        cp = strstr(line, "//");

        if (!strncmp(line, "actions", strlen("actions")))
            actions_flag = 1;

        if (1 == actions_flag)
            ++count;
        
        if (2 == count) {
            strncpy(outputs_name, line, strlen(line) - 2);
            fp = fopen(outputs_name, "w");
        }

        if (3 == count)
            actions_count = atoi(line);

        if (3 < count && 1 == actions_flag) {
            strcpy(temp_line, line);
            char *temp_token = strtok(temp_line, " ");
            while (temp_token) {
                if (strchr(temp_token, 'P'))
                    ++p_count;
                
                if (strchr(temp_token, 'L'))
                    ++l_count;
                
                if (!strcmp(temp_token, "//"))
                    break;

                temp_token = strtok(NULL, " ");
            }

            char *token = strtok(line, " ");

            if (!strcmp("Distance", token) && p_count == 2) { // The distance between two points is calculated.
                token = strtok(NULL, " ");

                strcpy(first_temp_token, token); 
                
                // The letter P is destroyed.
                for (int i = 0; i < strlen(token); ++i) {
                    token[i] = token[i + 1];
                    first_temp_token[i] = first_temp_token[i + 1];
                }
                
                // Indexes are calculated.
                int first_index_x = points_index.x[atoi(token)];
                int first_index_y = points_index.y[atoi(token)];

                // 2. X and y of the point are calculated.
                token = strtok(NULL, " ");
                strcpy(second_temp_token, token);
                for (int i = 0; i < strlen(token); ++i) {
                    token[i] = token[i + 1];
                    second_temp_token[i] = second_temp_token[i + 1];
                }

                int second_index_x = points_index.x[atoi(token)];
                int second_index_y = points_index.y[atoi(token)];
                
                // The distance between two points is calculated.
                double result = sqrt(pow((first_index_x - second_index_x), 2) + pow((first_index_y - second_index_y), 2));
                fprintf(fp, "Distance(P%d,P%d) = %.2f\n", atoi(first_temp_token), atoi(second_temp_token), result);

                ++flag_actions_count;

                memset(first_temp_token, 0, sizeof(first_temp_token));
                memset(second_temp_token, 0, sizeof(second_temp_token));
            }

            if (!strcmp("Distance", token) && 1 == p_count && 1 == l_count) { // Calculates the distance between a line and a point
                double x1, x2, y1, y2;
                double p_x, p_y;
                char temp_l_index[100];
                char temp_p_index[100];

                token = strtok(NULL, " ");

                if (strchr(token, 'L')) {
                    for (int i = 0; i < 100; ++i)
                        if (!strcmp(lines_index[i].line_name, token)) {
                            x1 = lines_index[i].x[0];
                            y1 = lines_index[i].y[0];
                            x2 = lines_index[i].x[1];
                            y2 = lines_index[i].y[1];
                        }
                    strcpy(temp_l_index, token);
                }
                else if (strchr(token, 'P')) {
                    strcpy(temp_p_index, token);
                    
                    for (int i = 0; i < strlen(token); ++i)
                        token[i] = token[i + 1];

                    p_x = points_index.x[atoi(token) - 1];
                    p_y = points_index.y[atoi(token) - 1];
                }

                token = strtok(NULL, " ");

                if (strchr(token, 'L')) {
                    for (int i = 0; i < 100; ++i)
                        if (!strncmp(lines_index[i].line_name, token, strlen(lines_index[i].line_name) - 1)) {
                            x1 = lines_index[i].x[0];
                            y1 = lines_index[i].y[0];
                            x2 = lines_index[i].x[1];
                            y2 = lines_index[i].y[1];
                            break;
                        }
                    strcpy(temp_l_index, token);
                }
                else if (strchr(token, 'P')) {
                    strcpy(temp_p_index, token);

                    for (int i = 0; i < strlen(token); ++i)
                        token[i] = token[i + 1];

                    p_x = points_index.x[atoi(token) - 1];
                    p_y = points_index.y[atoi(token) - 1];
                }

                for (int i = 0; i < strlen(temp_l_index); ++i)
                    temp_l_index[i] = temp_l_index[i + 1];

                for (int i = 0; i < strlen(temp_p_index); ++i)
                    temp_p_index[i] = temp_p_index[i + 1];

                double m = (y2 - y1) / (x2 - x1);
                double a = m;
                double b = -1;
                double c = -1 * m * x2 + y2;
                double result = (a * p_x) + (b * p_y) + c;

                if (result < 0)
                    result *= -1;

                result /= sqrt(pow(p_x, 2) + pow(p_y, 2));

                fprintf(fp, "Distance(P%d,L%d) = %.2f\n", atoi(temp_p_index), atoi(temp_l_index), result);

                ++flag_actions_count;
            }

            if (!strcmp("Angle", token)) { // The angle between the two lines is calculated.
                double x1, x2, y1, y2;
                char temp_first_token[100];
                char temp_second_token[100];

                token = strtok(NULL, " ");
                strcpy(temp_first_token, token);

                for (int i = 0; i < strlen(temp_first_token); ++i)
                    temp_first_token[i] = temp_first_token[i + 1];
                
                for (int i = 0; i < 100; ++i)
                    if (!strncmp(lines_index[i].line_name, token, strlen(lines_index[i].line_name) - 1)) {
                        x1 = lines_index[i].x[1] - lines_index[i].x[0];
                        y1 = lines_index[i].y[1] - lines_index[i].y[0];
                        break;
                    }
                
                token = strtok(NULL, " ");
                strcpy(temp_second_token, token);

                for (int i = 0; i < strlen(temp_second_token); ++i) 
                    temp_second_token[i] = temp_second_token[i + 1];

                for (int i = 0; i < 100; ++i) {
                    if (!strncmp(lines_index[i].line_name, token, strlen(lines_index[i].line_name) - 1))
                    {
                        x2 = lines_index[i].x[1] - lines_index[i].x[0];
                        y2 = lines_index[i].y[1] - lines_index[i].y[0];
                        break;
                    }

                double x_sum = x1 * x2;
                double y_sum = y1 * y2;

                double result = (x_sum + y_sum) / (sqrt(pow(x1, 2) + pow(y1, 2)) * sqrt(pow(x2, 2) + pow(y2, 2)));

                result = acos(result);
                result = (result * 180) / 3.14;

                fprintf(fp, "Angle(L%d,L%d) = %.2f\n", atoi(temp_first_token), atoi(temp_second_token), result);
                ++flag_actions_count;
            }

            if (!strcmp("Length", token) && 2 == l_count) { // Calculates the length of a line.
                double x1, x2, y1, y2;
                
                token = strtok(NULL, " ");
                
                for (int i = 0; i < 100; ++i)
                    if (!strncmp(lines_index[i].line_name, token, strlen(lines_index[i].line_name) - 1)) {
                        x1 = lines_index[i].x[0];
                        y1 = lines_index[i].y[0];
                        x2 = lines_index[i].x[1];
                        y2 = lines_index[i].y[1];
                        break;
                    }
                
                for (int i = 0; i < strlen(token); ++i)
                    token[i] = token[i + 1];

                double result = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

                fprintf(fp, "Length (L%d) = %.2f\n", atoi(token), result);

                ++flag_actions_count;
            }

            if (actions_count == flag_actions_count)
                break;

            memset(temp_line, 0, sizeof(temp_line));
            
            p_count = 0;
            l_count = 0;
        }
    }
    
    fclose(f);
    fclose(fp);
}
/*##############################################################################################################*/
/*                                           End of 171044015.c                                                 */
/*##############################################################################################################*/