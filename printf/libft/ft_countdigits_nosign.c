/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits_nosign.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:39:18 by ayezhova          #+#    #+#             */
/*   Updated: 2020/01/20 14:44:41 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countdigits_nosign(intmax_t n, int precision)
{
	int count;

	count = 0;
	if (n == 0 && precision != 0)
		return (1);
	if (n == 0 && precision == 0)
		return (0);
	if (n == -9223372036854775807 - 1)
		return (19);
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
