/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:18:06 by smontuor          #+#    #+#             */
/*   Updated: 2024/07/21 08:34:21 by smontuor         ###   ########.fr       */
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
# include <pthread.h>

/*
 * in ft_checkfile.c
*/
void		ft_checkfile(char *file, t_fdf *fdf);
/*
 * in mlx_related.c
*/
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_start_mlx(t_fdf *fdf);
void		clear_menu_win(t_fdf *fdf);
void		my_mlx_put_image_to_window(t_fdf *fdf, int flag);
int			expose_hook(t_fdf *fdf);
/*
 * in zoom_related.c
*/
void		set_zoom_and_center(t_fdf *fdf);
/*
 * in projection_related.c
*/
void		isometric_projection(t_fdf *info);
void		parallel_projection(t_fdf *info, int axis);
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
/*
 * in put_signature.c
*/
void		put_signature(t_fdf *fdf);
/*
 * in debug_utils.c
*/
void		print_coords(t_fdf *fdf);
void		print_iso_coords(t_fdf *fdf);
int			x_pos(char *s);
/*
 * in key_press_related.c
*/
void		clear_image(t_fdf *fdf);
void		reset_z(t_fdf *info);
void		calculate_look_at_for_height_map(t_fdf *info);
void		update_z(t_fdf *info, int flag);
void		reset_z(t_fdf *info);
/*
 * in deploy_map.c
*/
void		deploy_map(t_fdf *fdf);
void		deploy_sphere(t_fdf *fdf);
/*
* in hook_related.c
*/
int			ft_cool_exit(t_fdf *fdf);
void		projection_setup(t_fdf *fdf);
int			key_hook(int keycode, t_fdf *fdf);
int			mouse_hook(int button, int x, int y, t_fdf *fdf);
int			mouse_move(int x, int y, t_fdf *fdf);
int			mouse_release_hook(int button, int x, int y, t_fdf *fdf);
/*
* in init.c
*/
void		set_is_zero(t_fdf *info);
int			get_and_set_parallel_axis(t_fdf *fdf, int flag);
void		go_parallel(t_fdf *fdf);
/*
* in sphere_related.c
*/
void		apply_flat_to_sphere(t_fdf *info);

/*
* in main.c
*/
int			main(int ac, char **av);

/*
 * esperimenti
*/
// void my_mlx_pixel_put_opacity(t_data *data, int x,
//	TOUPint y, unsigned int color, double opacity);
void		drawLine(t_fdf *fdf, t_coords start, t_coords end);
// aggiustare //
void		change_earth_color(t_fdf *fdf);
void		change_stroboscope_color(t_fdf *fdf);
void		change_shadowed_color(t_fdf *fdf);
void		reset_colors(t_fdf *fdf);

#endif
