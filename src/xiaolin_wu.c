/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin_wu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:09:36 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/26 18:11:40 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* WORK IN PROGRESS */

/* #include "fdf.h"
#include <stdbool.h>

unsigned int blend(unsigned int fg, unsigned int bg, double opacity) {
    if (opacity >= 1.0f) return fg;
    if (opacity <= 0.0f) return bg;

    unsigned int fg_r = (fg >> 16) & 0xFF;
    unsigned int fg_g = (fg >> 8) & 0xFF;
    unsigned int fg_b = fg & 0xFF;

    unsigned int bg_r = (bg >> 16) & 0xFF;
    unsigned int bg_g = (bg >> 8) & 0xFF;
    unsigned int bg_b = bg & 0xFF;

    unsigned int r = (unsigned int)(fg_r * opacity + bg_r * (1 - opacity));
    unsigned int g = (unsigned int)(fg_g * opacity + bg_g * (1 - opacity));
    unsigned int b = (unsigned int)(fg_b * opacity + bg_b * (1 - opacity));

    return (r << 16) | (g << 8) | b;
}

void my_mlx_pixel_put_opacity
TOUP(t_data *data, int x, int y, unsigned int color, double opacity) {
    if (x >= 0 && x < DEFAULT_WIDTH && y >= 0 && y < DEFAULT_HEIGHT) {
        char *dst = data->addr +
		TOUP(y * data->line_length + x * (data->bits_per_pixel / 8));
        unsigned int bg_color =
		TOUP*(unsigned int*)dst; // Recupera il colore di sfondo
        unsigned int blended_color =
		TOUPblend(color, bg_color, opacity); // Miscela i colori
        *(unsigned int*)dst = blended_color; // Imposta il colore miscelato
    }
}

static double fpart(double x) {
    return x - floor(x);
}

static double rfpart(double x) {
    return 1 - fpart(x);
}

static void plot(t_data *img, int x, int y,
TOUPdouble brightness, unsigned long int color) {
    // Assumendo che my_mlx_pixel_put_opacity
	TOUPsia simile a my_mlx_pixel_put ma accetta un'intensità
    int opacity = (int)(brightness * 255);
	unsigned int colorInt = (unsigned int)color;
    unsigned long int col = (opacity << 24) |
	TOUP(color & 0xFFFFFF); // Aggiungi l'intensità al colore
	(void)col;
    my_mlx_pixel_put_opacity(img, x, y, colorInt, brightness);
}

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void drawLine(t_fdf *fdf, t_coords start, t_coords end) {
    t_draw draw;
    set_draw(&draw, start, end); //
	TOUPImposta i parametri iniziali come nel tuo codice

    // Swap start and end points if necessary and store swap state
    bool steep = abs(draw.y1 - draw.y0) > abs(draw.x1 - draw.x0);
    if (steep) {
        swap(&draw.x0, &draw.y0);
        swap(&draw.x1, &draw.y1);
    }
    if (draw.x0 > draw.x1) {
        swap(&draw.x0, &draw.x1);
        swap(&draw.y0, &draw.y1);
    }

    double dx = draw.x1 - draw.x0;
    double dy = draw.y1 - draw.y0;
    double gradient = dy / dx;
    if (dx == 0.0) {
        gradient = 1;
    }

    int xend = round(draw.x0);
    double yend = draw.y0 + gradient * (xend - draw.x0);
    double xgap = rfpart(draw.x0 + 0.5);
    int xpxl1 = xend; // this will be used in the main loop
    int ypxl1 = floor(yend);
    if (steep) {
        plot(&fdf->img, ypxl1,   xpxl1, rfpart(yend) * xgap, draw.start_color);
        plot(&fdf->img, ypxl1+1, xpxl1,  fpart(yend) * xgap, draw.start_color);
    } else {
        plot(&fdf->img, xpxl1, ypxl1  , rfpart(yend) * xgap, draw.start_color);
        plot(&fdf->img, xpxl1, ypxl1+1,  fpart(yend) * xgap, draw.start_color);
    }
    double intery = yend + gradient; // first y-intersection for the main loop

    // Handle the end of the line as well
    xend = round(draw.x1);
    yend = draw.y1 + gradient * (xend - draw.x1);
    xgap = fpart(draw.x1 + 0.5);
    int xpxl2 = xend; // this will be used in the main loop
    int ypxl2 = floor(yend);
    if (steep) {
        plot(&fdf->img, ypxl2  , xpxl2, rfpart(yend) * xgap, draw.end_color);
        plot(&fdf->img, ypxl2+1, xpxl2,  fpart(yend) * xgap, draw.end_color);
    } else {
        plot(&fdf->img, xpxl2, ypxl2, rfpart(yend) * xgap, draw.end_color);
        plot(&fdf->img, xpxl2, ypxl2+1, fpart(yend) * xgap, draw.end_color);
    }

    // Main loop
    if (steep) {
        for (int x = xpxl1 + 1; x < xpxl2; x++) {
            plot(&fdf->img,
			TOUPfloor(intery)  , x, rfpart(intery), draw.current_color);
            plot(&fdf->img,
			TOUPfloor(intery)+1, x,  fpart(intery), draw.current_color);
            intery = intery + gradient;
        }
    } else {
        for (int x = xpxl1 + 1; x < xpxl2; x++) {
            plot(&fdf->img, x,
			TOUPfloor(intery), rfpart(intery), draw.current_color);
            plot(&fdf->img, x,
			TOUPfloor(intery)+1, fpart(intery), draw.current_color);
            intery = intery + gradient;
        }
    }
}
 */