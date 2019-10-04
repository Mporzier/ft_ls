/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:01:01 by aschoenh          #+#    #+#             */
/*   Updated: 2018/11/07 10:41:19 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	int		i;

	if (s == NULL)
		return (NULL);
	dst = ft_strnew(ft_strlen(s));
	if (dst == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		dst[i] = f(i, s[i]);
	dst[i] = '\0';
	return (dst);
}
