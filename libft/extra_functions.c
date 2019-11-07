/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:29:06 by vsmolii           #+#    #+#             */
/*   Updated: 2019/06/03 16:51:52 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*itoa_filler_b(char *tab, uintmax_t value, int base)
{
	uintmax_t			tmp;
	int					size;
	char				*str;

	size = 0;
	tmp = value;
	while (tmp /= base)
		size++;
	size = size + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[value % base];
		size--;
		value = value / base;
	}
	return (str);
}

char		*ft_itoa_base_unsigned(uintmax_t value, int base)
{
	char	*str;
	char	*rest;

	str = "0123456789abcdef";
	rest = itoa_filler_b(str, value, base);
	return (rest);
}

char		*ft_itoa_base_ll(long long int n, char *base)
{
	unsigned long long int	nbr;
	int						len;
	int						base_len;
	char					*str;

	base_len = ft_strlen(base);
	nbr = (unsigned long long int)n;
	nbr = n < 0 ? -nbr : nbr;
	len = 2;
	while (nbr /= base_len)
		len++;
	nbr = (unsigned long long int)n;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	while (len-- > 0)
	{
		str[len] = base[nbr % base_len];
		nbr /= base_len;
	}
	str[0] = n < 0 ? '-' : str[0];
	return (str);
}

char		*ft_update(char *str, char *update)
{
	free(str);
	str = update;
	return (str);
}

char		*str_fill(int len, char symb)
{
	int		i;
	char	*rest;

	i = 0;
	rest = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		rest[i] = symb;
		i++;
	}
	rest[i] = '\0';
	return (rest);
}
