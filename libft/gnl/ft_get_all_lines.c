/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_all_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:43:45 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/20 22:58:25 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	ft_count_lines(const char *file, int flag)
{
	int		fd;
	ssize_t	i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-2);
	i = 0;
	line = ft_get_next_line(fd);
	if (flag == 1)
		ft_printf("\n Map loading...\n\n");
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
	count_lines = ft_count_lines(file, 0);
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

ssize_t	ft_get_all_lines_f(const char *file, char ***all_lines)
{
	int		fd;
	int		count_lines;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (fd);
	count_lines = ft_count_lines(file, 1);
	*all_lines = ft_calloc(count_lines + 1, sizeof(char *));
	if (*all_lines == NULL)
		return (close(fd));
	line = ft_get_next_line_no_nl(fd);
	i = 0;
	while (line != NULL)
	{
		ft_printf("\r ...%d lines read...", i + 1);
		(*all_lines)[i] = line;
		line = ft_get_next_line_no_nl(fd);
		i++;
	}
	ft_printf("\r%s ...%d total lines read\n%s", GREEN, i, RESET);
	ft_get_next_line_no_nl(-42);
	close(fd);
	return (count_lines);
}
// Path: libft/gnl/ft_get_all_lines.c