/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_simple_base_change.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:35:06 by ayezhova          #+#    #+#             */
/*   Updated: 2020/02/04 13:05:10 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_simple_oct(va_list args, int *len_total)
{
	char		*str;
	long int	convert_octal;
	int			len;

	convert_octal = va_arg(args, long int);
	str = ft_itoa_base(convert_octal, 8, 0, &len);
	write(1, str, len);
	*len_total = (*len_total) + len;
	free(str);
}

void	handle_simple_hex(va_list args, char c, int *len_total)
{
	char			*str;
	unsigned int	convert_hex;
	int				len;
	int				lower_case;

	lower_case = 0;
	if (c == 'x')
		lower_case = 1;
	convert_hex = va_arg(args, unsigned int);
	str = ft_itoa_base(convert_hex, 16, lower_case, &len);
	write(1, str, len);
	*len_total = (*len_total) + len;
	free(str);
}

void	handle_simple_point(va_list args, int *len_total)
{
	unsigned long int	long_int;
	char				*str;
	int					len;

	long_int = va_arg(args, unsigned long int);
	str = ft_itoa_base(long_int, 16, 1, &len);
	write(1, "0x", 2);
	write(1, str, len);
	*len_total = (*len_total) + len + 2;
	free(str);
}
