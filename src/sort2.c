/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:21:23 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/13 12:40:20 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static void		ft_swap(char **s1, char **s2)
{
	void		*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

t_file_list		*ft_sort_size(t_file_list *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && lst->st_size < lst->next->st_size)
		lst = ft_lst_swap(lst, lst->next);
	lst->next = ft_sort_size(lst->next);
	if (lst->next && lst->st_size < lst->next->st_size)
	{
		lst = ft_lst_swap(lst, lst->next);
		lst->next = ft_sort_size(lst->next);
	}
	return (lst);
}

static int		sort_types(char **av, int ac, int beg)
{
	int			i;
	int			k;
	struct stat st[ac];

	i = beg - 1;
	while (++i < ac)
		lstat(av[i], &st[i]);
	i = beg;
	while (!(S_ISDIR(st[i].st_mode)) && av[i])
		i++;
	k = i;
	while (++i < ac)
		if (!(S_ISDIR(st[i].st_mode)) && i != k)
			ft_swap(&av[i], &av[k++]);
	i = beg;
	while (i < ac)
	{
		lstat(av[i], &st[i]);
		sort_types2(ac, st, i, av);
		if (!(S_ISDIR(st[i].st_mode)))
			i++;
		else
			break ;
	}
	return (i);
}

t_file_list		*ft_list_sort_block(t_file_list *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && lst->st_blocks > lst->next->st_blocks)
		lst = ft_lst_swap(lst, lst->next);
	else if (lst->next && lst->st_blocks == lst->next->st_blocks)
		if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
			lst = ft_lst_swap(lst, lst->next);
	lst->next = ft_list_sort_block(lst->next);
	if (lst->next && lst->st_blocks > lst->next->st_blocks)
	{
		lst = ft_lst_swap(lst, lst->next);
		lst->next = ft_list_sort_block(lst->next);
	}
	else if (lst->next && lst->st_blocks == lst->next->st_blocks)
	{
		if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
		{
			lst = ft_lst_swap(lst, lst->next);
			lst->next = ft_list_sort_block(lst->next);
		}
	}
	return (lst);
}

int				sort_args(char **av, int ac, int i, int *count)
{
	*count = sort_types(av, ac, i);
	while (i < *count - 1)
	{
		if (ft_strcmp(av[i], av[i + 1]) > 0)
		{
			ft_swap(&av[i], &av[i + 1]);
			i = 1;
		}
		else
			i++;
	}
	i = *count;
	while (i + 1 < ac)
	{
		if (ft_strcmp(av[i], av[i + 1]) > 0)
		{
			ft_swap(&av[i], &av[i + 1]);
			i = *count;
		}
		else
			i++;
	}
	return (*count);
}
