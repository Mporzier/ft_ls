/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:32:02 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/13 12:48:06 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static int			get_col_s(t_file_list *lst, int s[7], int options,
						int total_blocks)
{
	int	len;

	init_tab(s, &len, &total_blocks);
	while (lst)
	{
		s[0] = ft_max(ft_get_int_len(lst->st_blocks), s[0]);
		s[1] = ft_max(ft_get_int_len(lst->st_nlink), s[1]);
		assign_table(s, options, lst);
		if (!S_ISCHR(lst->st_mode))
			len = ft_get_int_len(lst->st_size);
		else
		{
			s[5] = ft_max(ft_get_int_len(major(lst->st_rdev)), s[5]);
			s[6] = ft_max(ft_get_int_len(minor(lst->st_rdev)), s[6]);
			len = (s[5] + s[6] + 2);
		}
		s[4] = ft_max(len, s[4]);
		total_blocks += lst->st_blocks;
		lst = lst->next;
	}
	s[5] = ft_max(s[4] - s[6] - 1, s[5]);
	return (total_blocks);
}

static void			display_simple_name(t_file_list *lst, int options,
						int s_b)
{
	char			chmod[12];

	if ((((options / 100000) + 3) % 5) == 0)
		ft_printf("%*hu ", s_b, lst->st_blocks);
	get_chmod(lst, chmod, lst->path);
	change_color(chmod);
	ft_printf("%s", lst->name);
	if (!(lst->next) || ((options / 1000000000) + 3) % 5)
		ft_putstr("\033[0m\n");
	else
		ft_putstr("\033[0m, ");
}

static void			display_simple_list(t_file_list *lst, int count,
						int options, int *isfirst)
{
	int				i;
	int				blocks;
	int				tab[7];
	int				s_b;

	i = 0;
	s_b = 0;
	blocks = get_col_s(lst, tab, options, 0);
	while (lst && i++ != count)
	{
		if ((((options / 100000) + 3) % 5) == 0)
			s_b = ft_max(ft_get_int_len(lst->st_blocks), s_b);
		if (i + 1 > count)
			(*isfirst)++;
		if ((*isfirst)++ == 1 && i != count && !(((options / 100000) + 3) % 5))
			ft_printf("total %d\n", blocks);
		if ((!(ft_strcmp(lst->name, ".")) && (lst->path[ft_strlen(lst->path)
			- 1] == '.' && lst->path[ft_strlen(lst->path) - 2] == '/'))
				|| (ft_strcmp(lst->name, ".")))
			display_simple_name(lst, options, s_b);
		lst = lst->next;
	}
	if (lst && count)
		ft_putchar('\n');
}

static void			display_l_list(t_file_list *lst, int options,
						int count, int *isfirst)
{
	int				s[7];
	int				total_blocks;
	int				i;

	i = 7;
	while (i >= 0)
		s[i--] = 0;
	total_blocks = get_col_s(lst, s, options, 0);
	i = 0;
	while (lst && i != count)
	{
		if (i + 1 > count)
			(*isfirst)++;
		if (*isfirst == 1 && i != count)
		{
			ft_printf("total %d\n", total_blocks);
		}
		display_ls_lx(lst, s, options);
		ft_putchar('\n');
		lst = lst->next;
		i++;
	}
	if (lst && count)
		ft_putchar('\n');
}

void				ft_ls_display_files(t_file_list **lst, int options,
						int count)
{
	int			isfirst;

	isfirst = 0;
	ft_sort_list(lst, options, count);
	if (((((options / 10000) + 3) % 5 != 0
			&& ((options / 100000000) + 3) % 5 != 0))
				&& (((options / 10000000) + 3) % 5) != 0)
	{
		display_simple_list(*lst, count, options, &isfirst);
	}
	else if ((((options / 1000000000) + 3) % 5) == 0
			&& (((options / 10000000) + 3) % 5) != 0)
	{
		display_simple_list(*lst, count, options, &isfirst);
	}
	else
		display_l_list(*lst, options, count, &isfirst);
}
