/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:45:17 by vsmolii           #+#    #+#             */
/*   Updated: 2019/06/03 16:51:19 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_output_hope(int *i, va_list arg, char *str)
{
	int			nbr_read_char;
	t_format	*data;

	nbr_read_char = 0;
	data = (t_format *)malloc(sizeof(t_format));
	ft_parsing(data, str, i);
	if (str[*i] == '%')
		nbr_read_char = nbr_read_char + start_persnt_work(data);
	if (str[*i] == 'c')
		nbr_read_char = nbr_read_char + work_woth_c_format(arg, data);
	if (str[*i] == 's')
		nbr_read_char = nbr_read_char + work_with_s_format(arg, data);
	if (str[*i] == 'd' || str[*i] == 'i')
		nbr_read_char = nbr_read_char + start_d_work(arg, data);
	if (str[*i] == 'o' || str[*i] == 'u' || str[*i] == 'x' || str[*i] == 'X')
		nbr_read_char = nbr_read_char + start_o_work(arg, data, str, i);
	if (str[*i] == 'p')
		nbr_read_char = nbr_read_char + start_p_work(arg, data);
	if (str[*i] == 'f')
		nbr_read_char = nbr_read_char + start_f_work(arg, data);
	free(data);
	return (nbr_read_char);
}

void	ft_parsing(t_format *data, char *str, int *i)
{
	*i = get_flags(data, str, *i);
	*i = get_width(data, str, *i);
	*i = get_precision(data, str, *i);
	*i = get_length_flag(data, str, *i);
}

int		ft_printf(char *str, ...)
{
	int		i;
	int		nbr_read_char;
	va_list	arg;

	i = 0;
	nbr_read_char = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
		{
			ft_putchar(str[i]);
			nbr_read_char++;
			i++;
		}
		if (str[i] == '%' && str[i] != '\0')
		{
			i++;
			nbr_read_char += ft_output_hope(&i, arg, str);
		}
		if (str[i] != '\0')
			i++;
	}
	va_end(arg);
	return (nbr_read_char);
}
