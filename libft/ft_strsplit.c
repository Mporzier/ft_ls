/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:34:19 by aschoenh          #+#    #+#             */
/*   Updated: 2018/11/08 13:27:31 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		**ft_myfiller(char const *s, char c, char **dst, int words)
{
	char	*ptr;
	int		i;
	int		j;

	i = -1;
	while (*s && ++i < words)
	{
		while (*s == c && *s)
			s++;
		ptr = (char *)s;
		j = 0;
		while (*s && *s != c && ++j)
			s++;
		dst[i] = ft_strnew(j + 1);
		dst[i][j] = '\0';
		while (j-- > 0)
			dst[i][j] = *(ptr + j);
	}
	return (dst);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dst;
	int		words;

	if (s == NULL)
		return (NULL);
	words = ft_countwordssep((char *)s, c, c, c);
	if (!(dst = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	dst[words] = NULL;
	return (dst = ft_myfiller(s, c, dst, words));
}
