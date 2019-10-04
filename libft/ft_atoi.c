/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:46:05 by aschoenh          #+#    #+#             */
/*   Updated: 2018/11/07 18:09:25 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char					*s;
	unsigned long long int	i;
	int						neg;
	unsigned long long int	rep;

	s = (char *)str;
	i = 0;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == '\r' || s[i] == '\v'
			|| s[i] == '\f' || s[i] == ' ')
		i++;
	neg = 1;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			neg = -1;
	rep = 0;
	while (s[i] >= '0' && s[i] <= '9' && s[i])
	{
		rep = 10 * rep + (s[i++] - '0');
		if (rep > 9223372036854775807)
			return ((neg == -1) ? (int)0 : (int)-1);
	}
	return ((int)rep * (int)neg);
}
