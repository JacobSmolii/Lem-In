/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_work_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:39:00 by vsmolii           #+#    #+#             */
/*   Updated: 2019/06/03 16:50:46 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		start_p_work(va_list arg, t_format *data)
{
	int			length;
	intmax_t	nbr;
	char		*rest;
	char		*str;

	nbr = va_arg(arg, unsigned long);
	str = ft_itoa_base(nbr, 16);
	str = ft_update(str, ft_strjoin("0x", str));
	length = ft_strlen(str);
	if (data->w > length)
		rest = get_width_new_str(data, str);
	else
		rest = str;
	ft_putstr(rest);
	free(rest);
	length = ft_strlen(rest);
	return (length);
}

int		start_persnt_work(t_format *data)
{
	int		len;
	char	*rest;

	len = 0;
	if (data->w > 0)
	{
		len = data->w - 1;
		rest = persent_work_2(data, len);
	}
	else
		rest = "%";
	ft_putstr(rest);
	if (data->w > len)
		free(rest);
	return (ft_strlen(rest));
}

char	*persent_work_2(t_format *data, int len)
{
	char	*tmp;
	char	*rest;

	if (data->z == 1)
	{
		tmp = str_fill(len, '0');
		rest = ft_update(tmp, ft_strjoin(tmp, "%"));
	}
	else
	{
		tmp = str_fill(len, ' ');
		rest = (data->ms == 1) ? ft_update(tmp, ft_strjoin("%", tmp)) \
								: ft_update(tmp, ft_strjoin(tmp, "%"));
	}
	return (rest);
}

char	*extra_func_d(t_format *data, char *str, int len_new)
{
	char	*rest;

	if (data->z == 1 && data->prs == 0)
	{
		rest = str_fill(len_new, '0');
		rest = ft_update(rest, ft_strjoin(rest, str));
	}
	else
	{
		rest = str_fill(len_new, ' ');
		rest = (data->ms == 1) ? ft_update(rest, ft_strjoin(str, rest)) \
								: ft_update(rest, ft_strjoin(rest, str));
	}
	return (rest);
}

char	*extra_func_c_1(char *str, int len)
{
	int		i;
	char	*rest;

	i = 0;
	rest = (char *)malloc(sizeof(char) * (len + 1));
	rest[0] = '\0';
	i++;
	while (i <= len)
	{
		rest[i] = *str;
		str++;
		i++;
	}
	rest[i] = '\0';
	return (rest);
}
