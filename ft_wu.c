#include "fdf.h"

// void my_mlx_pixel_put(t_data *data, int x, int y, int color);

// void plot(t_data *data, int x, int y, unsigned long color) {
//     my_mlx_pixel_put(data, x, y, color);
// }

void	plot(t_data *data, int x, int y, float c)
{
	int color;

	color = (int)(c * 255);
	color = (color << 16) | (color << 8) | color;
	my_mlx_pixel_put(data, x, y, color);
}

int	ipart(float x)
{
	return (floor(x));
}

float ft_round(float x)
{
	return (ipart(x + 0.5f));
}

float	fpart(float x)
{
	return (x - floor(x));
}

float	rfpart(float x)
{
	return (1 - fpart(x));
}

void	swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void	initializeSteepAndSwap(t_wu *wu)
{
	wu->steep = abs(wu->y1 - wu->y0) > abs(wu->x1 - wu->x0);
	if (wu->steep)
	{
		swap(&wu->x0, &wu->y0);
		swap(&wu->x1, &wu->y1);
	}
	if (wu->x0 > wu->x1)
	{
		swap(&wu->x0, &wu->x1);
		swap(&wu->y0, &wu->y1);
	}
}

void	calculateGradientAndDifferences(t_wu *wu)
{
	wu->dx = wu->x1 - wu->x0;
	wu->dy = wu->y1 - wu->y0;
	wu->gradient = wu->dx == 0 ? 1.0 : wu->dy / wu->dx;
}

void	plotEndpoints(t_data *data, t_wu *wu)
{
	if (wu->steep)
	{
		plot(data, wu->ypxl1, wu->xpxl1, rfpart(wu->yend) * wu->xgap);
		plot(data, wu->ypxl1 + 1, wu->xpxl1, fpart(wu->yend) * wu->xgap);
	} else
	{
		plot(data, wu->xpxl1, wu->ypxl1, rfpart(wu->yend) * wu->xgap);
		plot(data, wu->xpxl1, wu->ypxl1 + 1, fpart(wu->yend) * wu->xgap);
	}
	wu->intery = wu->yend + wu->gradient;
}

void	drawFinalEndpoints(t_data *data, t_wu *wu)
{
	wu->xend = ft_round(wu->x1);
	wu->yend = wu->y1 + wu->gradient * (wu->xend - wu->x1);
	wu->xgap = rfpart(wu->x1 + 0.5);
	wu->xpxl2 = wu->xend;
	wu->ypxl2 = ipart(wu->yend);
	if (wu->steep)
	{
		plot(data, wu->ypxl2, wu->xpxl2, rfpart(wu->yend) * wu->xgap);
		plot(data, wu->ypxl2 + 1, wu->xpxl2, fpart(wu->yend) * wu->xgap);
	} else
	{
		plot(data, wu->xpxl2, wu->ypxl2, rfpart(wu->yend) * wu->xgap);
		plot(data, wu->xpxl2, wu->ypxl2 + 1, fpart(wu->yend) * wu->xgap);
	}
}

void	drawMainLine(t_data *data, t_wu *wu)
{
	int x;

	x = wu->xpxl1 + 1;
	while (x < wu->xpxl2)
	{
		if (wu->steep)
		{
			plot(data, wu->ypxl1, x, rfpart(wu->intery));
			plot(data, wu->ypxl1 + 1, x, fpart(wu->intery));
		} else
		{
			plot(data, x, wu->ypxl1, rfpart(wu->intery));
			plot(data, x, wu->ypxl1 + 1, fpart(wu->intery));
		}
		wu->intery += wu->gradient;
		x++;
	}
}

void	drawLine(t_data *data, t_wu *wu)
{
	initializeSteepAndSwap(wu);
	calculateGradientAndDifferences(wu);

	// First endpoint setup
	wu->xend = ft_round(wu->x0);
	wu->yend = wu->y0 + wu->gradient * (wu->xend - wu->x0);
	wu->xgap = rfpart(wu->x0 + 0.5);
	wu->xpxl1 = wu->xend;
	wu->ypxl1 = ipart(wu->yend);
	plotEndpoints(data, wu);

	// Second endpoint setup
	drawFinalEndpoints(data, wu);

	// Main line drawing
	drawMainLine(data, wu);
}
