#ifndef lib
#define lib

typedef struct {
    double x, y;
} Point2D;

typedef struct {
    double red, blue, green;
} Color;

typedef struct figure {
    Color background_color, foreground_color, grid_color;
    Point2D canvas_size;
    Point2D angle_offset;
    int show_grid;
    double pattern_thickness, grid_thickness, tile_size;
    char *archetype, *file_name;
    char file[20];
    char arche[20];
    struct figure *next;

} Figure;

Figure *read_commands_defaults(const char *command, const char *defaults);
void set_background_color(Point2D canvas, Color background_color, const char *filename);
void draw_grid_square(Point2D canvas, Color grid_color, double grid_thickness, double tile_size, const char *filename);
void draw_foreground_square(Point2D canvas, Color foreground_color, double pattern_thickness, double tile_size, Point2D angle_offset, const char *filename);
void draw_grid_hexagon(Point2D canvas, Color grid_color, double grid_thickness, double tile_size, const char *filename);
void draw_foreground_hexagon(Point2D canvas, Color foreground_color, double pattern_thickness, double tile_size, Point2D angle_offset, const char *filename);
void export_eps(Figure *head);

#endif