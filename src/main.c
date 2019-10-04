/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:14:00 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/13 12:39:17 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static int			ft_list2(char **av, int ac, int *i,
						t_file_list **begin_list)
{
	int				k;

	k = *i + 1;
	if (ac == k)
		ft_ls_get_file("", ".", begin_list);
	else
		sort_args(av, ac, k, i);
	return (k);
}

static t_file_list	*ft_ls_list_files(char **av, int ac, int *i, int options)
{
	t_file_list		*begin_list;
	char			*str;
	int				k;

	begin_list = NULL;
	k = ft_list2(av, ac, i, &begin_list) - 1;
	while (av[++k])
	{
		if (av[k][0] == '\0')
		{
			ft_ls_error(0, "fts_open", 0, NULL);
			return (NULL);
		}
		str = av[k];
		if (av[k][0] == '/' && av[k][ft_strlen(av[k]) - 1] != '/'
				&& (((options / 1000000000) + 3) % 5) != 0 && (((options /
				100000000) + 3) % 5) != 0 && (((options / 10000) + 3) % 5) != 0)
		{
			str = ft_strcat(av[k], "/");
			(*i)--;
		}
		if ((ft_ls_get_file("", str, &begin_list) == -1))
			ft_ls_error(ERRNO, av[k], 0, i);
	}
	return (begin_list);
}

int					main(int ac, char **av)
{
	int				i;
	int				options;
	int				isfile;
	int				count;
	t_file_list		*file;

	if ((i = ft_ls_parsing(ac, av, &options)) == -1)
		return (EXIT_FAILURE);
	count = i;
	if ((file = ft_ls_list_files(av, ac, &count, options)) == NULL)
		return (EXIT_FAILURE);
	if (count > 1)
	{
		ft_ls_display_files(&file, options, count - i - 1);
	}
	isfile = (!file ? 1 : 0);
	ft_ls_display(options, file, ac - i - 1, !isfile ? 2 : 1);
	ft_list_clear(&file);
	return (EXIT_SUCCESS);
}
