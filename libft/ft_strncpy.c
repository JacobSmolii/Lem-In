/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:43:16 by vsmolii           #+#    #+#             */
/*   Updated: 2018/12/15 17:47:10 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char	*ret;
	size_t	x;

	x = -1;
	ret = dest;
	while (++x < len)
	{
		if (*(src))
			*(dest++) = *(src++);
		else
			*(dest++) = 0;
	}
	return (ret);
}
