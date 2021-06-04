/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-biha <fle-biha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:31:53 by fle-biha          #+#    #+#             */
/*   Updated: 2021/06/03 17:22:33 by fle-biha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned int n, char *base)
{
	char				*str;
	unsigned int		i;

	i = ft_strlen(base);
	str = (char *)malloc(sizeof(char) * 2);
	if (!(str))
		ft_error_malloc();
	if (n >= i)
		str = ft_strjoin(ft_itoa_base(n / i, base), \
		ft_itoa_base(n % i, base), 0, 0);
	else if (n < i)
	{
		str[0] = base[n];
		str[1] = '\0';
	}
	return (str);
}
