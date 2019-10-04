/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:55:20 by aschoenh          #+#    #+#             */
/*   Updated: 2018/11/08 11:16:53 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		*big;

	big = (char *)haystack;
	if (!*needle)
		return (big);
	i = 0;
	j = 0;
	k = 0;
	while (big[i] && needle[j] && i < len)
	{
		while (big[i] == needle[j] && needle[j] && big[i] && i++ <= len)
			j++;
		if (!needle[j])
			return (&big[i - j]);
		else
		{
			k++;
			i = k;
		}
		j = 0;
	}
	return (NULL);
}
