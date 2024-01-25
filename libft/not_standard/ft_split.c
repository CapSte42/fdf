/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:08:57 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/19 17:06:45 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*get_next_word(char const *s, char c, size_t *start)
{
	size_t	end;

	while (s[*start] == c)
		(*start)++;
	end = *start;
	while (s[end] && s[end] != c)
		end++;
	return (ft_substr(s, *start, end - *start));
}

static void	free_all(char **result, size_t i)
{
	i--;
	while (i > 0)
	{
		i--;
		free(result[i]);
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	size_t	i;
	size_t	start;
	char	**result;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	while (i < word_count)
	{
		result[i] = get_next_word(s, c, &start);
		if (!result[i++])
		{
			free_all(result, i);
			return (NULL);
		}
		start += ft_strlen(result[i - 1]);
	}
	result[word_count] = NULL;
	return (result);
}

/*Parameters
	s: The string to be split.
	c: The delimiter character.
Return value
	The array of new strings resulting from the split.
	NULL if the allocation fails.
External functs
	malloc, free
Description
	Allocates (with malloc(3)) and returns an array
	of strings obtained by splitting ’s’ using the
	character ’c’ as a delimiter. The array must end
	with a NULL pointer.
-------------------------------------------------------------------------------
#include <stdio.h>
#include "libft.h"

int main(void)
{
    char *s = "Ciao, come stai? Spero che tu stia bene!";
    char c = ' ';
    char **words = ft_split(s, c);

    if (!words)
    {
        printf("Errore di allocazione della memoria.\n");
        return (1);
    }

    for (size_t i = 0; words[i] != NULL; i++)
    {
        printf("Parola %zu: %s\n", i + 1, words[i]);
        free(words[i]);
    }
    free(words);

    return (0);
}
*/