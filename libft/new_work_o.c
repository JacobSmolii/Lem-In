/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_work_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:06:33 by vsmolii           #+#    #+#             */
/*   Updated: 2019/06/03 16:50:15 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		start_o_work(va_list arg, t_format *data, char *str, int *i)
{
	int			length;
	uintmax_t	nbr;
	char		*rest;

	extra_func_o(data, str, i);
	length = 0;
	nbr = va_arg(arg, uintmax_t);
	if (!ft_strcmp(data->len, "hh"))
		nbr = (unsigned char)nbr;
	else if (!ft_strcmp(data->len, "h"))
		nbr = (unsigned short int)nbr;
	else if (!ft_strcmp(data->len, "l"))
		nbr = (unsigned long int)nbr;
	else if (!ft_strcmp(data->len, "ll"))
		nbr = (unsigned long long int)nbr;
	else
		nbr = (unsigned int)nbr;
	rest = work_with_o_format(data, nbr);
	ft_putstr(rest);
	length = ft_strlen(rest);
	free(rest);
	return (length);
}

void	extra_func_o(t_format *data, char *str, int *i)
{
	if (str[*i] == 'u')
		data->ch = 1;
	if (str[*i] == 'x' || str[*i] == 'X')
	{
		if (str[*i] == 'X')
			data->ch_cap_x = 1;
		data->x_cap_x = 1;
	}
}

char	*work_with_o_format(t_format *data, uintmax_t n)
{
	int		len_str;
	char	*str;

	if (data->x_cap_x == 1)
		str = ft_itoa_base_unsigned(n, 16);
	else
		str = (data->ch == 1) ? ft_itoa_unsigned(n) : itoa_fill_unsigned(n, 8);
	len_str = ft_strlen(str);
	if (data->prs >= 0)
		str = get_precs_o_str(data, str, len_str, n);
	if (data->w > 0)
		str = get_width_o_str(data, str);
	if (data->ch_cap_x == 1)
		str = ft_toupper_str(str);
	return (str);
}

char	*get_width_o_str(t_format *data, char *str)
{
	int		len;
	char	*rest;

	len = ft_strlen(str);
	if (data->w > len)
	{
		len = data->w - len;
		if (data->z == 1 && data->prs == 0)
		{
			rest = str_fill(len, '0');
			rest = ft_update(rest, ft_strjoin(rest, str));
		}
		else
		{
			rest = str_fill(len, ' ');
			rest = (data->ms == 1) ? ft_update(rest, ft_strjoin(str, rest)) \
									: ft_update(rest, ft_strjoin(rest, str));
		}
	}
	else
		rest = ft_strdup(str);
	free(str);
	return (rest);
}

char	*get_precs_o_str(t_format *data, char *str, int len_s, uintmax_t nbr)
{
	int		i;
	char	*rest;

	i = 0;
	if (data->h == 1 && data->prs <= len_s && data->ch == 0
									&& data->x_cap_x == 0)
		str = ft_update(str, flag_plus_or_space(str, '0'));
	rest = (data->prs > len_s) ? precis_str_fill(data, str, len_s, nbr) : str;
	if (data->x_cap_x == 1 && data->h == 1 && nbr > 0)
		rest = ft_update(rest, ft_strjoin("0x", rest));
	return (rest);
}
