/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:33:29 by vsmolii           #+#    #+#             */
/*   Updated: 2018/12/15 17:47:08 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, char *restrict s2, size_t n)
{
	char	*new_s1;
	size_t	i;

	new_s1 = s1;
	while (*s1)
		s1++;
	i = 0;
	while (*s2 && i++ < n)
		*s1++ = *s2++;
	*s1 = '\0';
	return (new_s1);
}
