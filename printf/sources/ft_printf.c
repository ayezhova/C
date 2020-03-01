/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:18:38 by ayezhova          #+#    #+#             */
/*   Updated: 2020/02/04 13:04:53 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	difficult_conv(va_list arg_list, t_flags *flags, int *len)
{
	char c;

	c = flags->conversion_specifier;
	if (c == 'd')
		handle_dif_int(arg_list, flags, len);
	if (c == 'c')
		handle_dif_char(arg_list, flags, len);
	if (c == 'u' || c == 'o' || c == 'x' || c == 'X' || c == 'b' || c == 't')
		handle_dif_unsigned(arg_list, flags, len);
	if (c == 's')
		handle_dif_str(arg_list, flags, len);
	if (c == 'f')
		handle_dif_float(arg_list, flags, len);
	if (c == '%')
		handle_dif_percent(flags, len);
	if (c == 'p')
		handle_dif_point(arg_list, flags, len);
}

static void	reset_flags(t_flags *flags)
{
	int j;

	j = 0;
	while (j < 5)
	{
		flags->conversion_flags[j] = 0;
		j++;
	}
	flags->field_width = -1;
	flags->precision = -1;
	flags->alt_coversion_specifier = '\0';
	flags->conversion_specifier = '\0';
}

static int	handle_conversions(char *str, t_flags *flags,
		va_list arg_list, int *len)
{
	int j;

	j = 0;
	reset_flags(flags);
	j = 1 + j + check_cover_flags(str, flags, j + 1);
	j += check_field_width(str, flags, j, arg_list);
	j += check_precision(str, flags, j, arg_list);
	j += check_alt_specifier(str, flags, j);
	j += find_specifier(str, flags, j);
	difficult_conv(arg_list, flags, len);
	return (j);
}

static int	handle_arg(t_flags *flags, va_list arg_list, char *str, int *len)
{
	char	c;
	int		j;

	c = str[1];
	j = 0;
	if (c == 'c' || c == 'd' || c == 'i' || c == '%' || c == 's' ||
			c == 'o' || c == 'x' || c == 'X' || c == 'p' || c == 'n' ||
			c == 'M')
		j += handle_simple_conversion(c, arg_list, len);
	else
		j += handle_conversions(&str[j], flags, arg_list, len);
	return (j);
}

int			ft_printf(char *str, ...)
{
	va_list				arg_list;
	t_flags				flags;
	int					i;
	int					j;
	int					len;

	i = 0;
	len = 0;
	va_start(arg_list, str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] != '%')
			j++;
		write(1, &str[i], j);
		len += j;
		if (str[i + j] != '\0')
			j += handle_arg(&flags, arg_list, &str[i + j], &len);
		i = i + j;
	}
	va_end(arg_list);
	return (len);
}
