/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:05:31 by aschoenh          #+#    #+#             */
/*   Updated: 2018/11/06 12:05:33 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dst;
	i = -1;
	if (s > d)
	{
		while ((int)++i < (int)len)
			*(d + i) = *(s + i);
	}
	else if (s < d)
	{
		while ((int)--len >= 0)
			*(d + len) = *(s + len);
	}
	return (dst);
}
