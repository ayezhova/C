/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difficult_conv_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:21:57 by ayezhova          #+#    #+#             */
/*   Updated: 2020/02/04 13:04:32 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_putnbr_u(uintmax_t n, int digits)
{
	char	str[digits + 1];
	int		i;

	if (digits == 0)
		return ;
	i = digits;
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	write(1, str, digits);
}

static int		ft_countdigits_nosign_u(uintmax_t n, t_flags *flags)
{
	int count;

	if (flags->precision == 0 && n == 0)
		return (0);
	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void		dif_unsigned(uintmax_t ret, t_flags *flags, int *len)
{
	int digits;
	int spaces;
	int zeros;

	digits = ft_countdigits_nosign_u(ret, flags);
	spaces = flags->field_width - ft_max(flags->precision, digits);
	if (flags->conversion_flags[0] == 0 && spaces > 0 &&
			!(flags->precision == -1 && flags->conversion_flags[1] == 1))
		print_char(' ', spaces);
	if (flags->precision == -1 && flags->conversion_flags[1] == 1 &&
			flags->conversion_flags[0] == 0)
	{
		zeros = spaces;
		spaces = 0;
	}
	else
		zeros = flags->precision - digits;
	if (zeros > 0)
		print_char('0', zeros);
	ft_putnbr_u(ret, digits);
	if (flags->conversion_flags[0] == 1 && spaces > 0)
		print_char(' ', spaces);
	*len = (*len) + ft_max(spaces, 0) + ft_max(zeros, 0) + digits;
}

void			handle_dif_unsigned(va_list arg_list, t_flags *flags,
		int *len)
{
	uintmax_t ret;

	if (flags->alt_coversion_specifier == '\0')
		ret = (uintmax_t)va_arg(arg_list, unsigned int);
	if (flags->alt_coversion_specifier == 'h')
		ret = (uintmax_t)va_arg(arg_list, unsigned int);
	if (flags->alt_coversion_specifier == 'H')
		ret = (uintmax_t)va_arg(arg_list, unsigned int);
	if (flags->alt_coversion_specifier == 'l')
		ret = (uintmax_t)va_arg(arg_list, unsigned long int);
	if (flags->alt_coversion_specifier == 'd')
		ret = (uintmax_t)va_arg(arg_list, unsigned long long int);
	if (flags->alt_coversion_specifier == 'z')
		ret = (uintmax_t)va_arg(arg_list, size_t);
	if (flags->alt_coversion_specifier == 'j')
		ret = (uintmax_t)va_arg(arg_list, uintmax_t);
	if (flags->conversion_specifier == 'u')
		dif_unsigned(ret, flags, len);
	else
		dif_unsigned_base(ret, flags, len);
}
