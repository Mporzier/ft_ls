/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwordssep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:49:02 by aschoenh          #+#    #+#             */
/*   Updated: 2018/11/08 11:58:04 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwordssep(char *s, char a, char b, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (s[i] && (s[i] != a) && s[i] != b && s[i] != c
			&& s[i + 1] != a && s[i + 1] != b && s[i + 1] != c
			&& s[i + 1] != 0)
		count++;
	while (s[i])
	{
		if ((s[i] == a) && s[i] == b && s[i] == c
				&& s[i + 1] != a && s[i + 1] != b && s[i + 1] != c
				&& s[i + 1] != 0)
			count++;
		i++;
	}
	return (count);
}
