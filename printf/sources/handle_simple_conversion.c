/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_simple_conversion.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:39:01 by ayezhova          #+#    #+#             */
/*   Updated: 2020/02/04 13:05:13 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	handle_simple_int(va_list args, int *len_total)
{
	int		value;
	int		len;
	char	*str;

	value = va_arg(args, int);
	str = ft_itoa_base(value, 10, 1, &len);
	write(1, str, len);
	*len_total = (*len_total) + len;
	free(str);
}

static void	handle_simple_string(va_list args, int *len_total)
{
	char	*str;
	int		i;
	char	null_str[7];

	i = 0;
	str = va_arg(args, char*);
	if (str == NULL)
	{
		ft_strcpy(null_str, "(null)");
		str = null_str;
	}
	while (str[i])
		i++;
	write(1, str, i);
	*len_total = (*len_total) + i;
}

static void	handle_simple_char(va_list args, int *len)
{
	char c;

	c = va_arg(args, int);
	write(1, &c, 1);
	*len = (*len) + 1;
}

static void	handle_simple_unsigned(va_list args, int *len_total)
{
	unsigned int	value;
	int				len;
	char			*str;

	value = va_arg(args, unsigned int);
	str = ft_itoa_base(value, 10, 1, &len);
	write(1, str, len);
	*len_total = (*len_total) + len;
	free(str);
}

int			handle_simple_conversion(char c, va_list args, int *len)
{
	if (c == 'd' || c == 'i')
		handle_simple_int(args, len);
	if (c == '%')
	{
		*len = (*len) + 1;
		write(1, "%", 1);
	}
	if (c == 'u')
		handle_simple_unsigned(args, len);
	if (c == 's')
		handle_simple_string(args, len);
	if (c == 'c')
		handle_simple_char(args, len);
	if (c == 'o')
		handle_simple_oct(args, len);
	if (c == 'x' || c == 'X')
		handle_simple_hex(args, c, len);
	if (c == 'p')
		handle_simple_point(args, len);
	if (c == 'n')
		handle_num_printed(args, len);
	if (c == 'M')
		handle_m(args, len);
	return (2);
}
