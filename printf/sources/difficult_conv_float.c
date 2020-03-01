/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difficult_conv_float.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:25:10 by ayezhova          #+#    #+#             */
/*   Updated: 2020/02/04 13:04:13 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		write_sign_f(t_flags *flags, int neg)
{
	if (flags->conversion_flags[2] == 1 && neg == 0)
		write(1, "+", 1);
	else if (flags->conversion_flags[3] == 1 && neg == 0)
		write(1, " ", 1);
	if (neg == 1)
	{
		write(1, "-", 1);
	}
}

static void		write_str(t_flags *f, char *str, int int_l, int dec_l)
{
	if (f->precision != 0 || f->conversion_flags[4] == 1)
		write(1, str, int_l + dec_l + 1);
	else
	{
		write(1, str, int_l);
	}
	free(str);
}

static void		write_space(t_flags *flags, int spaces)
{
	if (flags->conversion_flags[0] == 0 && flags->conversion_flags[1] == 1)
		print_char('0', spaces);
	if (flags->conversion_flags[0] == 0 && spaces > 0 &&
			flags->conversion_flags[1] == 0)
		print_char(' ', spaces);
}

static void		dif_float(long double num, t_flags *f,
		int *len_total, int neg)
{
	int		spaces;
	int		len[2];
	int		sign;
	char	*str;

	sign = 0;
	if (f->precision == -1)
		f->precision = 6;
	str = ft_ftoa(num, len, neg, f->precision);
	if (f->precision != 0)
		spaces = ft_max(f->field_width - 1 - len[0] - len[1] - sign, 0);
	else
		spaces = ft_max(f->field_width - len[0] - len[1] - sign, 0);
	if (neg == 1 || f->conversion_flags[2] == 1 || f->conversion_flags[3] == 1)
		sign = 1;
	if (f->precision != 0)
		spaces = ft_max(f->field_width - 1 - len[0] - len[1] - sign, 0);
	else
		spaces = ft_max(f->field_width - len[0] - len[1] - sign, 0);
	write_space(f, spaces);
	write_sign_f(f, neg);
	write_str(f, str, len[0], len[1]);
	if (f->conversion_flags[0] == 1)
		print_char(' ', spaces);
	(*len_total) += ft_max(f->field_width, len[0] + len[1] + 1 + sign);
}

void			handle_dif_float(va_list args, t_flags *flags,
		int *len_total)
{
	long double		float_arg;
	int				neg;

	neg = 0;
	if (flags->alt_coversion_specifier == 'L')
		float_arg = (long double)va_arg(args, long double);
	else
		float_arg = (long double)va_arg(args, double);
	if (float_arg < 0)
	{
		neg = 1;
		float_arg *= -1;
	}
	dif_float(float_arg, flags, len_total, neg);
}
