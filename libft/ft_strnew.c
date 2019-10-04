/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:59:53 by aschoenh          #+#    #+#             */
/*   Updated: 2018/11/07 18:18:25 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	int		i;
	char	*dst;

	i = (int)size;
	if (!(dst = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i >= 0)
		dst[i--] = '\0';
	return (dst);
}
