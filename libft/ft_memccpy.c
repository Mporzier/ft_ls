/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:45:28 by aschoenh          #+#    #+#             */
/*   Updated: 2018/11/06 16:09:52 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
			size_t n)
{
	size_t				i;
	unsigned char		*dest;
	unsigned char		*source;

	c = (unsigned char)c;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = -1;
	while (++i < n && n > 0)
	{
		*(dest + i) = *((unsigned char *)(source + i));
		if (*(unsigned char *)(source + i) == (unsigned char)c)
			return ((unsigned char *)dst + i + 1);
	}
	return (NULL);
}
