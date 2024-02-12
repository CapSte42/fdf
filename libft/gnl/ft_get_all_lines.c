/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_all_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:43:45 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/12 12:55:49 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	ft_count_lines(const char *file)
{
	int		fd;
	ssize_t	i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-2);
	i = 0;
	line = ft_get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		i++;
		line = ft_get_next_line(fd);
	}
	close(fd);
	ft_get_next_line(-42);
	return (i);
}

ssize_t	ft_get_all_lines(const char *file, char ***all_lines)
{
	int		fd;
	int		count_lines;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (fd);
	count_lines = ft_count_lines(file);
	*all_lines = ft_calloc(count_lines + 1, sizeof(char *));
	if (*all_lines == NULL)
		return (close(fd));
	line = ft_get_next_line_no_nl(fd);
	i = 0;
	while (line != NULL)
	{
		(*all_lines)[i] = line;
		line = ft_get_next_line_no_nl(fd);
		i++;
	}
	ft_get_next_line_no_nl(-42);
	close(fd);
	return (count_lines);
}
