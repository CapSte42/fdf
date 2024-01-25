/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_all_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:43:45 by smontuor          #+#    #+#             */
/*   Updated: 2024/01/25 17:34:40 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_lines(const char *file)
{
	int		fd;
	int		i;

	fd = ft_open_file(file);
	if (fd < 0)
		return (-2);
	i = 0;
	while (ft_get_next_line(fd) != NULL)
		i++;
	close(fd);
	ft_get_next_line(-42);
	return (i);
}

int	ft_get_all_lines(const char *file, char ***all_lines)
{
	int		i;
	int		fd;
	char	*line;

	*all_lines = ft_calloc(count_lines(file) + 1, sizeof(char *));
	if (*all_lines == NULL)
		return (-2);
	fd = ft_open_file(file);
	if (fd < 0)
	{
		free(all_lines);
		return (-2);
	}
	line = ft_get_next_line(fd);
	line = ft_strtrim(line, "\n");
	i = -1;
	while (line != NULL)
	{
		(*all_lines)[++i] = line;
		line = ft_get_next_line(fd);
		line = ft_strtrim(line, "\n");
	}
	close(fd);
	ft_get_next_line(-42);
	return (i);
}
