/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difficult_conv_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:24:02 by ayezhova          #+#    #+#             */
/*   Updated: 2020/02/04 13:04:06 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_dif_char(va_list arg_list, t_flags *flags, int *len)
{
	char	c;
	int		width;

	c = (char)va_arg(arg_list, int);
	width = flags->field_width;
	if (flags->conversion_flags[1] == 1 && flags->conversion_flags[0] == 0)
		print_char('0', width - 1);
	else if (flags->conversion_flags[0] == 0)
		print_char(' ', width - 1);
	write(1, &c, 1);
	if (flags->conversion_flags[0] == 1)
		print_char(' ', width - 1);
	(*len) += ft_max(width - 1, 0) + 1;
}
