/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:10:22 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/13 12:40:07 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int				ft_ls_parsing(int ac, char **av, int *options)
{
	int			ret;
	int			i;
	int			k;

	ret = 9000000;
	*options = 0;
	i = 1;
	k = 1;
	while (k < ac && av[k][0] == '-' && av[k][1] != '\0')
	{
		if (av[k][1] == '-' && !av[k][2])
			return (k);
		if (av[k][1] == '-' && av[k][2])
			return (ft_ls_error(USAGE, av[k], 1, NULL));
		while (av[k][i])
		{
			ret += ft_ls_parse_options(av[k][i], options);
			if (ret % 2 != 0)
				return (ft_ls_error(USAGE, av[k], i, NULL));
			i++;
		}
		i = 1;
		k++;
	}
	return (k - 1);
}

static	void	ft_ls_parse_options2(char flag, int *options)
{
	if (flag == 'm' && (((*options / 1000000000) + 3) % 5) != 0)
		*options += 2000000000;
	else if (flag == 'n' && (((*options / 100000000) + 3) % 5) != 0)
		*options += 200000000;
	else if (flag == 'g' && (((*options / 10000000) + 3) % 5) != 0)
		*options += 20000000;
	else if (flag == 'S' && (((*options / 1000000) + 3) % 5) != 0)
		*options += 2000000;
	else if (flag == 's' && (((*options / 100000) + 3) % 5) != 0)
		*options += 200000;
	else if (flag == 'l' && (((*options / 10000) + 3) % 5) != 0)
		*options += 20000;
	else if (flag == 'R' && (((*options / 1000) + 3) % 5) != 0)
		*options += 2000;
	else if (flag == 'a' && (((*options / 100) + 3) % 5) != 0)
		*options += 200;
	else if (flag == 'r' && (((*options / 10) + 3) % 5) != 0)
		*options += 20;
	else if (flag == 't' && (((*options / 1) + 3) % 5) != 0)
		*options += 2;
}

int				ft_ls_parse_options(char flag, int *options)
{
	if (flag == 'l' || flag == 'R' || flag == 'a'
			|| flag == 'r' || flag == 's' || flag == 'S' || flag == '1'
			|| flag == 't' || flag == 'm' || flag == 'n' || flag == 'g')
	{
		ft_ls_parse_options2(flag, options);
		if (flag == '1')
		{
			(((((*options) / 1000000000) + 3) % 5) == 0) ?
				*options -= 2000000000 : *options;
			(((((*options) / 10000) + 3) % 5) == 0) ?
				*options -= 20000 : *options;
			(((((*options) / 10000000) + 3) % 5) == 0) ?
				*options -= 20000000 : *options;
		}
	}
	else
		return (-1);
	return (0);
}

int				ft_ls_error(int error, char *str, int index, int *i)
{
	if (error == USAGE)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(str[index], 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage: ft_ls [-algnRrsSt1] [file ...]", 2);
	}
	if (error == ERRNO)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	if (i != NULL)
		(*i)--;
	if (error == USAGE || error == MALL_ERR)
		exit(EXIT_FAILURE);
	return (0);
}
