/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:45:01 by ayezhova          #+#    #+#             */
/*   Updated: 2020/02/04 13:04:02 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_cover_flags(char *str, t_flags *flags, int i)
{
	int		j;
	char	c;

	j = 0;
	c = str[i];
	j = 0;
	while (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#')
	{
		if (c == '-')
			flags->conversion_flags[0] = 1;
		if (c == '0')
			flags->conversion_flags[1] = 1;
		if (c == '+')
			flags->conversion_flags[2] = 1;
		if (c == ' ')
			flags->conversion_flags[3] = 1;
		if (c == '#')
			flags->conversion_flags[4] = 1;
		c = str[i + ++j];
	}
	return (j);
}

int	check_field_width(char *str, t_flags *flags, int i, va_list list)
{
	int		width;
	int		j;

	j = 0;
	width = 0;
	if (str[i + j] == '*')
	{
		width = va_arg(list, int);
		j++;
	}
	else
	{
		while (str[i + j] >= '0' && str[i + j] <= '9')
		{
			width *= 10;
			width += (int)str[i + j] - '0';
			j++;
		}
	}
	flags->field_width = width;
	return (j);
}

int	check_precision(char *str, t_flags *flags, int i, va_list list)
{
	int		precision;
	int		j;

	j = 0;
	precision = -1;
	if (str[i + j] == '.')
	{
		precision = 0;
		j++;
		if (str[i + j] == '*')
		{
			precision = va_arg(list, int);
			j++;
		}
		else
		{
			while (str[i + j] >= '0' && str[i + j] <= '9')
			{
				precision *= 10;
				precision += (int)str[i + j++] - '0';
			}
		}
	}
	flags->precision = precision;
	return (j);
}

int	check_alt_specifier(char *str, t_flags *flags, int i)
{
	int		j;
	char	c;

	j = 0;
	c = str[i];
	if (c == 'l' || c == 'L' || c == 'h' || c == 'z' || c == 'j')
	{
		flags->alt_coversion_specifier = c;
		j++;
	}
	if (c == 'l' && str[i + 1] == 'l')
	{
		flags->alt_coversion_specifier = 'd';
		j++;
	}
	if (c == 'h' && str[i + 1] == 'h')
	{
		flags->alt_coversion_specifier = 'H';
		j++;
	}
	return (j);
}

int	find_specifier(char *str, t_flags *flags, int i)
{
	char	c;

	c = str[i];
	if (c == 'd' || c == 'i')
		flags->conversion_specifier = 'd';
	else if (c == 'b' || c == 'x' || c == 'X' || c == 'u' || c == 'o' ||
			c == '%' || c == 'p' || c == 's' || c == 'f' || c == 'c' ||
			c == 't')
		flags->conversion_specifier = c;
	else
		return (0);
	return (1);
}
