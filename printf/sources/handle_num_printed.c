/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_num_printed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:52:03 by ayezhova          #+#    #+#             */
/*   Updated: 2020/02/04 13:04:57 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_num_printed(va_list args, int *len_total)
{
	signed int *x;

	x = (int *)va_arg(args, unsigned long int);
	(*x) = (*len_total);
}

void	handle_m(va_list args, int *len_total)
{
	unsigned int fortune;

	fortune = (unsigned)va_arg(args, int);
	if (fortune == 42)
	{
		write(1, "You're basic and you'll always be basic.\n", 41);
		(*len_total) += 41;
		return ;
	}
	if (fortune % 3 == 0)
	{
		write(1, "Bad Luck! A dog is going to pee on your leg!\n", 45);
		(*len_total) += 45;
	}
	if (fortune % 3 == 1)
	{
		write(1, "Bad Luck! The wind is going to ruin your hair cut.\n", 51);
		(*len_total) += 51;
	}
	if (fortune % 3 == 2)
	{
		write(1, "Best Luck! You're going to find candy on the floor!\n", 52);
		(*len_total) += 52;
	}
}
