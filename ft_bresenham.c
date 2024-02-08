#include "fdf.h" // Assicurati che questo header includa le definizioni di t_data, t_coords, e my_mlx_pixel_put

static int calculate_step(int start, int end) {
    return (start < end) ? 1 : -1;
}

static void draw_line(t_data *data, int x, int y, int x1, int y1, int color)
{
    int dx, sx;
    int dy, sy;
    int err, e2;
    int steep = abs(y1 - y) > abs(x1 - x);

    if (steep) {
        // Swap x and y
        int temp = x;
        x = y;
        y = temp;

        temp = x1;
        x1 = y1;
        y1 = temp;
    }

    dx = abs(x1 - x);
    sx = (x < x1) ? 1 : -1;

    dy = -abs(y1 - y);
    sy = (y < y1) ? 1 : -1;

    err = dx + dy;

    while (1)
    {
        if (steep) {
            my_mlx_pixel_put(data, y, x, color); // If steep, put pixel at (y, x) instead of (x, y)
        } else {
            my_mlx_pixel_put(data, x, y, color);
        }

        if (x == x1 && y == y1)
            break;

        e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            x += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y += sy;
        }
    }
}

void bresenham(t_data *data, t_coords *start, t_coords *end)
{
    int delta_x = abs(end->x - start->x);
    int delta_y = abs(end->y - start->y);
    int color = start->color; // Usa il colore del punto di partenza o definisci come preferisci

    if (delta_x >= delta_y) {
        draw_line(data, start->x, start->y, end->x, end->y, color);
    } else {
        // Se delta_y è maggiore di delta_x, scambiamo le coordinate x e y per adattarci
        draw_line(data, start->y, start->x, end->y, end->x, color);
    }
}