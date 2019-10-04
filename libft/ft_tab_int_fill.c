/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_int_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:23:37 by aschoenh          #+#    #+#             */
/*   Updated: 2018/11/08 10:07:48 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*tab_int_fill(int tab[], unsigned int size, int value)
{
	unsigned int	i;

	i = 0;
	while (i < size)
		tab[i++] = value;
	return (tab);
}
