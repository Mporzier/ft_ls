/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:48:29 by aschoenh          #+#    #+#             */
/*   Updated: 2018/11/08 10:46:48 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*dst;
	unsigned int		i;

	if (s == NULL || s[start] == '\0')
		return (NULL);
	if (len == 0)
	{
		dst = ft_strnew(0);
		return (dst);
	}
	if (start + (unsigned int)len > ft_strlen(s))
		return (NULL);
	if (!(dst = ft_strnew(sizeof(char) * len)))
		return (NULL);
	i = -1;
	while (++i < (unsigned int)len && s[start + i])
		dst[i] = s[start + i];
	dst[i] = '\0';
	return (ft_strdup(dst));
}
