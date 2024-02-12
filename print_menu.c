/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:30:13 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/12 18:16:41 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_map_info(t_fdf *fdf)
{
	char	*to_write;

	to_write = "<<< --- MAP INFO --- >>>";
	mlx_string_put(fdf->mlx, fdf->mlx_win, x_pos(to_write), 90, -1, to_write);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 120, 0xFFFFFF, "Size       :");
	to_write = ft_itoa(fdf->index);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 95, 120, 0xff8c00, to_write);
	free(to_write);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 140, 0xFFFFFF, "Xmax       :");
	to_write = ft_itoa(fdf->x_axis);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 95, 140, 0xff8c00, to_write);
	free(to_write);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 160, 0xFFFFFF, "Ymax       :");
	to_write = ft_itoa(fdf->y_axis);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 95, 160, 0xff8c00, to_write);
	free(to_write);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 180, 0xFFFFFF, "Zmax       :");
	to_write = ft_itoa(fdf->z_max);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 95, 180, 0xff8c00, to_write);
	free(to_write);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 200, 0xFFFFFF, "Zmin       :");
	to_write = ft_itoa(fdf->z_min);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 95, 200, 0xff8c00, to_write);
	free(to_write);
}

static void	put_draw_info(t_fdf *fdf)
{
	char	*to_write;

	to_write = "<<< --- DRAW INFO --- >>>";
	mlx_string_put(fdf->mlx, fdf->mlx_win, x_pos(to_write), 230, -1, to_write);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 260, 0xFFFFFF, "Z modifier :");
	to_write = ft_itoa(fdf->z_mod);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 95, 260, 0xff8c00, to_write);
	free(to_write);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 280, 0xFFFFFF, "Angle view :");
	to_write = ft_itoa(fdf->zoom.angle);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 95, 280, 0xff8c00, to_write);
	free(to_write);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 300, 0xFFFFFF, "ZoOoOoOoOm :");
	to_write = ft_itoa(fdf->zoom.scaling);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 95, 300, 0xff8c00, to_write);
	free(to_write);
}

static void	put_controls_1(t_fdf *fdf)
{
	char	*to_write;

	to_write = "<<< --- CONTROLS --- >>>";
	mlx_string_put(fdf->mlx, fdf->mlx_win, x_pos(to_write), 610, -1, to_write);
	to_write = "ESC : QUIT :(";
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 870, 0xdc143c, to_write);
	to_write = "(but you can always come back!)";
	mlx_string_put(fdf->mlx, fdf->mlx_win, x_pos(to_write), 890, 0xdc143c
		, to_write);
}

static void put_controls_2(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 640, 0xffd700
		, "Left Click : Move");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 660, 0xffd700
		, "Scroll     : zoom In/Out");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 680, 0xffd700
		, "Arrows     : Rotate X/Y axis");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 700, 0xffd700
		, "Q/W        : Rotate Z axis");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 720, 0xffd700
		, "+/-        : Change Z modifier");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 740, 0xffd700
		, "R          : Reset Z modifier");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 760, 0xffd700
		, "Right Click: Change projection");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 780, 0xffd700
		, "C          : Change color");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20, 800, 0xffd700
		, "Space      : Reset");
}

void	write_menu(t_fdf *fdf)
{
	put_map_info(fdf);
	put_draw_info(fdf);
	put_controls_1(fdf);
	put_controls_2(fdf);
	put_signature(fdf);
}
