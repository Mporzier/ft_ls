/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:49:14 by aschoenh          #+#    #+#             */
/*   Updated: 2018/11/07 18:13:11 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elem;
	t_list	*tmp;

	if (alst)
	{
		elem = *alst;
		while (elem)
		{
			tmp = elem->next;
			del((elem)->content, (elem)->content_size);
			free(elem);
			elem = tmp;
		}
		*alst = NULL;
	}
}
