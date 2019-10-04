/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:59:08 by aschoenh          #+#    #+#             */
/*   Updated: 2018/11/07 17:14:03 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int			j;
	int			i;
	int			k;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	j = 0;
	k = 0;
	while (*(haystack + i) && *(needle + j))
	{
		while (*(haystack + i) == *(needle + j) && needle[j] && haystack[i])
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)haystack + (i - j));
		else
			i = ++k;
		j = 0;
	}
	return (NULL);
}
