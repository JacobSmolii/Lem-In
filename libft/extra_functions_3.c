/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 21:05:42 by vsmolii           #+#    #+#             */
/*   Updated: 2019/06/03 16:51:44 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*itoa_filler(char *str, uintmax_t value)
{
	int			len;
	uintmax_t	tmp;
	char		*rest;

	len = 0;
	tmp = value;
	while (tmp /= 10)
		len++;
	len += 1;
	rest = (char *)malloc(sizeof(char) * (len + 1));
	if (rest == NULL)
		return (NULL);
	rest[len] = '\0';
	while (len > 0)
	{
		rest[len - 1] = str[value % 10];
		len--;
		value /= 10;
	}
	return (rest);
}

char		*ft_itoa_unsigned(uintmax_t value)
{
	char	*str;
	char	*rest;

	str = "0123456789abcdef";
	rest = itoa_filler(str, value);
	return (rest);
}

intmax_t	ft_abs(intmax_t nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char		*itoa_filler_p(char *tab, intmax_t val, int base, int flag)
{
	uintmax_t		tmp;
	int				size;
	char			*str;

	size = 0;
	tmp = ft_abs(val);
	while (tmp /= base)
		size++;
	size = size + flag + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(val % base)];
		size--;
		val = val / base;
	}
	return (str);
}

char		*ft_itoa_base(intmax_t value, int base)
{
	char			*str;
	char			*tab;
	int				flag;

	flag = 0;
	tab = "0123456789abcdef";
	if (value < 0 && base == 10)
		flag = 1;
	str = itoa_filler_p(tab, value, base, flag);
	return (str);
}
