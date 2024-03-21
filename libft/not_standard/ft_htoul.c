/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:43:50 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/06 23:21:47 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned long int	ft_htoul(const char *s)
{
	int					i;
	unsigned long int	val;
	int					c;

	val = 0;
	i = 0;
	if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X'))
	{
		i += 2;
	}
	while (s[i] != '\0')
	{
		c = s[i];
		if (c >= '0' && c <= '9')
			val = val * 16 + (c - '0');
		else if (c >= 'a' && c <= 'f')
			val = val * 16 + (c - 'a' + 10);
		else if (c >= 'A' && c <= 'F')
			val = val * 16 + (c - 'A' + 10);
		else
			break ;
		i++;
	}
	return (val);
}
