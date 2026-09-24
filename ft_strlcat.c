/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabualha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:38:11 by mabualha          #+#    #+#             */
/*   Updated: 2026/09/24 17:03:15 by mabualha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	count;
	size_t	x;

	i = 0;
	count = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	while (src[count] != '\0')
		count++;
	if (i >= size)
		return (size + count);
	x = 0;
	while (src[x] != '\0' && (i + x) < size - 1)
	{
		dest[i + x] = src[x];
		x++;
	}
	dest[i + x] = '\0';
	return (i + count);
}
