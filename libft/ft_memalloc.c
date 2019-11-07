/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:34:21 by vsmolii           #+#    #+#             */
/*   Updated: 2018/12/15 17:46:06 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(sizeof(str) * size);
	if (str != NULL)
	{
		i = 0;
		while (i < size)
		{
			str[i] = '\0';
			i++;
		}
	}
	return (str);
}
