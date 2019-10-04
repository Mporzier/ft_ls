/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:00:07 by aschoenh          #+#    #+#             */
/*   Updated: 2018/11/07 17:12:56 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	if (!n)
		return (0);
	i = 0;
	while (*(s1 + i) && (*(s1 + i) == *(s2 + i)) && i + 1 < (int)n)
		i++;
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}
