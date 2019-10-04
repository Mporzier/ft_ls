/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:01:14 by aschoenh          #+#    #+#             */
/*   Updated: 2018/11/07 13:16:32 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	lendst;
	size_t	lensrc;

	lendst = (ft_strlen(dst) > dstsize) ? dstsize : ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (lendst == dstsize)
		return (dstsize + lensrc);
	if (lensrc < dstsize - lendst)
		ft_strncat(dst, src, dstsize + 1);
	else
	{
		ft_strncat(dst, src, dstsize - lendst - 1);
		*(dst + dstsize - 1) = '\0';
	}
	return (lendst + lensrc);
}
