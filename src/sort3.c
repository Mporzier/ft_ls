/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:24:51 by mporzier          #+#    #+#             */
/*   Updated: 2019/02/13 12:40:24 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	ft_sort_list2(int options, t_file_list **lst,
			t_file_list **lst1)
{
	if ((options + 3) % 5 == 0)
	{
		*lst = ft_list_sort_time(*lst);
		if (lst1)
			*lst1 = ft_list_sort_time(*lst1);
	}
	if (((options / 1000000) + 3) % 5 == 0)
	{
		*lst = ft_sort_size(*lst);
		if (lst1)
			*lst1 = ft_sort_size(*lst1);
	}
}

void	sort_types2(int ac, struct stat st[ac], int i, char **av)
{
	if (S_ISLNK(st[i].st_mode))
	{
		lstat(av[i], &st[i]);
	}
}
