/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-biha <fle-biha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:50:06 by fle-biha          #+#    #+#             */
/*   Updated: 2021/06/04 10:51:30 by fle-biha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_base(char *base)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (base[i] == 32 || (base[i] >= 9 && base[i] <= 13))
			return (0);
		i2 = i + 1;
		while (base[i2])
		{
			if (base[i] == base[i2])
				return (0);
			i2++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	ft_mini_atoi(char *str, char *base, int i, int base_int)
{
	int			i2;
	int			check_str;
	long int	nbr;

	i2 = 0;
	check_str = 0;
	nbr = 0;
	while (str[i])
	{
		i2 = 0;
		check_str = 0;
		while (base[i2])
		{
			if (base[i2] == str[i])
			{
				nbr = nbr * base_int + i2;
				check_str += 1;
			}
			i2++;
		}
		i++;
		if (check_str == 0)
			str[i] = 0;
	}
	return (nbr);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	base_int;

	i = 0;
	sign = 1;
	base_int = ft_check_base(base);
	if (base_int == 0)
		return (0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (ft_mini_atoi(str, base, i, base_int) * sign);
}
