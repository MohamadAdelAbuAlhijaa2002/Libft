/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabualha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:15:06 by mabualha          #+#    #+#             */
/*   Updated: 2026/09/24 17:04:18 by mabualha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*get_word(char const *s, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	word = malloc(end - start + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_words(char **arr, size_t count)
{
	while (count > 0)
	{
		count--;
		free(arr[count]);
	}
	free(arr);
}

static int	fill_words(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			arr[word] = get_word(s, start, i);
			if (arr[word] == NULL)
				return (free_words(arr, word), 0);
			word++;
		}
	}
	arr[word] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	if (!fill_words(arr, s, c))
		return (NULL);
	return (arr);
}
