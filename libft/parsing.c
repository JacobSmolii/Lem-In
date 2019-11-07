/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:53:08 by vsmolii           #+#    #+#             */
/*   Updated: 2019/06/03 16:50:46 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_flags(t_format *data, char *str, int i)
{
	init_data(data);
	while (str[i] == '+' || str[i] == '-' || str[i] == '#' || str[i] == ' ' ||
			str[i] == '0')
	{
		if (str[i] == '+')
			data->p = 1;
		if (str[i] == '-')
			data->ms = 1;
		if (str[i] == '#')
			data->h = 1;
		if (str[i] == ' ')
			data->sp = 1;
		if (str[i] == '0')
			data->z = 1;
		i++;
	}
	return (i);
}

void	init_data(t_format *data)
{
	data->p = 0;
	data->ms = 0;
	data->h = 0;
	data->sp = 0;
	data->z = 0;
	data->ch = 0;
	data->ch_cap_x = 0;
	data->x_cap_x = 0;
	data->w = 0;
	data->prs = 0;
	data->prs_ext = 0;
	data->len = "";
}

int		get_width(t_format *data, char *str, int i)
{
	if ((str[i] >= '0' && str[i] <= '9'))
		data->w = ft_atoi(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int		get_precision(t_format *data, char *str, int i)
{
	if (str[i] == '.')
	{
		i++;
		if (str[i] >= '0' && str[i] <= '9')
		{
			data->prs_ext = 1;
			data->prs = ft_atoi(&str[i]);
		}
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (i);
}

int		get_length_flag(t_format *data, char *str, int i)
{
	if (str[i] == 'l' || str[i] == 'L' || str[i] == 'h' || str[i] == 'h')
	{
		if (str[i] == 'l')
			data->len = "l";
		if (str[i] == 'h')
			data->len = "h";
		i++;
	}
	if (str[i] == 'l' || str[i] == 'h')
	{
		if (str[i] == 'l')
			data->len = "ll";
		if (str[i] == 'h')
			data->len = "hh";
		i++;
	}
	return (i);
}
