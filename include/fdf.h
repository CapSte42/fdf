/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:18:06 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/14 01:13:18 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include "struct.h"
# include "macro.h"
# include <math.h>

/*
 * in ft_checkfile.c
*/
void		ft_checkfile(char *file, t_fdf *fdf);
/*
 * in mlx_related.c
*/
int		ft_cool_exit(t_fdf *fdf);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_start_mlx(t_fdf *fdf);
void	my_mlx_put_image_to_window(t_fdf *fdf, int flag);
/*
 * in zoom_related.c
*/
void		set_zoom_and_center(t_fdf *fdf);
/*
 * in projection_related.c
*/
void		isometric_projection(t_fdf *info);
void		conic_projection(t_fdf *fdf);
/*
 * in ft_drawline.c
*/
void		drawline(t_fdf *fdf, t_coords start, t_coords end);
/*
 * in print_menu.c
*/
void		write_menu(t_fdf *fdf);
/*
 * in utils.c
*/
void		reset_iso_coords(t_fdf *fdf);
void		put_menu_win(t_fdf *fdf);
int			x_pos(char *s);
/*
 * in put_signature.c
*/
void		put_signature(t_fdf *fdf);
/*
 * in debug_utils.c
*/
void		print_coords(t_fdf *fdf);
void		print_iso_coords(t_fdf *fdf);
/*
 * in key_press_related.c
*/
void	reset_z(t_fdf *info);
int	key_hook(int keycode, t_fdf *fdf);
/*
* in main.c
*/
void	deploy_map(t_fdf *fdf);
/*
 * esperimenti
*/
// void my_mlx_pixel_put_opacity(t_data *data, int x, int y, unsigned int color, float opacity);
// void drawLine(t_fdf *fdf, t_coords start, t_coords end);
void	set_draw(t_draw *draw, t_coords start, t_coords end); //to put static
// aggiustare //

#endif
