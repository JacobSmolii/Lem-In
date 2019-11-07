/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_work_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:03:44 by vsmolii           #+#    #+#             */
/*   Updated: 2019/06/03 16:49:51 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		start_d_work(va_list arg, t_format *data)
{
	int			length;
	intmax_t	nbr;
	char		*rest;

	length = 0;
	nbr = va_arg(arg, intmax_t);
	if (!ft_strcmp(data->len, "hh"))
		nbr = (signed char)nbr;
	else if (!ft_strcmp(data->len, "h"))
		nbr = (short int)nbr;
	else if (!ft_strcmp(data->len, "l"))
		nbr = (long int)nbr;
	else if (!ft_strcmp(data->len, "ll"))
		nbr = (long long int)nbr;
	else
		nbr = (int)nbr;
	rest = work_with_d_format(data, nbr);
	length = ft_strlen(rest);
	ft_putstr(rest);
	free(rest);
	return (length);
}

char	*work_with_d_format(t_format *data, intmax_t nbr)
{
	int		len_str;
	char	*str;

	str = ft_itoa_intmax(nbr);
	len_str = ft_strlen(str);
	if (data->prs >= 0)
		str = get_precision_str(data, str, len_str, nbr);
	if (data->w > 0)
		str = get_width_str(data, str, nbr);
	return (str);
}

char	*get_width_str(t_format *data, char *str, intmax_t nbr)
{
	int		len_str;
	int		len_new;
	char	*rest;

	str = get_width_str_2(data, str, nbr);
	len_str = ft_strlen(str);
	if (data->w > len_str)
	{
		len_new = data->w - len_str;
		rest = extra_func_d(data, str, len_new);
	}
	else
		rest = ft_strdup(str);
	if (data->p == 1 && data->z == 1 && data->w > len_str)
		rest = change_symb_position(rest, '+');
	if (data->w > len_str && nbr < 0 && data->z == 1)
		rest = change_symb_position(rest, '-');
	free(str);
	return (rest);
}

char	*get_precision_str(t_format *data, char *s, int len_s, intmax_t nbr)
{
	char	*rest;

	if (nbr < 0)
		rest = ft_update(s, precis_str_fill(data, s, len_s, nbr));
	else
		rest = (data->prs >= len_s) ? precis_str_fill(data, s, len_s, nbr) : s;
	if (data->p == 1 && nbr > 0)
	{
		rest = ft_update(rest, flag_plus_or_space(rest, '+'));
		data->ch = 1;
	}
	if (data->sp == 1 && nbr > 0 && data->p == 0)
		rest = ft_update(rest, flag_plus_or_space(rest, ' '));
	return (rest);
}

char	*precis_str_fill(t_format *data, char *str, int len_str, intmax_t nbr)
{
	char	*rest;
	char	*tmp;

	if (nbr < 0)
	{
		tmp = ft_itoa_intmax(nbr * (-1));
		len_str = ft_strlen(tmp);
	}
	else
		tmp = str;
	if (data->prs > 0)
	{
		rest = ft_strnew(1);
		rest = ft_update(rest, str_fill(data->prs - len_str, '0'));
		rest = ft_update(rest, ft_strjoin(rest, tmp));
	}
	else
		rest = ft_strdup(tmp);
	if (nbr < 0)
		rest = ft_update(rest, ft_strjoin("-", rest));
	ft_strdel(&tmp);
	return (rest);
}
