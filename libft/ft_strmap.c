/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:46:50 by aschoenh          #+#    #+#             */
/*   Updated: 2018/11/07 10:40:54 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		dst[i] = f(s[i]);
	dst[i] = '\0';
	return (dst);
}
