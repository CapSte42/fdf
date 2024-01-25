#include "minilibx_linux/mlx.h"
#include "minilibx_linux/mlx_int.h"
#include "stdio.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	color = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	for(int x = 5; x <= 495; x++)
		for(int y = 5; y <= 495; y++) {
			/* if (x == 5 || x == 495 || y == 5 || y == 495 || x == y || x + y == 500) */
				my_mlx_pixel_put(&img, x, y, color);
				printf("\n%X", color++);}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	sleep(2);
	while(1)
	{
	for(int x = 5; x <= 495; x++)
		for(int y = 5; y <= 495; y++) {
			/* if (x == 5 || x == 495 || y == 5 || y == 495 || x == y || x + y == 500) */
				my_mlx_pixel_put(&img, x, y, color);
				printf("\n%X", color++);
				color += 1;}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	}
	mlx_loop(mlx);
}