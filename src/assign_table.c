/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:59:21 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/13 12:37:37 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void			assign_table(int s[7], int options, t_file_list *lst)
{
	if ((((options / 100000000) + 3) % 5) && getpwuid(lst->st_uid) != NULL)
		s[2] = ft_max(ft_strlen(getpwuid(lst->st_uid)->pw_name), s[2]);
	else
		s[2] = ft_max(ft_get_int_len(lst->st_uid), s[2]);
	if ((((options / 100000000) + 3) % 5) && getgrgid(lst->st_gid) != NULL)
		s[3] = ft_max(ft_strlen(getgrgid(lst->st_gid)->gr_name), s[3]);
	else
		s[3] = ft_max(ft_get_int_len(lst->st_gid), s[3]);
}
