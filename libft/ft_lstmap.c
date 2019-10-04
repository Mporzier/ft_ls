/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:45:36 by aschoenh          #+#    #+#             */
/*   Updated: 2018/11/08 09:59:31 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*curr;
	t_list	*first;

	curr = ft_lstnew(NULL, 0);
	if (!curr || !lst)
		return (NULL);
	curr = f(lst);
	first = curr;
	while (lst->next)
	{
		lst = lst->next;
		curr->next = f(lst);
		if (curr->next == NULL)
		{
			free(curr->next);
			return (NULL);
		}
		curr = curr->next;
	}
	return (first);
}
