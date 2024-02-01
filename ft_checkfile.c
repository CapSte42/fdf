/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:35:53 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/01 23:16:22 by smontuor         ###   ########.fr       */
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

t_coordinates	*set_coordinates(int n_lines, int elem_in_row, char **all_lines)
{
	int				x;
	int				y;
	int				i;
	char			*color;
	t_coordinates	*coordinates;

	if (n_lines <= 0 || elem_in_row <= 0 || all_lines == NULL)
		return (NULL);
	coordinates = malloc(n_lines * elem_in_row * sizeof(t_coordinates));
	if (!coordinates)
		return (NULL);
	y = -1;
	i = -1;
	while (++y < elem_in_row)
	{
		x = -1;
		while (++x < n_lines)
		{
			coordinates[++i].x = x + 1;
			coordinates[i].y = y + 1;
			/*coordinates[i].z =  boia faus sono co. fare split all_lines prima di cercare di assegnarlo*/
		}
	}

}

char	**ft_checkfile(char *file)
{
	char			**all_lines;
	int				n_lines;
	int				elem_in_row;
	char			*dot;
	t_coordinates	*coordinates;

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
	coordinates = set_coordinates(n_lines, elem_in_row, all_lines);
	ft_perror("%d/%d\n", n_lines, elem_in_row);
	return (all_lines);
}
