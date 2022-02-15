#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib.h"

#define PI 3.14159265

Figure *read_commands_defaults(const char *command, const char *defaults)
{
    Figure default_settings;
    char *t;
    char buffer[500];
    char ch;
    int i = 0, flag = 1, num;

    Figure *head, *root;
    root = (Figure *)malloc(sizeof(Figure));
    head = root;

    FILE *file_ptr = fopen(defaults, "r");
    FILE *ptr;

    if (file_ptr != NULL)
    {
        while (fscanf(file_ptr, "%c", &ch) != EOF)
        {
            if (ch == '/')
                flag = 0;

            if (ch != '\n' && flag)
            {
                buffer[i] = ch;
                i++;
            }
            if (ch == '\n')
            {

                buffer[i] = '\0';
                i = 0;
                flag = 1;

                t = strtok(buffer, ":");

                if (strcmp("grid_color", t) == 0)
                {
                    t = strtok(NULL, "(");
                    sscanf(t, "%lf,%lf,%lf", &default_settings.grid_color.red, &default_settings.grid_color.green, &default_settings.grid_color.blue);
                }
                if (strcmp("foreground_color", t) == 0)
                {
                    t = strtok(NULL, "(");
                    sscanf(t, "%lf,%lf,%lf", &default_settings.foreground_color.red, &default_settings.foreground_color.green, &default_settings.foreground_color.blue);
                }
                if (strcmp("background_color", t) == 0)
                {
                    t = strtok(NULL, "(");
                    sscanf(t, "%lf,%lf,%lf", &default_settings.background_color.red, &default_settings.background_color.green, &default_settings.background_color.blue);
                }
                if (strcmp("pattern_thickness", t) == 0)
                {
                    t = strtok(NULL, ":");
                    sscanf(t, "%lf", &default_settings.pattern_thickness);
                }
                if (strcmp("grid_thickness", t) == 0)
                {
                    t = strtok(NULL, ":");
                    sscanf(t, "%lf", &default_settings.grid_thickness);
                }
                if (strcmp("tile_size", t) == 0)
                {
                    t = strtok(NULL, ":");
                    sscanf(t, "%lf", &default_settings.tile_size);
                }
                if (strcmp("canvas_size", t) == 0)
                {
                    t = strtok(NULL, "(");
                    sscanf(t, "%lf,%lf", &default_settings.canvas_size.x, &default_settings.canvas_size.y);
                }
                if (strcmp("show_grid", t) == 0)
                {
                    t = strtok(NULL, ":");
                    if (strncmp("False", t, 4) == 0)
                        default_settings.show_grid = 0;
                    if (strncmp("True", t, 4) == 0)
                        default_settings.show_grid = 1;
                }
                if (strcmp("angle_offset", t) == 0)
                {
                    t = strtok(NULL, "(");
                    sscanf(t, "%lf,%lf", &default_settings.angle_offset.x, &default_settings.angle_offset.y);
                }
            }
        }
    }
    fclose(file_ptr);

    ptr = fopen(command, "r");

    if (ptr != NULL)
    {
        while (fscanf(ptr, "%c", &ch) != EOF)
        {
            if (ch == '/')
                flag = 0;

            if (ch != '\n' && flag)
            {
                buffer[i] = ch;
                i++;
            }

            if (ch == '\n')
            {

                root->background_color.red = default_settings.background_color.red;
                root->background_color.green = default_settings.background_color.green;
                root->background_color.blue = default_settings.background_color.blue;

                root->foreground_color.red = default_settings.foreground_color.red;
                root->foreground_color.green = default_settings.foreground_color.green;
                root->foreground_color.blue = default_settings.foreground_color.blue;

                root->grid_color.red = default_settings.grid_color.red;
                root->grid_color.green = default_settings.grid_color.green;
                root->grid_color.blue = default_settings.grid_color.blue;

                root->canvas_size.x = default_settings.canvas_size.x;
                root->canvas_size.y = default_settings.canvas_size.y;

                root->angle_offset.x = default_settings.angle_offset.x;
                root->angle_offset.y = default_settings.angle_offset.y;

                root->show_grid = default_settings.show_grid;

                root->pattern_thickness = default_settings.pattern_thickness;

                root->grid_thickness = default_settings.grid_thickness;

                root->tile_size = default_settings.tile_size;

                root->archetype = NULL;
                root->file_name = NULL;

                root->next = NULL;

                buffer[i] = '\0';

                i = 0;
                flag = 1;
                t = strtok(buffer, ":");
                while (t != NULL)
                {
                    if (strcmp(t, "grid_color") == 0 || strcmp(t, " grid_color") == 0)
                    {
                        t = strtok(NULL, ",");
                        sscanf(t, "(%lf", &(root->grid_color.red));

                        t = strtok(NULL, ",");
                        sscanf(t, "%lf", &(root->grid_color.green));

                        t = strtok(NULL, ",");
                        sscanf(t, "%lf)", &(root->grid_color.blue));
                    }
                    if (strcmp(t, "foreground_color") == 0 || strcmp(t, " foreground_color") == 0)
                    {
                        t = strtok(NULL, ",");
                        sscanf(t, "(%lf", &(root->foreground_color.red));

                        t = strtok(NULL, ",");
                        sscanf(t, "%lf", &(root->foreground_color.green));

                        t = strtok(NULL, ", ");
                        sscanf(t, "%lf)", &(root->foreground_color.blue));
                    }
                    if (strcmp(t, "background_color") == 0 || strcmp(t, " background_color") == 0)
                    {
                        t = strtok(NULL, ",");
                        sscanf(t, "(%lf", &(root->background_color.red));

                        t = strtok(NULL, ",");
                        sscanf(t, "%lf", &(root->background_color.green));

                        t = strtok(NULL, ",");
                        sscanf(t, "%lf)", &(root->background_color.blue));
                    }
                    if (strcmp(t, "pattern_thickness") == 0 || strcmp(t, " pattern_thickness") == 0)
                    {

                        t = strtok(NULL, ",");
                        sscanf(t, "%lf", &(root->pattern_thickness));
                    }
                    if (strcmp(t, "grid_thickness") == 0 || strcmp(t, " grid_thickness") == 0)
                    {

                        t = strtok(NULL, ",");
                        sscanf(t, "%lf", &(root->grid_thickness));
                    }
                    if (strcmp(t, "tile_size") == 0 || strcmp(t, " tile_size") == 0)
                    {

                        t = strtok(NULL, ",");
                        sscanf(t, "%lf", &(root->tile_size));
                    }
                    if (strcmp(t, "canvas_size") == 0 || strcmp(t, " canvas_size") == 0)
                    {

                        t = strtok(NULL, ",");
                        sscanf(t, "(%lf", &(root->canvas_size.x));

                        t = strtok(NULL, ",");
                        sscanf(t, "%lf)", &(root->canvas_size.y));
                    }
                    if (strcmp(t, "angle_offset") == 0 || strcmp(t, " angle_offset") == 0)
                    {

                        t = strtok(NULL, ",");
                        sscanf(t, "(%lf", &(root->angle_offset.x));

                        t = strtok(NULL, ",");
                        sscanf(t, "%lf)", &(root->angle_offset.y));
                    }
                    if (strcmp(t, "show_grid") == 0 || strcmp(t, " show_grid") == 0)
                    {

                        t = strtok(NULL, ",");
                        if (strncmp(t, "True", 4) == 0)
                            root->show_grid = 1;
                        if (strncmp(t, "False", 5) == 0)
                            root->show_grid = 0;
                    }
                    if (strcmp(t, "archetype") == 0 || strcmp(t, " archetype") == 0)
                    {

                        t = strtok(NULL, ",");
                        root->archetype = (char *)malloc(sizeof(char) * 100);
                        strcpy(root->archetype, t);
                        memcpy(root->arche, root->archetype, strlen(root->archetype) + 1);
                    }
                    if (strcmp(t, "file_name") == 0 || strcmp(t, " file_name") == 0)
                    {

                        t = strtok(NULL, ".,");
                        root->file_name = (char *)malloc(sizeof(char) * 100);
                        strcpy(root->file_name, t);
                        memcpy(root->file, root->file_name, strlen(root->file_name) + 1);
                    }

                    t = strtok(NULL, ":");
                }
                if (root->archetype != NULL && root->file_name != NULL)
                {

                    root->background_color.red *= 1.0 / 256.0;
                    root->background_color.green *= 1.0 / 256.0;
                    root->background_color.blue *= 1.0 / 256.0;

                    root->foreground_color.red *= 1.0 / 256.0;
                    root->foreground_color.green *= 1.0 / 256.0;
                    root->foreground_color.blue *= 1.0 / 256.0;

                    root->grid_color.red *= 1.0 / 256.0;
                    root->grid_color.green *= 1.0 / 256.0;
                    root->grid_color.blue *= 1.0 / 256.0;

                    root->next = (Figure *)malloc(sizeof(Figure));
                    root = root->next;
                }

                memset(buffer, 0, 200);
            }
        }

        root->background_color.red = default_settings.background_color.red;
        root->background_color.green = default_settings.background_color.green;
        root->background_color.blue = default_settings.background_color.blue;

        root->foreground_color.red = default_settings.foreground_color.red;
        root->foreground_color.green = default_settings.foreground_color.green;
        root->foreground_color.blue = default_settings.foreground_color.blue;

        root->grid_color.red = default_settings.grid_color.red;
        root->grid_color.green = default_settings.grid_color.green;
        root->grid_color.blue = default_settings.grid_color.blue;

        root->canvas_size.x = default_settings.canvas_size.x;
        root->canvas_size.y = default_settings.canvas_size.y;

        root->angle_offset.x = default_settings.angle_offset.x;
        root->angle_offset.y = default_settings.angle_offset.y;

        root->show_grid = default_settings.show_grid;

        root->pattern_thickness = default_settings.pattern_thickness;

        root->grid_thickness = default_settings.grid_thickness;

        root->tile_size = default_settings.tile_size;

        root->archetype = NULL;
        root->file_name = NULL;

        root->next = NULL;

        buffer[i] = '\0';

        i = 0;
        flag = 1;
        t = strtok(buffer, ":");

        while (t != NULL)
        {
            if (strcmp(t, "grid_color") == 0 || strcmp(t, " grid_color") == 0)
            {
                t = strtok(NULL, ",");
                sscanf(t, "(%lf", &(root->grid_color.red));

                t = strtok(NULL, ",");
                sscanf(t, "%lf", &(root->grid_color.green));

                t = strtok(NULL, ",");
                sscanf(t, "%lf)", &(root->grid_color.blue));
            }
            if (strcmp(t, "foreground_color") == 0 || strcmp(t, " foreground_color") == 0)
            {
                t = strtok(NULL, ",");
                sscanf(t, "(%lf", &(root->foreground_color.red));

                t = strtok(NULL, ",");
                sscanf(t, "%lf", &(root->foreground_color.green));

                t = strtok(NULL, ", ");
                sscanf(t, "%lf)", &(root->foreground_color.blue));
            }
            if (strcmp(t, "background_color") == 0 || strcmp(t, " background_color") == 0)
            {
                t = strtok(NULL, ",");
                sscanf(t, "(%lf", &(root->background_color.red));

                t = strtok(NULL, ",");
                sscanf(t, "%lf", &(root->background_color.green));

                t = strtok(NULL, ",");
                sscanf(t, "%lf)", &(root->background_color.blue));
            }
            if (strcmp(t, "pattern_thickness") == 0 || strcmp(t, " pattern_thickness") == 0)
            {

                t = strtok(NULL, ",");
                sscanf(t, "%lf", &(root->pattern_thickness));
            }
            if (strcmp(t, "grid_thickness") == 0 || strcmp(t, " grid_thickness") == 0)
            {

                t = strtok(NULL, ",");
                sscanf(t, "%lf", &(root->grid_thickness));
            }
            if (strcmp(t, "tile_size") == 0 || strcmp(t, " tile_size") == 0)
            {

                t = strtok(NULL, ",");
                sscanf(t, "%lf", &(root->tile_size));
            }
            if (strcmp(t, "canvas_size") == 0 || strcmp(t, " canvas_size") == 0)
            {

                t = strtok(NULL, ",");
                sscanf(t, "(%lf", &(root->canvas_size.x));

                t = strtok(NULL, ",");
                sscanf(t, "%lf)", &(root->canvas_size.y));
            }
            if (strcmp(t, "angle_offset") == 0 || strcmp(t, " angle_offset") == 0)
            {

                t = strtok(NULL, ",");
                sscanf(t, "(%lf", &(root->angle_offset.x));

                t = strtok(NULL, ",");
                sscanf(t, "%lf)", &(root->angle_offset.y));
            }
            if (strcmp(t, "show_grid") == 0 || strcmp(t, " show_grid") == 0)
            {

                t = strtok(NULL, ",");
                if (strcmp(t, "True") == 0)
                    root->show_grid = 1;
                if (strcmp(t, "False") == 0)
                    root->show_grid = 0;
            }
            if (strcmp(t, "archetype") == 0 || strcmp(t, " archetype") == 0)
            {

                t = strtok(NULL, ",");
                root->archetype = (char *)malloc(sizeof(char) * 100);
                strcpy(root->archetype, t);
                memcpy(root->arche, root->archetype, strlen(root->archetype) + 1);
            }
            if (strcmp(t, "file_name") == 0 || strcmp(t, " file_name") == 0)
            {

                t = strtok(NULL, ".,");
                root->file_name = (char *)malloc(sizeof(char) * 100);
                strcpy(root->file_name, t);
                memcpy(root->file, root->file_name, strlen(root->file_name) + 1);
            }

            t = strtok(NULL, ":");
        }
        if (root->archetype != NULL && root->file_name != NULL)
        {

            root->background_color.red *= 1.0 / 256.0;
            root->background_color.green *= 1.0 / 256.0;
            root->background_color.blue *= 1.0 / 256.0;

            root->foreground_color.red *= 1.0 / 256.0;
            root->foreground_color.green *= 1.0 / 256.0;
            root->foreground_color.blue *= 1.0 / 256.0;

            root->grid_color.red *= 1.0 / 256.0;
            root->grid_color.green *= 1.0 / 256.0;
            root->grid_color.blue *= 1.0 / 256.0;

            root->next = NULL;
        }
    }

    fclose(ptr);
    return head;
}
void set_background_color(Point2D canvas, Color background_color, const char *filename)
{

    FILE *ptr = fopen(filename, "a");

    if (ptr != NULL)
    {
        fprintf(ptr, "newpath\n");
        fprintf(ptr, "%lf %lf moveto\n", 0.0, 0.0);
        fprintf(ptr, "%lf %lf lineto\n", canvas.x, 0.0);
        fprintf(ptr, "%lf %lf lineto\n", canvas.x, canvas.y);
        fprintf(ptr, "%lf %lf lineto\n", 0.0, canvas.y);
        fprintf(ptr, "closepath\n");
        fprintf(ptr, "gsave\n");
        fprintf(ptr, "%lf %lf %lf setrgbcolor\n", background_color.red, background_color.green, background_color.blue);
        fprintf(ptr, "fill\n");
        fprintf(ptr, "grestore\n");
        fprintf(ptr, "stroke\n");
    }

    fclose(ptr);
}
void draw_grid_square(Point2D canvas, Color grid_color, double grid_thickness, double tile_size, const char *filename)
{
    FILE *ptr = fopen(filename, "a");

    Point2D temp;

    temp.x = 0.0;
    temp.y = 0.0;

    if (ptr != NULL)
    {
        while (temp.y <= canvas.y)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", grid_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", grid_color.red, grid_color.green, grid_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", canvas.x, temp.y);
            fprintf(ptr, "stroke\n");
            temp.y += tile_size;
        }

        temp.x = 0.0;
        temp.y = 0.0;

        while (temp.x <= canvas.x)
        {

            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", grid_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", grid_color.red, grid_color.green, grid_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x, canvas.y);
            fprintf(ptr, "stroke\n");
            temp.x += tile_size;
        }
    }

    fclose(ptr);
}

void draw_foreground_square(Point2D canvas, Color foreground_color, double pattern_thickness, double tile_size, Point2D angle_offset, const char *filename)
{
    FILE *ptr = fopen(filename, "a");
    Point2D temp;

    double sinx, cosx;
    double length;
    length = tile_size / 2.0 + angle_offset.y / 2.0;
    sinx = sin(angle_offset.x * PI / 180.0);
    cosx = cos(angle_offset.x * PI / 180.0);
    double hip = pow(length, 2) + pow(length, 2);
    hip = sqrt(hip);
    length = hip / 2.0;
    length = length / sin((angle_offset.x + 45.0) * PI / 180.0);

    if (ptr != NULL)
    {
        temp.x = tile_size / 2.0 - angle_offset.y / 2.0;
        temp.y = 0.0;

        while (temp.y < canvas.y)
        {
            while (temp.x <= canvas.x)
            {

                fprintf(ptr, "newpath\n");
                fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
                fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
                fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
                fprintf(ptr, "%lf %lf lineto\n", (temp.x + (length * cosx)), (temp.y + (length * sinx)));
                fprintf(ptr, "stroke\n");
                temp.x += tile_size;
            }

            temp.x = tile_size / 2.0 - angle_offset.y / 2.0;
            temp.y += tile_size;
        }

        temp.x = tile_size / 2.0 - angle_offset.y / 2.0;
        temp.y = tile_size;

        while (temp.y <= canvas.y)
        {
            while (temp.x <= canvas.x)
            {
                fprintf(ptr, "newpath\n");
                fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
                fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
                fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
                fprintf(ptr, "%lf %lf lineto\n", (temp.x + (length * cosx)), (temp.y - (length * sinx)));
                fprintf(ptr, "stroke\n");
                temp.x += tile_size;
            }

            temp.x = tile_size / 2.0 - angle_offset.y / 2.0;
            temp.y += tile_size;
        }

        temp.x = tile_size / 2.0 + angle_offset.y / 2.0;
        temp.y = 0.0;

        while (temp.y < canvas.y)
        {
            while (temp.x <= canvas.x)
            {

                fprintf(ptr, "newpath\n");
                fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
                fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
                fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
                fprintf(ptr, "%lf %lf lineto\n", (temp.x - (length * cosx)), (temp.y + (length * sinx)));
                fprintf(ptr, "stroke\n");
                temp.x += tile_size;
            }

            temp.x = tile_size / 2.0 + angle_offset.y / 2.0;
            temp.y += tile_size;
        }
        temp.x = tile_size / 2.0 + angle_offset.y / 2.0;
        temp.y = tile_size;

        while (temp.y <= canvas.y)
        {
            while (temp.x <= canvas.x)
            {

                fprintf(ptr, "newpath\n");
                fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
                fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
                fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
                fprintf(ptr, "%lf %lf lineto\n", (temp.x - (length * cosx)), (temp.y - (length * sinx)));
                fprintf(ptr, "stroke\n");
                temp.x += tile_size;
            }

            temp.x = tile_size / 2.0 + angle_offset.y / 2.0;
            temp.y += tile_size;
        }

        temp.x = 0.0;
        temp.y = tile_size / 2.0 + angle_offset.y / 2.0;

        while (temp.x < canvas.x)
        {
            while (temp.y <= canvas.y)
            {

                fprintf(ptr, "newpath\n");
                fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
                fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
                fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
                fprintf(ptr, "%lf %lf lineto\n", (temp.x + (length * sinx)), (temp.y - (length * cosx)));
                fprintf(ptr, "stroke\n");
                temp.y += tile_size;
            }

            temp.y = tile_size / 2.0 + angle_offset.y / 2.0;
            temp.x += tile_size;
        }
        temp.x = 0.0;
        temp.y = tile_size / 2.0 + angle_offset.y / 2.0;

        while (temp.x <= canvas.x)
        {
            while (temp.y <= canvas.y)
            {

                fprintf(ptr, "newpath\n");
                fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
                fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
                fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
                fprintf(ptr, "%lf %lf lineto\n", (temp.x - (length * sinx)), (temp.y - (length * cosx)));
                fprintf(ptr, "stroke\n");
                temp.y += tile_size;
            }

            temp.y = tile_size / 2.0 + angle_offset.y / 2.0;
            temp.x += tile_size;
        }

        temp.x = 0.0;
        temp.y = tile_size / 2.0 - angle_offset.y / 2.0;

        while (temp.x < canvas.x)
        {
            while (temp.y <= canvas.y)
            {

                fprintf(ptr, "newpath\n");
                fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
                fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
                fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
                fprintf(ptr, "%lf %lf lineto\n", (temp.x + (length * sinx)), (temp.y + (length * cosx)));
                fprintf(ptr, "stroke\n");
                temp.y += tile_size;
            }

            temp.y = tile_size / 2.0 - angle_offset.y / 2.0;
            temp.x += tile_size;
        }

        temp.x = tile_size;
        temp.y = tile_size / 2.0 - angle_offset.y / 2.0;

        while (temp.x <= canvas.x)
        {
            while (temp.y <= canvas.y)
            {

                fprintf(ptr, "newpath\n");
                fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
                fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
                fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
                fprintf(ptr, "%lf %lf lineto\n", (temp.x - (length * sinx)), (temp.y + (length * cosx)));
                fprintf(ptr, "stroke\n");
                temp.y += tile_size;
            }

            temp.y = tile_size / 2.0 - angle_offset.y / 2.0;
            temp.x += tile_size;
        }
    }
    fclose(ptr);
}

void draw_grid_hexagon(Point2D canvas, Color grid_color, double grid_thickness, double tile_size, const char *filename)
{

    FILE *ptr = fopen(filename, "a");
    Point2D temp;
    Point2D initial;
    initial.x = tile_size * sqrt(3) / 2.0;
    initial.y = 0.0;
    int counter = 0;
    
    if (ptr != NULL)
    {
        while (initial.y < canvas.y)
        {
            temp.x = initial.x;
            temp.y = initial.y;

            while (temp.x < canvas.x)
            {
                fprintf(ptr, "newpath\n");
                fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
                fprintf(ptr, "%lf setlinewidth\n", grid_thickness);
                fprintf(ptr, "%lf %lf %lf setrgbcolor\n", grid_color.red, grid_color.green, grid_color.blue);
                fprintf(ptr, "%lf %lf lineto\n", temp.x, temp.y - tile_size);
                fprintf(ptr, "stroke\n");

                temp.x += tile_size * sqrt(3);
            }
            temp.x = initial.x;
            temp.y = initial.y;
            
            while (temp.x < canvas.x)
            {
                fprintf(ptr, "newpath\n");
                fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
                fprintf(ptr, "%lf setlinewidth\n", grid_thickness);
                fprintf(ptr, "%lf %lf %lf setrgbcolor\n", grid_color.red, grid_color.green, grid_color.blue);
                fprintf(ptr, "%lf %lf lineto\n", temp.x + (tile_size * sqrt(3) / 2.0), temp.y + (tile_size * 1.0 / 2.0));
                fprintf(ptr, "stroke\n");

                temp.x += tile_size * sqrt(3);
            }

            temp.x = initial.x;
            temp.y = initial.y;
            
            while (temp.x < canvas.x)
            {
                fprintf(ptr, "newpath\n");
                fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
                fprintf(ptr, "%lf setlinewidth\n", grid_thickness);
                fprintf(ptr, "%lf %lf %lf setrgbcolor\n", grid_color.red, grid_color.green, grid_color.blue);
                fprintf(ptr, "%lf %lf lineto\n", temp.x - (tile_size * sqrt(3) / 2.0), temp.y + (tile_size * 1.0 / 2.0));
                fprintf(ptr, "stroke\n");

                temp.x += tile_size * sqrt(3);
            }

            ++counter;
            
            if (counter == 1)
                initial.x = 0.0;
            
            if (counter == 2)
            {
                initial.x = tile_size * sqrt(3) / 2.0;
                counter = 0;
            }

            initial.y += tile_size + tile_size / 2.0;
        }
    }

    fclose(ptr);
}
void draw_foreground_hexagon(Point2D canvas, Color foreground_color, double pattern_thickness, double tile_size, Point2D angle_offset, const char *filename)
{
    FILE *ptr = fopen(filename, "a");
    Point2D temp;
    double sinx, cosx;
    double length;
    length = tile_size / 2.0 + angle_offset.y / 2.0;

    length /= 2.0;
    length *= sqrt(3);
    length = length / sin((angle_offset.x + 60.0) * PI / 180.0);

    temp.x = tile_size / 2.0 * sqrt(3) - ((tile_size + angle_offset.y) / 4.0 * sqrt(3));
    temp.y = (tile_size / 4.0 + angle_offset.y / 4.0);

    sinx = sin((angle_offset.x - 30.0) * PI / 180.0);
    cosx = cos((angle_offset.x - 30.0) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x + (length * cosx), temp.y + (length * sinx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = tile_size / 2.0 * sqrt(3) - ((tile_size + angle_offset.y) / 4.0 * sqrt(3));
        temp.y += 3 * tile_size;
    }

    temp.x = tile_size / 2.0 * sqrt(3) - ((tile_size + angle_offset.y) / 4.0 * sqrt(3));
    temp.y = (tile_size / 4.0 + angle_offset.y / 4.0);
    sinx = sin((angle_offset.x - 60.0) * PI / 180.0);
    cosx = cos((angle_offset.x - 60.0) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x - (length * sinx), temp.y - (length * cosx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = tile_size / 2.0 * sqrt(3) - ((tile_size + angle_offset.y) / 4.0 * sqrt(3));
        temp.y += 3 * tile_size;
    }

    temp.x = tile_size / 2.0 * sqrt(3) - ((tile_size - angle_offset.y) / 4.0 * sqrt(3));
    temp.y = (tile_size / 4.0 - angle_offset.y / 4.0);
    sinx = sin((60.0 - angle_offset.x) * PI / 180.0);
    cosx = cos((60.0 - angle_offset.x) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x - (length * sinx), temp.y + (length * cosx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = tile_size / 2.0 * sqrt(3) - ((tile_size - angle_offset.y) / 4.0 * sqrt(3));
        temp.y += 3 * tile_size;
    }

    temp.x = tile_size / 2.0 * sqrt(3) - ((tile_size - angle_offset.y) / 4.0 * sqrt(3));
    temp.y = (tile_size / 4.0 - angle_offset.y / 4.0);
    sinx = sin((angle_offset.x - 30.0) * PI / 180.0);
    cosx = cos((angle_offset.x - 30.0) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x - (length * cosx), temp.y - (length * sinx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = tile_size / 2.0 * sqrt(3) - ((tile_size - angle_offset.y) / 4.0 * sqrt(3));
        temp.y += 3 * tile_size;
    }

    temp.x = 0.0;
    temp.y = tile_size + (angle_offset.y / 2.0);
    sinx = sin((angle_offset.x) * PI / 180.0);
    cosx = cos((angle_offset.x) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x + (length * sinx), temp.y - (length * cosx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = 0.0;
        temp.y += 3 * tile_size;
    }

    temp.x = 0.0;
    temp.y = tile_size + (angle_offset.y / 2.0);
    sinx = sin((angle_offset.x) * PI / 180.0);
    cosx = cos((angle_offset.x) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x - (length * sinx), temp.y - (length * cosx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = 0.0;
        temp.y += 3 * tile_size;
    }

    temp.x = 0.0;
    temp.y = tile_size - (angle_offset.y / 2.0);
    sinx = sin((angle_offset.x) * PI / 180.0);
    cosx = cos((angle_offset.x) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x + (length * sinx), temp.y + (length * cosx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = 0.0;
        temp.y += 3 * tile_size;
    }

    temp.x = 0.0;
    temp.y = tile_size - (angle_offset.y / 2.0);
    sinx = sin((angle_offset.x) * PI / 180.0);
    cosx = cos((angle_offset.x) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x - (length * sinx), temp.y + (length * cosx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }
        temp.x = 0.0;
        temp.y += 3 * tile_size;
    }

    temp.x = tile_size / 2.0 * sqrt(3);
    temp.y = 2 * tile_size + (tile_size + angle_offset.y) / 2.0;
    sinx = sin((angle_offset.x) * PI / 180.0);
    cosx = cos((angle_offset.x) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x + (length * sinx), temp.y - (length * cosx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }
        temp.x = tile_size / 2.0 * sqrt(3);
        temp.y += 3 * tile_size;
    }

    temp.x = tile_size / 2.0 * sqrt(3);
    temp.y = 2 * tile_size + (tile_size + angle_offset.y) / 2.0;
    sinx = sin((angle_offset.x) * PI / 180.0);
    cosx = cos((angle_offset.x) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x - (length * sinx), temp.y - (length * cosx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = tile_size / 2.0 * sqrt(3);
        temp.y += 3 * tile_size;
    }

    temp.x = tile_size / 2.0 * sqrt(3);
    temp.y = 2 * tile_size + (tile_size - angle_offset.y) / 2.0;
    sinx = sin((angle_offset.x) * PI / 180.0);
    cosx = cos((angle_offset.x) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x + (length * sinx), temp.y + (length * cosx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = tile_size / 2.0 * sqrt(3);
        temp.y += 3 * tile_size;
    }

    temp.x = tile_size / 2.0 * sqrt(3);
    temp.y = 2 * tile_size + (tile_size - angle_offset.y) / 2.0;
    sinx = sin((angle_offset.x) * PI / 180.0);
    cosx = cos((angle_offset.x) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x - (length * sinx), temp.y + (length * cosx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = tile_size / 2.0 * sqrt(3);
        temp.y += 3 * tile_size;
    }

    temp.x = (tile_size / 2.0 * sqrt(3)) + (tile_size + angle_offset.y) / 4.0 * sqrt(3);
    temp.y = (tile_size + angle_offset.y) / 4.0;

    sinx = sin((angle_offset.x - 30.0) * PI / 180.0);
    cosx = cos((angle_offset.x - 30.0) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x - (length * cosx), temp.y + (length * sinx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = (tile_size / 2.0 * sqrt(3)) + (tile_size + angle_offset.y) / 4.0 * sqrt(3);
        temp.y += 3 * tile_size;
    }

    temp.x = (tile_size / 2.0 * sqrt(3)) + (tile_size + angle_offset.y) / 4.0 * sqrt(3);
    temp.y = (tile_size + angle_offset.y) / 4.0;

    sinx = sin((angle_offset.x - 60.0) * PI / 180.0);
    cosx = cos((angle_offset.x - 60.0) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x + (length * sinx), temp.y - (length * cosx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = (tile_size / 2.0 * sqrt(3)) + (tile_size + angle_offset.y) / 4.0 * sqrt(3);
        temp.y += 3 * tile_size;
    }

    temp.x = (tile_size / 2.0 * sqrt(3)) + (tile_size - angle_offset.y) / 4.0 * sqrt(3);
    temp.y = (tile_size - angle_offset.y) / 4.0;

    sinx = sin((60.0 - angle_offset.x) * PI / 180.0);
    cosx = cos((60.0 - angle_offset.x) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x + (length * sinx), temp.y + (length * cosx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }
        temp.x = (tile_size / 2.0 * sqrt(3)) + (tile_size - angle_offset.y) / 4.0 * sqrt(3);
        temp.y += 3 * tile_size;
    }

    temp.x = (tile_size / 2.0 * sqrt(3)) + (tile_size - angle_offset.y) / 4.0 * sqrt(3);
    temp.y = (tile_size - angle_offset.y) / 4.0;

    sinx = sin((30.0 - angle_offset.x) * PI / 180.0);
    cosx = cos((30.0 - angle_offset.x) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x + (length * cosx), temp.y + (length * sinx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = (tile_size / 2.0 * sqrt(3)) + (tile_size - angle_offset.y) / 4.0 * sqrt(3);
        temp.y += 3 * tile_size;
    }

    temp.x = tile_size / 2.0 * sqrt(3) - ((tile_size + angle_offset.y) / 4.0 * sqrt(3));
    temp.y = (tile_size / 4.0 + angle_offset.y / 4.0) + (3 * tile_size - angle_offset.y) / 2.0;

    sinx = sin((30.0 - angle_offset.x) * PI / 180.0);
    cosx = cos((30.0 - angle_offset.x) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x + (length * cosx), temp.y + (length * sinx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = tile_size / 2.0 * sqrt(3) - ((tile_size + angle_offset.y) / 4.0 * sqrt(3));
        temp.y += 3 * tile_size;
    }

    temp.x = tile_size / 2.0 * sqrt(3) - ((tile_size + angle_offset.y) / 4.0 * sqrt(3));
    temp.y = (tile_size / 4.0 + angle_offset.y / 4.0) + (3 * tile_size - angle_offset.y) / 2.0;

    sinx = sin((60 - angle_offset.x) * PI / 180.0);
    cosx = cos((60 - angle_offset.x) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x + (length * sinx), temp.y + (length * cosx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = tile_size / 2.0 * sqrt(3) - ((tile_size + angle_offset.y) / 4.0 * sqrt(3));
        temp.y += 3 * tile_size;
    }

    temp.x = tile_size / 2.0 * sqrt(3) - ((tile_size - angle_offset.y) / 4.0 * sqrt(3));
    temp.y = (tile_size / 4.0 - angle_offset.y / 4.0) + (3 * tile_size + angle_offset.y) / 2.0;

    sinx = sin((60 - angle_offset.x) * PI / 180.0);
    cosx = cos((60 - angle_offset.x) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x - (length * sinx), temp.y - (length * cosx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = tile_size / 2.0 * sqrt(3) - ((tile_size - angle_offset.y) / 4.0 * sqrt(3));
        temp.y += 3 * tile_size;
    }

    temp.x = tile_size / 2.0 * sqrt(3) - ((tile_size - angle_offset.y) / 4.0 * sqrt(3));
    temp.y = (tile_size / 4.0 - angle_offset.y / 4.0) + (3 * tile_size + angle_offset.y) / 2.0;

    sinx = sin((30 - angle_offset.x) * PI / 180.0);
    cosx = cos((30 - angle_offset.x) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x - (length * cosx), temp.y - (length * sinx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = tile_size / 2.0 * sqrt(3) - ((tile_size - angle_offset.y) / 4.0 * sqrt(3));
        temp.y += 3 * tile_size;
    }

    temp.x = tile_size / 2.0 * sqrt(3) + ((tile_size - angle_offset.y) / 4.0 * sqrt(3));
    temp.y = (tile_size / 4.0 - angle_offset.y / 4.0) + (3 * tile_size + angle_offset.y) / 2.0;

    sinx = sin((angle_offset.x - 60.0) * PI / 180.0);
    cosx = cos((angle_offset.x - 60.0) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x - (length * sinx), temp.y - (length * cosx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = tile_size / 2.0 * sqrt(3) + ((tile_size - angle_offset.y) / 4.0 * sqrt(3));
        temp.y += 3 * tile_size;
    }

    temp.x = tile_size / 2.0 * sqrt(3) + ((tile_size - angle_offset.y) / 4.0 * sqrt(3));
    temp.y = (tile_size / 4.0 - angle_offset.y / 4.0) + (3 * tile_size + angle_offset.y) / 2.0;

    sinx = sin((30.0 - angle_offset.x) * PI / 180.0);
    cosx = cos((30.0 - angle_offset.x) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x + (length * cosx), temp.y - (length * sinx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = tile_size / 2.0 * sqrt(3) + ((tile_size - angle_offset.y) / 4.0 * sqrt(3));
        temp.y += 3 * tile_size;
    }

    temp.x = tile_size / 2.0 * sqrt(3) + ((tile_size + angle_offset.y) / 4.0 * sqrt(3));
    temp.y = (tile_size / 4.0 + angle_offset.y / 4.0) + (3 * tile_size - angle_offset.y) / 2.0;

    sinx = sin((angle_offset.x - 30.0) * PI / 180.0);
    cosx = cos((angle_offset.x - 30.0) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x - (length * cosx), temp.y - (length * sinx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = tile_size / 2.0 * sqrt(3) + ((tile_size + angle_offset.y) / 4.0 * sqrt(3));
        temp.y += 3 * tile_size;
    }

    temp.x = tile_size / 2.0 * sqrt(3) + ((tile_size + angle_offset.y) / 4.0 * sqrt(3));
    temp.y = (tile_size / 4.0 + angle_offset.y / 4.0) + (3 * tile_size - angle_offset.y) / 2.0;

    sinx = sin((60.0 - angle_offset.x) * PI / 180.0);
    cosx = cos((60.0 - angle_offset.x) * PI / 180.0);

    while (temp.y < canvas.y)
    {
        while (temp.x < canvas.x)
        {
            fprintf(ptr, "newpath\n");
            fprintf(ptr, "%lf %lf moveto\n", temp.x, temp.y);
            fprintf(ptr, "%lf setlinewidth\n", pattern_thickness);
            fprintf(ptr, "%lf %lf %lf setrgbcolor\n", foreground_color.red, foreground_color.green, foreground_color.blue);
            fprintf(ptr, "%lf %lf lineto\n", temp.x - (length * sinx), temp.y + (length * cosx));
            fprintf(ptr, "stroke\n");
            temp.x += tile_size * sqrt(3);
        }

        temp.x = tile_size / 2.0 * sqrt(3) + ((tile_size + angle_offset.y) / 4.0 * sqrt(3));
        temp.y += 3 * tile_size;
    }

    fclose(ptr);
}

void export_eps(Figure *temp)
{
    while (temp != NULL)
    {
        strcat(temp->file, ".eps");

        set_background_color(temp->canvas_size, temp->background_color, temp->file);

        if (strncmp(temp->arche, "Square", 6) == 0)
        {
            if (temp->show_grid)
                draw_grid_square(temp->canvas_size, temp->grid_color, temp->grid_thickness, temp->tile_size, temp->file);

            draw_foreground_square(temp->canvas_size, temp->foreground_color, temp->pattern_thickness, temp->tile_size, temp->angle_offset, temp->file);
        }

        if (strncmp(temp->arche, "Hexagon", 7) == 0)
        {
            if (temp->show_grid)
                draw_grid_hexagon(temp->canvas_size, temp->grid_color, temp->grid_thickness, temp->tile_size, temp->file);
            
            draw_foreground_hexagon(temp->canvas_size, temp->foreground_color, temp->pattern_thickness, temp->tile_size, temp->angle_offset, temp->file);
        }
        
        temp = temp->next;
    }
}