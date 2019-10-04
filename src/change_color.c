/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:02:01 by mporzier          #+#    #+#             */
/*   Updated: 2019/02/13 12:48:57 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void			get_chmod(t_file_list *file, char chmod[12],
		char path[PATH_MAX])
{
	chmod[0] = get_file_type(file->st_mode);
	chmod[1] = (S_IRUSR & file->st_mode) ? 'r' : '-';
	chmod[2] = (S_IWUSR & file->st_mode) ? 'w' : '-';
	chmod[3] = (S_IXUSR & file->st_mode) ? 'x' : '-';
	chmod[4] = (S_IRGRP & file->st_mode) ? 'r' : '-';
	chmod[5] = (S_IWGRP & file->st_mode) ? 'w' : '-';
	chmod[6] = (S_IXGRP & file->st_mode) ? 'x' : '-';
	chmod[7] = (S_IROTH & file->st_mode) ? 'r' : '-';
	chmod[8] = (S_IWOTH & file->st_mode) ? 'w' : '-';
	chmod[9] = (S_IXOTH & file->st_mode) ? 'x' : '-';
	chmod[10] = get_acl(path);
	chmod[11] = '\0';
	if (S_ISUID & file->st_mode)
		chmod[3] = chmod[3] == '-' ? 'S' : 's';
	if (S_ISGID & file->st_mode)
		chmod[6] = chmod[6] == '-' ? 'S' : 's';
	if (S_ISVTX & file->st_mode)
		chmod[9] = chmod[9] == '-' ? 'T' : 't';
}

static	char	*get_lscolors(void)
{
	extern	char	**environ;
	int				i;

	i = 0;
	while (environ[i])
	{
		if (environ[i][0] == 'L' && environ[i][1] == 'S'
				&& environ[i][2] == 'C' && environ[i][3] == 'O'
				&& environ[i][4] == 'L' && environ[i][5] == 'O'
				&& environ[i][6] == 'R' && environ[i][7] == 'S'
				&& environ[i][8] == '=')
			break ;
		i++;
	}
	if (!environ[i])
		return (NULL);
	return (environ[i] + 9);
}

static	int		change_color3(char chmod[12], char fg[34], char bg[34],
		char *lc)
{
	if (chmod[8] == 'w' && chmod[9] == 't' && chmod[0] == 'd')
	{
		return (ft_printf("\033[%d;%dm", *(ft_strchr(fg, lc[18]) + 1),
					*(ft_strchr(bg, lc[19]) + 1)));
	}
	if (chmod[8] == 'w' && chmod[0] == 'd')
	{
		return (ft_printf("\033[%d;%dm", *(ft_strchr(fg, lc[20]) + 1),
					*(ft_strchr(bg, lc[21]) + 1)));
	}
	if (chmod[0] == 'd')
	{
		return (ft_printf("\033[%d;%dm", *(ft_strchr(fg, lc[0]) + 1),
					*(ft_strchr(bg, lc[1]) + 1)));
	}
	if (chmod[3] == 'x' || chmod[6] == 'x' || chmod[9] == 'x')
	{
		return (ft_printf("\033[%d;%dm", *(ft_strchr(fg, lc[8]) + 1),
					*(ft_strchr(bg, lc[9]) + 1)));
	}
	return (0);
}

static	int		change_color2(char chmod[12], char fg[34], char bg[34],
		char *lc)
{
	if (chmod[0] == 'b')
	{
		return (ft_printf("\033[%d;%dm", *(ft_strchr(fg, lc[10]) + 1),
					*(ft_strchr(bg, lc[11]) + 1)));
	}
	if (chmod[0] == 'c')
	{
		return (ft_printf("\033[%d;%dm", *(ft_strchr(fg, lc[12]) + 1),
					*(ft_strchr(bg, lc[13]) + 1)));
	}
	if (chmod[3] == 's')
	{
		return (ft_printf("\033[%d;%dm", *(ft_strchr(fg, lc[14]) + 1),
					*(ft_strchr(bg, lc[15]) + 1)));
	}
	if (chmod[6] == 's')
	{
		return (ft_printf("\033[%d;%dm", *(ft_strchr(fg, lc[16]) + 1),
					*(ft_strchr(bg, lc[17]) + 1)));
	}
	return (change_color3(chmod, fg, bg, lc));
}

int				change_color(char chmod[12])
{
	char	*lc;
	char	fg[34];
	char	bg[34];

	set_colors_fg(fg);
	set_colors_bg(bg);
	if (!(lc = get_lscolors()) || (check_lscolors(lc) == 1))
		return (0);
	if (chmod[0] == 'l')
	{
		return (ft_printf("\033[%d;%dm", *(ft_strchr(fg, lc[2]) + 1),
					*(ft_strchr(bg, lc[3]) + 1)));
	}
	if (chmod[0] == 's')
	{
		return (ft_printf("\033[%d;%dm", *(ft_strchr(fg, lc[4]) + 1),
					*(ft_strchr(bg, lc[5]) + 1)));
	}
	if (chmod[0] == 'p')
	{
		return (ft_printf("\033[%d;%dm", *(ft_strchr(fg, lc[6]) + 1),
					*(ft_strchr(bg, lc[7]) + 1)));
	}
	return (change_color2(chmod, fg, bg, lc));
}
