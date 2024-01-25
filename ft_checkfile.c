/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:35:53 by smontuor          #+#    #+#             */
/*   Updated: 2024/01/25 17:48:16 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	is_fdf_file(const char *file)
{
	char	*dot;

	dot = ft_strrchr(file, '.');
	if (!dot || dot == file)
		ft_exit_error("Wrong file format: expected a .fdf file.");
	if (!ft_strncmp(dot, ".fdf", 5) == 0)
		ft_exit_error("Wrong file format: expected a .fdf file.");

}

static void	check_consistency(int n_lines, char **all_lines)
{
	int	i;
	char	**line;

	i = 0;
	while (i < n_lines)
	{
		ft_printf(2, "<%s>\n",all_lines[i]);
		line = ft_split(all_lines[i], ' ');
		if (check_line(line) /*AAAAAAAAAAAAAAAAAAAAAAAAAAAAA*/)
			/* AAAAAAAAAAAAAAAAAA */
		i++;
	}
}

static int	check_line(char **line)
{
	
}

void	ft_checkfile(char *file)
{
	char	**all_lines;
	int		n_lines;

	if (!file)
		ft_exit_error("Please enter a .fdf file as an argument.");
	is_fdf_file(file);
	n_lines = ft_get_all_lines(file, &all_lines);
	if (n_lines == -1)
		ft_exit_error("File passed as argument is empty.");
	/* check_consistency(n_lines, all_lines); */
}

/* devo controllare la coerenza della matrice ottenuta, ossia se e' compatibile con
una mappa fdf. mi basta controllare che il numero di righe e di colonne sia maggiore 0 */