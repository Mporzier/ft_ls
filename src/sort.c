/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:05:33 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/13 12:40:16 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void				ft_list_reverse(t_file_list **begin_list)
{
	t_file_list		*prev;
	t_file_list		*current;
	t_file_list		*next;

	next = NULL;
	prev = NULL;
	current = NULL;
	if (!begin_list || !*begin_list)
		return ;
	current = *begin_list;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*begin_list = prev;
}

t_file_list			*ft_list_sort_time(t_file_list *lst)
{
	if (!lst)
		return (NULL);
	if ((lst->next && lst->time_set < lst->next->time_set))
		lst = ft_lst_swap(lst, lst->next);
	else if (lst->next && lst->time_set == lst->next->time_set)
		if (lst->next && (lst->time < lst->next->time))
			lst = ft_lst_swap(lst, lst->next);
	lst->next = ft_list_sort_time(lst->next);
	if (lst->next && (lst->time_set < lst->next->time_set))
	{
		lst = ft_lst_swap(lst, lst->next);
		lst->next = ft_list_sort_time(lst->next);
	}
	else if (lst->next && lst->time_set == lst->next->time_set)
	{
		if (lst->next && (lst->time < lst->next->time))
		{
			lst = ft_lst_swap(lst, lst->next);
			lst->next = ft_list_sort_time(lst->next);
		}
	}
	return (lst);
}

static t_file_list	*ft_list_sort_ascii(t_file_list *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
		lst = ft_lst_swap(lst, lst->next);
	lst->next = ft_list_sort_ascii(lst->next);
	if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
	{
		lst = ft_lst_swap(lst, lst->next);
		lst->next = ft_list_sort_ascii(lst->next);
	}
	return (lst);
}

static t_file_list	*ft_pre_sort_list(t_file_list ***lst, t_file_list **lst1,
						int count)
{
	t_file_list		*lst2;
	int				i;

	lst2 = NULL;
	i = 0;
	*lst1 = **lst;
	lst2 = *lst1;
	while (*lst1 && i < count && count > 0)
	{
		if (i < count)
			*lst1 = (*lst1)->next;
		i++;
	}
	while (lst2 && --i && count > 0)
		lst2 = lst2->next;
	lst2->next = NULL;
	return (lst2);
}

void				ft_sort_list(t_file_list **lst, int options,
					int count)
{
	t_file_list		*lst1;
	t_file_list		*lst2;

	lst1 = NULL;
	if (count > 0)
		lst2 = ft_pre_sort_list(&lst, &lst1, count);
	if (count < 1)
		*lst = ft_list_sort_ascii(*lst);
	ft_sort_list2(options, lst, &lst1);
	if (((options / 10) + 3) % 5 == 0)
	{
		ft_list_reverse(lst);
		if (lst1)
			ft_list_reverse(&lst1);
	}
	if (lst1 && count > 0)
	{
		if (lst2->next)
			lst2->next->next = lst1;
		else
			lst2->next = lst1;
	}
}
