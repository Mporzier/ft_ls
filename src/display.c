/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:23:58 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/13 12:38:11 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static t_file_list	*read_directory(char path[PATH_MAX], char file[NAME_MAX + 1]
					, int options)
{
	DIR				*dir;
	struct dirent	*struc;
	t_file_list		*new;

	new = NULL;
	if (!(dir = opendir(path)))
	{
		ft_ls_error(ERRNO, file, 0, NULL);
		return (NULL);
	}
	else
	{
		while ((struc = readdir(dir)))
		{
			if (!struc)
				return (NULL);
			if ((((((options) / 100) + 3) % 5) == 0) ||
					struc->d_name[0] != '.')
				ft_ls_get_file(path, struc->d_name, &new);
		}
	}
	if (dir)
		closedir(dir);
	return (new);
}

static void			display_path(char *path, int ac, int *isfirst)
{
	if (ac != 0 && ac != 1)
	{
		if (*isfirst == 2)
		{
			ft_printf("%s:\n", path);
			*isfirst = 1;
		}
		else
			ft_printf("\n%s:\n", path);
	}
}

void				ft_ls_display(int options, t_file_list *file,
		int ac, int isfirst)
{
	t_file_list		*lst;

	lst = file;
	if ((((options / 1000) + 3) % 5) != 0 && isfirst == 0)
		return ;
	else
	{
		while (lst)
		{
			if ((S_ISDIR(lst->st_mode)) && (isfirst ||
				ft_strcmp(lst->name, ".")) && ft_strcmp(lst->name, ".."))
			{
				display_path(lst->path, ac, &isfirst);
				if ((file = read_directory(lst->path, lst->name, options)))
				{
					ft_ls_display_files(&file, options, -1);
					ft_ls_display(options, file, -1, 0);
					ft_list_clear(&file);
				}
			}
			lst = lst->next;
		}
	}
}
