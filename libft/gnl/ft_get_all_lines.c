/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_all_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:43:45 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/01 19:03:26 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	count_lines(const char *file)
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
	char	*all_file_one_line;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (fd);
	all_file_one_line = ft_calloc(1, 1);
	if (all_file_one_line == NULL)
		return (close(fd));
	line = ft_get_next_line(fd);
	while (line != NULL)
	{
		all_file_one_line = ft_freejoin(all_file_one_line, line);
		free(line);
		line = ft_get_next_line(fd);
	}
	ft_get_next_line(-42);
	*all_lines = ft_split(all_file_one_line, '\n');
	close(fd);
	free(all_file_one_line);
	return (count_lines(file));
}
