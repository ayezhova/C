/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstoccur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:00:50 by ayezhova          #+#    #+#             */
/*   Updated: 2019/11/18 15:00:57 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		firstoccur(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}