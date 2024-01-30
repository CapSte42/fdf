/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:35:53 by smontuor          #+#    #+#             */
/*   Updated: 2024/01/27 19:58:24 by smontuor         ###   ########.fr       */
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

static int	count_elements(const char *line)
{
	int count;
	int in_element;
	int i;

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

static void check_consistency(int n_lines, char **all_lines)
{
	int	i;
	int	expected_elements;
	int	num_elements;

	if (n_lines <= 0 || all_lines == NULL)
		// Gestisci caso di input non valido
	i = 0;
	expected_elements = count_elements(all_lines[0]);
	if (expected_elements == -1)
		// Gestisci l'errore o la riga vuota
	i = 1;
	while (i < n_lines)
	{
		num_elements = count_elements(all_lines[i]);
		if (num_elements != expected_elements)
		{
			// Inconsistenza trovata, gestisci come necessario
			return;
		}
		i++;
	}
    // Tutte le righe sono consistenti
}

void	ft_checkfile(char *file)
{
	char	**all_lines;
	int		n_lines;

	if (!file)
		ft_exit_error("Yeah. Whatever.");
	is_fdf_file(file);
	n_lines = ft_get_all_lines(file, &all_lines);
	if (n_lines == -1)
		ft_exit_error("File passed as argument is dumb.");
	check_consistency(n_lines, all_lines);
	
}

/* devo controllare la coerenza della matrice ottenuta, ossia se e' compatibile con
una mappa fdf. mi basta controllare che il numero di righe e di colonne sia maggiore 0 */