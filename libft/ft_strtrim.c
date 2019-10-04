/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:27:55 by aschoenh          #+#    #+#             */
/*   Updated: 2018/11/08 09:59:01 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		myft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*dst;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	j = len - 1;
	while (i < len && myft_isspace(s[i]))
		i++;
	while (j > 0 && myft_isspace(s[j]))
		j--;
	if (i == len || j == 0)
		return (dst = ft_strnew(1));
	if (!(dst = (char *)malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	k = 0;
	while (i <= j)
		dst[k++] = s[i++];
	dst[k] = '\0';
	return (dst);
}
