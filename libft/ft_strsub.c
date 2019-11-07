/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:03:47 by vsmolii           #+#    #+#             */
/*   Updated: 2018/12/28 13:40:04 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*f;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	f = (char *)malloc(sizeof(char) * (len + 1));
	if (!f)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		f[i++] = s[start++];
	}
	f[i] = '\0';
	return (f);
}
