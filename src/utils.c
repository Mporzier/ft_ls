/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:25:31 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/13 12:40:40 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/ft_ls.h>

int				ft_max(int a, int b)
{
	return (a > b ? a : b);
}

void			ft_list_clear(t_file_list **begin_list)
{
	t_file_list	*temp;
	t_file_list	*new_list;

	if (!*begin_list)
		return ;
	new_list = *begin_list;
	while (new_list)
	{
		temp = new_list->next;
		free(new_list);
		new_list = temp;
	}
	*begin_list = NULL;
}

int				ft_list_longest_name(t_file_list **lst)
{
	int			len;

	len = 0;
	while (*lst)
	{
		len = ft_max(ft_strlen((*lst)->name), len);
		*lst = (*lst)->next;
	}
	return (len);
}

t_file_list		*ft_lst_swap(t_file_list *file1, t_file_list *file2)
{
	file1->next = file2->next;
	file2->next = file1;
	return (file2);
}

int				ft_get_int_len(int n)
{
	int			rep;

	rep = 1;
	while (n / 10)
	{
		n /= 10;
		rep++;
	}
	return (rep);
}
