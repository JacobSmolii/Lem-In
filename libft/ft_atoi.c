/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:40:05 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 20:33:59 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			check_atoi(int nbr)
{
	if (nbr < -2147483648 || nbr > 2147483647)
	{
		ft_printf("ERROR, int is not valid\n");
		exit(1);
	}
}

int				ft_atoi(const char *str)
{
	intmax_t	i;
	intmax_t	sign;
	intmax_t	nbr;

	i = 0;
	nbr = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\r' || *str == '\t'
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	nbr = nbr * sign;
	check_atoi(nbr);
	return (nbr);
}
