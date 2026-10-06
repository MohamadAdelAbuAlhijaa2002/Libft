/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabualha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:15:06 by mabualha          #+#    #+#             */
/*   Updated: 2026/10/06 18:51:51 by mabualha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long n)
{
	if (n < 0)
		return (1 + ft_numlen(-n));
	if (n < 10)
		return (1);
	return (1 + ft_numlen(n / 10));
}

static void	ft_putnum(char *str, long n, int *i)
{
	if (n >= 10)
		ft_putnum(str, n / 10, i);
	str[*i] = (n % 10) + '0';
	(*i)++;
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;
	int		i;

	num = n;
	len = ft_numlen(num);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (num < 0)
	{
		str[i++] = '-';
		num = -num;
	}
	ft_putnum(str, num, &i);
	str[i] = '\0';
	return (str);
}
