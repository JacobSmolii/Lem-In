/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 21:03:11 by vsmolii           #+#    #+#             */
/*   Updated: 2019/06/03 16:51:44 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_sign(long long nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	return (nbr);
}

char		*itoa_fill(char *str, long long value, int flag)
{
	int			len;
	long long	tmp;
	char		*rest;

	len = 0;
	tmp = ft_sign(value);
	while (tmp /= 10)
		len++;
	len = len + flag + 1;
	rest = (char *)malloc(sizeof(char) * (len + 1));
	if (rest == NULL)
		return (NULL);
	rest[len] = '\0';
	if (flag == 1)
		rest[0] = '-';
	while (len > flag)
	{
		rest[len - 1] = str[ft_sign(value % 10)];
		len--;
		value /= 10;
	}
	return (rest);
}

char		*ft_itoa_intmax(long long value)
{
	int		flag;
	char	*rest;
	char	*str;

	flag = 0;
	str = "0123456789abcdef";
	if (value < 0)
		flag = 1;
	rest = itoa_fill(str, value, flag);
	return (rest);
}

char		*itoa_fill_un(char *str, uintmax_t value, int base)
{
	int			len;
	uintmax_t	tmp;
	char		*rest;

	len = 0;
	tmp = value;
	while (tmp /= base)
		len++;
	len += 1;
	rest = (char *)malloc(sizeof(char) * (len + 1));
	rest[len] = '\0';
	while (len > 0)
	{
		rest[len - 1] = str[value % base];
		len--;
		value /= base;
	}
	return (rest);
}

char		*itoa_fill_unsigned(uintmax_t value, int base)
{
	char	*str;
	char	*rest;

	str = "0123456789abcdef";
	rest = itoa_fill_un(str, value, base);
	return (rest);
}
