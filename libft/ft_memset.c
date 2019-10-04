/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:06:52 by aschoenh          #+#    #+#             */
/*   Updated: 2018/11/06 12:07:13 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	a;
	char			*str;
	size_t			i;

	a = (unsigned char)c;
	str = b;
	i = 0;
	while (i < len)
		*(str + i++) = a;
	return (b);
}
