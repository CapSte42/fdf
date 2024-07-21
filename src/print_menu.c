/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:30:13 by smontuor          #+#    #+#             */
/*   Updated: 2024/07/21 08:37:37 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_map_info(t_fdf *fdf)
{
	char	*to_write;

	to_write = NULL;
	to_write = "<<< ---- MAP INFO ---- >>>";
	mlx_string_put(fdf->mlx, fdf->mlx_win, 10, 90, -1, to_write);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 120, 0xFFFFFF, "Size       :");
	to_write = ft_itoa(fdf->index);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 110, 120, 0xff8c00, to_write);
	free(to_write);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 140, 0xFFFFFF, "Xmax       :");
	to_write = ft_itoa(fdf->x_axis);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 110, 140, 0xff8c00, to_write);
	free(to_write);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 160, 0xFFFFFF, "Ymax       :");
	to_write = ft_itoa(fdf->y_axis);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 110, 160, 0xff8c00, to_write);
	free(to_write);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 180, 0xFFFFFF, "Zmax       :");
	to_write = ft_itoa(fdf->z_max);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 110, 180, 0xff8c00, to_write);
	free(to_write);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 200, 0xFFFFFF, "Zmin       :");
	to_write = ft_itoa(fdf->z_min);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 110, 200, 0xff8c00, to_write);
	free(to_write);
}

// added after evaluation the value speed
static void	put_draw_info(t_fdf *fdf)
{
	char	*to_write;

	to_write = "<<< ---- DRAW INFO ---- >>>";
	mlx_string_put(fdf->mlx, fdf->mlx_win, 10, 230, -1, to_write);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 260, 0xFFFFFF, "Z modifier :");
	to_write = ft_itoa(fdf->z_mod);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 110, 260, 0xff8c00, to_write);
	free(to_write);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 280, 0xFFFFFF, "POV (x,y,z):");
	to_write = ft_itoa(fdf->rot_x * 10);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 110, 280, 0xff8c00, to_write);
	free(to_write);
	to_write = ft_itoa(fdf->rot_y * 10);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 140, 280, 0xff8c00, to_write);
	free(to_write);
	to_write = ft_itoa(fdf->rot_z * 10);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 170, 280, 0xff8c00, to_write);
	free(to_write);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 300, 0xFFFFFF, "ZoOoOoOoOm :");
	to_write = ft_itoa(fdf->zoom.scaling);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 110, 300, 0xff8c00, to_write);
	free(to_write);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 320, 0xFFFFFF, "Speed      :");
	to_write = ft_itoa(fdf->acceleration * 10);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 190, 320, 0xff8c00, to_write);
	free(to_write);
}

static void	put_controls_1(t_fdf *fdf)
{
	char	*to_write;

	to_write = "<<< ---- CONTROLS ---- >>>";
	mlx_string_put(fdf->mlx, fdf->mlx_win, 10, 610, -1, to_write);
	to_write = "ESC : QUIT :(";
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 900, 0xdc143c, to_write);
	to_write = "(but you can always come back!)";
	mlx_string_put(fdf->mlx, fdf->mlx_win, 10, 910, 0xdc143c,
		to_write);
}

static void	put_controls_2(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 640, 0xffd700,
		"Left Click : Move");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 660, 0xffd700,
		"Scroll     : Zoom In/Out");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 680, 0xffd700,
		"Left/Right : Rotate Y axis");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 700, 0xffd700,
		"Up/Down    : Rotate X axis");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 740, 0xffd700,
		"+/-        : Change Height");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 760, 0xffd700,
		"R          : Reset Height");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 780, 0xffd700,
		"Right Click: Change projection");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 720, 0xffd700,
		"a/d        : Rotate Z axis");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 800, 0xffd700,
		"Space      : Reset");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 820, 0xffd700,
		"H          : Hide/Show Menu");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 840, 0xffd700,
		"Q/W        : Change Speed");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 860, 0xffd700,
		"1/2/3      : Change Colors");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 880, 0xffd700,
		"4          : Reset Colors");
}

void	write_menu(t_fdf *fdf)
{
	put_map_info(fdf);
	put_draw_info(fdf);
	put_controls_1(fdf);
	put_controls_2(fdf);
}
