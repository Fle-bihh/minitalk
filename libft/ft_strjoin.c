/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-biha <fle-biha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:14:10 by fle-biha          #+#    #+#             */
/*   Updated: 2021/06/03 16:07:16 by fle-biha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int free1, int free2)
{
	char	*new_s;
	size_t	len_s;
	int		i_s;
	int		i_s2;

	len_s = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_s = (char *)malloc(sizeof(char) * len_s);
	if (!(new_s))
		ft_error_malloc();
	i_s = -1;
	while (s1[++i_s])
		new_s[i_s] = s1[i_s];
	i_s2 = -1;
	while (s2[++i_s2])
		new_s[i_s++] = s2[i_s2];
	new_s[i_s] = 0;
	if (free1)
		free(s1);
	if (free2)
		free(s2);
	return (new_s);
}
