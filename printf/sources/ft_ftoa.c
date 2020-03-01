/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:01:53 by ayezhova          #+#    #+#             */
/*   Updated: 2020/02/04 13:04:45 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			count_digits(long int n, int base)
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

static char			*ft_itoa_base_f(long int num, int base, int lower, int *len)
{
	char	*str;
	int		i;
	char	*possib;

	if (lower == 1)
		possib = ft_strdup("0123456789abcdef");
	else
		possib = ft_strdup("0123456789ABCDEF");
	i = -1;
	*len = count_digits(num, base);
	if (!(str = (char*)malloc((sizeof(*str) * *len + 1))))
		return (NULL);
	str[*len] = '\0';
	while (++i < *len)
	{
		str[*len - 1 - i] = possib[num % base];
		num = num / base;
	}
	free(possib);
	return (str);
}

static char			*ft_fstrform(char *num, int *int_len, int length,
		int precis)
{
	char	*str;
	int		str_len;
	int		i;
	int		j;
	int		zeros;

	i = 0;
	j = 0;
	str_len = ft_max(*int_len, 1) + precis + 2;
	if (!(str = (char*)malloc((sizeof(*str) * str_len))))
		return (NULL);
	while (i < *int_len)
		str[i++] = num[j++];
	set_int_zero(int_len, str, &i);
	str[i++] = '.';
	zeros = precis - length;
	while (zeros >= 0)
		str[i + zeros--] = '0';
	i += ft_max(precis - length, 0);
	while (num[j])
		str[i++] = num[j++];
	str[str_len] = '\0';
	free(num);
	return (str);
}

static uintmax_t	round_f(long double num, int neg)
{
	uintmax_t non_decimal;

	non_decimal = (uintmax_t)num;
	num = num - non_decimal;
	if (neg == 1)
	{
		if (num <= .5)
			return (non_decimal);
		else
			return (non_decimal + 1);
	}
	if (num <= .5)
		return (non_decimal);
	else
		return (non_decimal + 1);
}

char				*ft_ftoa(long double num, int lengths[2], int neg,
		int precision)
{
	char	*str;
	int		length;

	(lengths[0]) = ft_countdigits_nosign((long int)num, 1);
	if ((long int)num == 0)
		(lengths[0]) = 0;
	else
		(lengths[0]) = ft_countdigits_nosign((long int)num, 1);
	(lengths[1]) = precision;
	num = round_f(num * ft_exp(10, precision), neg);
	str = ft_itoa_base_f(num, 10, 0, &length);
	str = ft_fstrform(str, &lengths[0], length, precision);
	return (str);
}
