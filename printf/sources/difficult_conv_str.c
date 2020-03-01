/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difficult_conv_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:14:00 by ayezhova          #+#    #+#             */
/*   Updated: 2020/02/04 13:04:29 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_dif_str(va_list args, t_flags *flags, int *len_total)
{
	char	*str;
	int		i;
	int		spaces;
	int		digits;
	char	null_str[7];

	i = 0;
	str = va_arg(args, char*);
	if (str == NULL)
	{
		ft_strcpy(null_str, "(null)");
		str = null_str;
	}
	i = ft_strlen(str);
	if (flags->precision == -1)
		digits = i;
	else
		digits = ft_min(flags->precision, i);
	spaces = flags->field_width - digits;
	if (flags->conversion_flags[0] == 0 && spaces > 0)
		print_char(' ', spaces);
	write(1, str, digits);
	if (flags->conversion_flags[0] == 1 && spaces > 0)
		print_char(' ', spaces);
	*len_total = (*len_total) + ft_max(digits, 0) + ft_max(spaces, 0);
}

void	handle_dif_percent(t_flags *flags, int *len)
{
	int		spaces;

	spaces = flags->field_width - 1;
	if (flags->conversion_flags[0] == 0 && spaces > 0 &&
			flags->conversion_flags[1] == 0)
		print_char(' ', spaces);
	else if (flags->conversion_flags[0] == 0 && spaces > 0 &&
			flags->conversion_flags[1] == 1)
		print_char('0', spaces);
	write(1, "%", 1);
	if (flags->conversion_flags[0] == 1 && spaces > 0)
		print_char(' ', spaces);
	*len = (*len) + ft_max(spaces, 0) + 1;
}

void	handle_dif_point(va_list args, t_flags *flags, int *len_total)
{
	unsigned long int	long_int;
	char				*str;
	int					len;
	int					spaces;
	int					zeros;

	long_int = va_arg(args, unsigned long int);
	str = ft_itoa_base(long_int, 16, 1, &len);
	spaces = flags->field_width - ft_max(flags->precision, len) - 2;
	if (flags->conversion_flags[0] == 0 && spaces > 0)
		print_char(' ', spaces);
	write(1, "0x", 2);
	zeros = flags->precision - len;
	if (zeros > 0)
		print_char('0', zeros);
	write(1, str, len);
	if (flags->conversion_flags[0] == 1 && spaces > 0)
		print_char(' ', spaces);
	*len_total = (*len_total) + ft_max(spaces, 0) + ft_max(zeros, 0) + len + 2;
	free(str);
}
