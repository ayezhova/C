/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dificult_conv_base_change.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:27:45 by ayezhova          #+#    #+#             */
/*   Updated: 2020/02/04 13:04:36 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		count_digits_u(long int n, int base)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}

static void		get_base(int *base, int *lower, t_flags *flags)
{
	(*lower) = 1;
	if (flags->conversion_specifier == 'o')
		(*base) = 8;
	if (flags->conversion_specifier == 'x')
		(*base) = 16;
	if (flags->conversion_specifier == 'X')
	{
		(*base) = 16;
		(*lower) = 0;
	}
	if (flags->conversion_specifier == 'b')
		(*base) = 2;
	if (flags->conversion_specifier == 't')
		(*base) = 3;
}

static char		*ft_itoa_base_u(uintmax_t num, t_flags *flags, int *digits)
{
	char	*str;
	int		i;
	char	*possib;
	int		base;
	int		lower;

	get_base(&base, &lower, flags);
	if (lower == 1)
		possib = ft_strdup("0123456789abcdef");
	else
		possib = ft_strdup("0123456789ABCDEF");
	i = -1;
	(*digits) = count_digits_u(num, base);
	if (!(str = (char*)malloc((sizeof(*str) * (*digits) + 1))))
		return (NULL);
	str[(*digits)] = '\0';
	while (++i < (*digits))
	{
		str[(*digits) - 1 - i] = possib[num % base];
		num = num / base;
	}
	free(possib);
	return (str);
}

static void		print_alt(t_flags *flags, uintmax_t ret)
{
	if (ret == 0)
		return ;
	if (flags->conversion_specifier == 'o')
	{
		write(1, "0", 1);
	}
	if (flags->conversion_specifier == 'x')
	{
		write(1, "0x", 2);
	}
	if (flags->conversion_specifier == 'X')
	{
		write(1, "0X", 2);
	}
}

void			dif_unsigned_base(uintmax_t ret, t_flags *f, int *len)
{
	int		digits;
	int		sign;
	int		spaces;
	int		zeros;
	char	*str;

	str = ft_itoa_base_u(ret, f, &digits);
	zeros = alt_num_u(f, &sign, ret);
	check_if_digits_zero(&digits, ret, f);
	spaces = f->field_width - sign - ft_max(f->precision, digits);
	if (f->conversion_flags[0] == 0 && spaces > 0 && !(f->precision == -1
				&& f->conversion_flags[1] == 1))
		print_char(' ', spaces);
	get_zeros_u(f, &zeros, &spaces, digits);
	if (f->conversion_flags[4] == 1)
		print_alt(f, ret);
	if (zeros > 0)
		print_char('0', zeros);
	if (!(ret == 0 && f->precision == 0) || (f->conversion_specifier == 'o'))
		write(1, str, digits);
	if (f->conversion_flags[0] == 1 && spaces > 0)
		print_char(' ', spaces);
	free(str);
	*len = (*len) + ft_max(spaces, 0) + ft_max(zeros, 0) + digits + sign;
}
