/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ad_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:04:21 by vsmolii           #+#    #+#             */
/*   Updated: 2018/12/15 21:13:40 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ad_max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				reslt;

	reslt = tab[0];
	i = 0;
	while (i < len)
	{
		if (tab[i] > reslt)
			reslt = tab[i];
		i++;
	}
	return (reslt);
}
