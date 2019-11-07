/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_work_d_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 21:31:25 by vsmolii           #+#    #+#             */
/*   Updated: 2019/06/03 16:49:51 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*flag_plus_or_space(char *str, char symb)
{
	int		i;
	int		len;
	char	*rest;

	i = 0;
	len = ft_strlen(str);
	rest = (char *)malloc(sizeof(char) * (len + 2));
	rest[0] = symb;
	i++;
	while (*str)
	{
		rest[i] = *str;
		i++;
		str++;
	}
	rest[i] = '\0';
	return (rest);
}

char	*get_width_str_2(t_format *data, char *str, intmax_t nbr)
{
	if (data->p == 1 && data->prs == 0 && nbr > 0 && data->ch == 0)
		str = ft_update(str, flag_plus_or_space(str, '+'));
	return (str);
}

char	*ft_toupper_str(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
	return (str);
}

char	*change_symb_position(char *str, char symb)
{
	int		i;
	char	tmp;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == symb && str[0] == '0')
		{
			tmp = str[i];
			str[i] = str[0];
			str[0] = tmp;
		}
		i++;
	}
	return (str);
}

char	*get_width_f_str_2(t_format *data, char *str, int len)
{
	char	*tmp;
	char	*rest;

	if (data->z == 1)
	{
		tmp = str_fill(data->w - len, '0');
		rest = ft_update(tmp, ft_strjoin(tmp, str));
	}
	else
	{
		tmp = str_fill(data->w - len, ' ');
		rest = (data->ms == 1) ? ft_update(tmp, ft_strjoin(str, tmp)) \
								: ft_update(tmp, ft_strjoin(tmp, str));
	}
	return (rest);
}
