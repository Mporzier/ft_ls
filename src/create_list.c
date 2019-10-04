/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:02:30 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/13 12:38:07 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static int			ft_ls_get_path(char path[PATH_MAX], char file[NAME_MAX + 1],
										char elempath[PATH_MAX])
{
	int				i;
	int				j;

	i = -1;
	j = -1;
	while (path[++i])
		elempath[i] = path[i];
	if (i && i < PATH_MAX)
		if (!(path[0] == '/' && path[1] == '\0'))
			elempath[i++] = '/';
	while (file[++j] && i < PATH_MAX)
		elempath[i++] = file[j];
	if (i < PATH_MAX)
		elempath[i] = '\0';
	else
		errno = ENAMETOOLONG;
	if (i < PATH_MAX)
		return (1);
	return (0);
}

static t_file_list	*get_file(char *file, char *path, struct stat *stat)
{
	t_file_list		*elem;
	int				i;

	if (!(elem = (t_file_list*)ft_memalloc(sizeof(t_file_list))))
		ft_ls_error(2, NULL, 0, NULL);
	i = -1;
	while (file[++i])
		elem->name[i] = file[i];
	elem->st_nlink = stat->st_nlink;
	elem->st_uid = stat->st_uid;
	elem->st_gid = stat->st_gid;
	elem->st_mode = stat->st_mode;
	elem->st_size = stat->st_size;
	elem->st_rdev = stat->st_rdev;
	elem->time = stat->st_mtimespec.tv_sec;
	elem->st_blocks = stat->st_blocks;
	ft_ls_get_path(path, file, elem->path);
	elem->next = NULL;
	return (elem);
}

int					is_link(mode_t type)
{
	if (S_ISLNK(type))
		return (1);
	return (0);
}

int					ft_ls_get_file(char path[PATH_MAX], char file[NAME_MAX + 1],
										t_file_list **lst)
{
	char			elempath[PATH_MAX];
	struct stat		info;
	int				i;
	t_file_list		*lst2;

	lst2 = *lst;
	i = 0;
	if (!(ft_ls_get_path(path, file, elempath)))
	{
		ft_ls_error(1, file, 0, NULL);
		return (-1);
	}
	if ((lstat(elempath, &info) == -1))
		return (-1);
	if (!*lst)
		*lst = get_file(file, path, &info);
	else
	{
		while ((*lst)->next)
			lst = &((*lst)->next);
		(*lst)->next = get_file(file, path, &info);
	}
	return (1);
}
