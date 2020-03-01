/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 07:05:56 by ayezhova          #+#    #+#             */
/*   Updated: 2020/01/24 15:42:40 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int		ft_exp(int base, unsigned int power)
{
	long int		num;
	unsigned int	i;

	i = 0;
	num = base;
	if (power == 0)
		return (1);
	while (i < power - 1)
	{
		num *= base;
		i++;
	}
	return (num);
}
