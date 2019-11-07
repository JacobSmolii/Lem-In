/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_work_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 22:27:18 by vsmolii           #+#    #+#             */
/*   Updated: 2019/06/03 16:50:46 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		work_with_s_format(va_list arg, t_format *data)
{
	int		length;
	int		len_str;
	char	*rest;
	char	*str;

	length = 0;
	str = va_arg(arg, char *);
	if (!str)
		str = "(null)";
	len_str = ft_strlen(str);
	if (data->prs >= 0)
		rest = get_precision_new_str(data, str, len_str);
	length = ft_strlen(rest);
	if (data->w > 0)
		rest = get_width_new_str(data, rest);
	ft_putstr(rest);
	free(rest);
	length = ft_strlen(rest);
	return (length);
}

char	*get_width_new_str(t_format *data, char *str)
{
	int		i;
	int		len;
	char	*rest;
	char	*tmp;

	i = 0;
	len = ft_strlen(str);
	if (data->w > len)
	{
		tmp = str_fill(data->w - len, ' ');
		rest = (data->ms == 1) ? ft_update(tmp, ft_strjoin(str, tmp)) \
								: ft_update(tmp, ft_strjoin(tmp, str));
	}
	else
		rest = str;
	free(str);
	return (rest);
}

char	*get_precision_new_str(t_format *data, char *str, int len_str)
{
	int		i;
	char	*rest;

	rest = NULL;
	i = 0;
	if (data->prs < len_str)
	{
		rest = (char *)malloc(sizeof(char) * (data->prs + 1));
		while (i < data->prs)
		{
			rest[i] = *str;
			i++;
			str++;
		}
		rest[i] = '\0';
	}
	if (data->prs >= len_str || data->prs == 0)
	{
		if (rest)
			free(rest);
		rest = ft_strdup(str);
	}
	return (rest);
}

int		work_woth_c_format(va_list arg, t_format *data)
{
	int		length;
	int		c;
	char	*str;
	char	*rest;

	c = va_arg(arg, int);
	str = (char *)malloc(sizeof(char) * 2);
	str[0] = (char)c;
	str[1] = '\0';
	if (data->w > 1)
	{
		rest = extra_func_c_2(data, data->w - 1, str, c);
		length = data->w;
		free(str);
	}
	else
	{
		rest = str;
		length = 1;
	}
	write(1, rest, length);
	free(rest);
	return (length);
}

char	*extra_func_c_2(t_format *data, int len, char *str, char c)
{
	char	*rest;

	rest = str_fill(data->w - 1, ' ');
	if (c == '\0' && data->ms == 1)
		rest = ft_update(rest, extra_func_c_1(rest, len));
	else
		rest = (data->ms == 1) ? ft_update(rest, ft_strjoin(str, rest)) \
								: ft_update(rest, ft_strjoin(rest, str));
	return (rest);
}
