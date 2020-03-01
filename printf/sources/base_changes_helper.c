/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_changes_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:44:05 by ayezhova          #+#    #+#             */
/*   Updated: 2020/02/04 13:03:54 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		alt_num_u(t_flags *flags, int *sign, uintmax_t ret)
{
	(*sign) = 0;
	if (ret == 0)
		return (0);
	if (flags->conversion_flags[4] == 1)
	{
		if (flags->conversion_specifier == 'o')
		{
			(*sign) = (*sign) + 1;
			return (-1);
		}
		if (flags->conversion_specifier == 'x')
		{
			(*sign) = (*sign) + 2;
			return (-2);
		}
		if (flags->conversion_specifier == 'X')
		{
			(*sign) = (*sign) + 2;
			return (-2);
		}
	}
	return (0);
}

void	get_zeros_u(t_flags *flags, int *zeros, int *spaces, int digits)
{
	if (flags->conversion_flags[1] == 1 && flags->conversion_flags[0] == 0
		&& flags->precision == -1)
	{
		(*zeros) = *spaces;
		(*spaces) = 0;
	}
	else
		(*zeros) += flags->precision - digits;
}

void	check_if_digits_zero(int *digits, int ret, t_flags *f)
{
	if (ret == 0 && f->precision == 0 && !(f->conversion_specifier == 'o'
				&& f->conversion_flags[4] == 1))
		(*digits) = 0;
}
