/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:45:43 by aschoenh          #+#    #+#             */
/*   Updated: 2018/11/08 10:01:12 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int		myft_intlen(int n)
{
	int		i;

	i = 1;
	while (n /= 10)
		++i;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		sign;

	sign = (n < 0) ? -1 : 1;
	if (n == -2147483648)
		return (s = ft_strdup("-2147483648"));
	i = myft_intlen(n);
	if (n < 0)
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (s == NULL)
		return (NULL);
	s[i--] = '\0';
	n = n * sign;
	while (i >= 0)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	if (sign == -1)
		s[0] = '-';
	return (s);
}
