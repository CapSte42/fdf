/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:35:53 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/01 17:14:18 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_elements(const char *line)
{
	int	count;
	int	in_element;
	int	i;

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
		} else if (line[i] == ' ')
		{
			in_element = 0;
		}
		i++;
	}
	return (count);
}

static int	check_consistency(int n_lines, char **all_lines)
{
	int	i;
	int	expected_elements;
	int	num_elements;

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
}

char	**ft_checkfile(char *file)
{
	char	**all_lines;
	int		n_lines;
	char	*dot;

	if (!file)
		ft_exit_error("Yeah. Whatever.");
	ft_check_format(file, ".fdf");
	n_lines = ft_get_all_lines(file, &all_lines);
	if (n_lines == -1)
		ft_exit_error("File passed as argument is dumb.");
	if (check_consistency(n_lines, all_lines) == 0)
	{
		ft_free_n(0, 1, &all_lines);
		ft_exit_error("Bad map format.");
	}
	return (all_lines);
}
