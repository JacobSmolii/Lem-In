/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_work_f_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:19:20 by vsmolii           #+#    #+#             */
/*   Updated: 2019/06/03 16:50:15 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_precs_f(t_format *data, char *str, int sign, long double nbr)
{
	int		i;
	int		len;
	char	*rest;

	len = ft_strlen(str);
	rest = ft_strnew(sign + len + 1 + ((data->prs > 0) ? data->prs : 0));
	i = sign;
	ft_strcpy(rest + i, str);
	i += len;
	if (data->prs > 0)
		rest[i++] = '.';
	while (i < len + sign + ((data->prs > 0) ? (data->prs + 1) : 0))
	{
		rest[i] = ((unsigned long long int)(nbr * 10) % 10) + '0';
		nbr *= 10;
		i++;
	}
	if (sign)
		rest[0] = '-';
	free(str);
	return (rest);
}

char	*convert_float_nbr(t_format *data, long double nbr)
{
	int			pos;
	int			sign;
	long double	d_start;
	char		*str;
	char		*rest;

	rest = NULL;
	pos = 0;
	d_start = 0.45;
	sign = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		sign = 1;
	}
	data->prs = (data->prs_ext == 1) ? data->prs : 6;
	while (data->prs >= 0 && pos < data->prs)
	{
		d_start = d_start / 10;
		pos++;
	}
	nbr = nbr + d_start;
	str = ft_itoa_base_ll((unsigned long long int)nbr, "0123456789");
	rest = get_precs_f(data, str, sign, nbr);
	return (rest);
}

int		start_f_work(va_list arg, t_format *data)
{
	long double		nbr;
	int				len;
	char			*rest;

	if (!ft_strcmp(data->len, "l"))
		nbr = (double)va_arg(arg, double);
	else if (!ft_strcmp(data->len, "ll"))
		nbr = (long double)va_arg(arg, long double);
	else
		nbr = (double)va_arg(arg, double);
	rest = convert_float_nbr(data, nbr);
	len = ft_strlen(rest);
	rest = get_width_f_str(data, rest, len, nbr);
	ft_putstr(rest);
	if (data->w > len || (data->prs < len && data->prs != 0))
		free(rest);
	len = ft_strlen(rest);
	return (len);
}

char	*get_width_f_str(t_format *data, char *str, int len, long double nbr)
{
	char		*rest;

	if (data->p == 1 && nbr > 0)
		str = ft_update(str, ft_strjoin("+", str));
	if (data->sp == 1 && nbr > 0)
		str = ft_update(str, ft_strjoin(" ", str));
	len = ft_strlen(str);
	if (data->w > len)
	{
		rest = get_width_f_str_2(data, str, data->w - len);
		free(str);
	}
	else
		rest = str;
	if (data->w > len && nbr < 0)
		rest = change_symb_position(rest, '-');
	return (rest);
}
