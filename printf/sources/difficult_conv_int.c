/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difficult_conv_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:44:01 by ayezhova          #+#    #+#             */
/*   Updated: 2020/02/04 13:04:25 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_char(char c, int n)
{
	char	str[n + 1];
	int		i;

	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	write(1, str, n);
}

static void	write_sign(t_flags *flags, intmax_t *value, int min)
{
	if (flags->conversion_flags[2] == 1 && (*value) >= 0)
		write(1, "+", 1);
	else if (flags->conversion_flags[3] == 1 && (*value) >= 0)
		write(1, " ", 1);
	if ((*value) < 0)
	{
		write(1, "-", 1);
		if (min == 0)
			*value = (*value) * -1;
	}
}

static void	write_zeros(t_flags *flags, int *zeros, int *spaces,
		int digits)
{
	if (flags->precision == -1 && flags->conversion_flags[1] == 1 &&
			flags->conversion_flags[0] == 0)
	{
		(*zeros) = (*spaces);
		(*spaces) = 0;
	}
	else
		(*zeros) = flags->precision - digits;
	if ((*zeros) > 0)
		print_char('0', (*zeros));
}

static void	dif_int(intmax_t ret, t_flags *flags, int *len)
{
	int digits;
	int sign;
	int spaces;
	int zeros;
	int min;

	sign = 0;
	min = 0;
	if (ret == -9223372036854775807 - 1)
		min = 1;
	digits = ft_countdigits_nosign(ret, flags->precision);
	if (ret < 0 || flags->conversion_flags[2] == 1 ||
			flags->conversion_flags[3] == 1)
		sign = 1;
	spaces = flags->field_width - sign - ft_max(flags->precision, digits);
	if (flags->conversion_flags[0] == 0 && spaces > 0 &&
			!(flags->precision == -1 && flags->conversion_flags[1] == 1))
		print_char(' ', spaces);
	write_sign(flags, &ret, min);
	write_zeros(flags, &zeros, &spaces, digits);
	if (digits != 0)
		ft_putnbr(ret);
	if (flags->conversion_flags[0] == 1 && spaces > 0)
		print_char(' ', spaces);
	*len = (*len) + ft_max(spaces, 0) + ft_max(zeros, 0) + digits + sign;
}

void		handle_dif_int(va_list arg_list, t_flags *flags, int *len)
{
	intmax_t ret;

	if (flags->alt_coversion_specifier == '\0')
		ret = (intmax_t)va_arg(arg_list, int);
	if (flags->alt_coversion_specifier == 'h')
		ret = (intmax_t)(short int)va_arg(arg_list, int);
	if (flags->alt_coversion_specifier == 'H')
		ret = (intmax_t)(signed char)va_arg(arg_list, int);
	if (flags->alt_coversion_specifier == 'l')
		ret = (intmax_t)va_arg(arg_list, long int);
	if (flags->alt_coversion_specifier == 'd')
		ret = (intmax_t)va_arg(arg_list, long long int);
	if (flags->alt_coversion_specifier == 'z')
		ret = (uintmax_t)va_arg(arg_list, size_t);
	if (flags->alt_coversion_specifier == 'j')
		ret = (uintmax_t)va_arg(arg_list, intmax_t);
	dif_int(ret, flags, len);
}
