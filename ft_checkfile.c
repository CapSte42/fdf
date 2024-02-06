/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:35:53 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/06 14:08:54 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_elements(const char *line)
{
	int				count;
	int				in_element;
	int				i;

	if (line == NULL)
	{
		return (-1);
	}
	count = 0;
	in_element = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && in_element == 0)
		{
			in_element = 1;
			count++;
		}
		else if (line[i] == ' ')
		{
			in_element = 0;
		}
		i++;
	}
	return (count);
}

static int	check_consistency(int n_lines, char **all_lines)
{
	int				i;
	int				expected_elements;
	int				num_elements;

	if (n_lines <= 0 || all_lines == NULL)
		ft_exit_error("Something went wrong.");
	i = 0;
	expected_elements = count_elements(all_lines[0]);
	if (expected_elements == -1)
		ft_exit_error("Fill the map with something usefull.");
	i = 1;
	while (i < n_lines)
	{
		num_elements = count_elements(all_lines[i]);
		if (num_elements != expected_elements)
			return (0);
		i++;
	}
	return (expected_elements);
}

static int	set_line(int last_x, int y, char **all_lines, t_coords *coords)
{
	static int	current_i;
	char**		y_line;
	char**		current_elem;

	y_line = ft_split(all_lines[y], ' ');
	while(*y_line)
	{
		coords[current_i].x = (int)(current_i / last_x);
		coords[current_i].y = (int)(current_i % last_x);
		current_elem = ft_split(*y_line, ',');
		if (!current_elem)
			return (ft_free_n(0, 1, y_line), 0);
		coords[current_i].z = ft_atoi(current_elem[0]);
		if (current_elem[1] != NULL)
			coords[current_i].color = current_elem[1]; /* todo color to int hex char* */
		else
			ft_free_n(1, 0, &current_elem);
		y_line++;
		current_i++;
	}
	if (current_i == (last_x * (y + 1)))
		return (ft_free_n(0, 1, y_line), 1);
	return (0);
}

static t_coords	*set_coords(int n_lines, int elem_in_row, char **all_lines)
{
	int				x;
	int				y;
	int				i;
	t_coords		*coords;

	if (n_lines <= 0 || elem_in_row <= 0 || all_lines == NULL)
		return (NULL);
	coords = ft_calloc(sizeof(t_coords), n_lines * elem_in_row);
	if (!coords)
		return (NULL);
	y = -1;
	while (++y < n_lines)
	{
		if (set_line(elem_in_row, y, all_lines, coords) == 0)
			return (NULL);
	}
	return (coords);
}

char	**ft_checkfile(char *file)
{
	char			**all_lines;
	int				n_lines;
	int				elem_in_row;
	char			*dot;
	t_coords		*coords;

	if (!file)
		ft_exit_error("You must be the clever one.");
	ft_check_format(file, ".fdf");
	n_lines = ft_get_all_lines(file, &all_lines);
	if (n_lines == -1)
		ft_exit_error("File passed as argument is dumb.");
	elem_in_row = check_consistency(n_lines, all_lines);
	if (elem_in_row == 0)
	{
		ft_free_n(0, 1, &all_lines);
		ft_exit_error("Bad map format.");
	}
	coords = set_coords(n_lines, elem_in_row, all_lines);
	if (!coords)
	{
		ft_free_n(0, 1, &all_lines);
		ft_perror("Malloc error in set_coords.");
	}
	for(int i = 0; i < n_lines * elem_in_row; i++)
	{
		printf("coords.x = %f , coords.y = %f , coords.z = %f , color = %s\n", coords[i].x, coords[i].y, coords[i].z, coords[i].color);
	}
	return (all_lines);
}
