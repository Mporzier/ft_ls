/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:36:55 by rmarracc          #+#    #+#             */
/*   Updated: 2018/12/07 13:35:13 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

int			ft_process_arg(const char *fmt, t_arg *flag, int i,
	va_list ap)
{
	while (fmt[i])
	{
		if (ft_is_arg1(fmt[i]))
			ft_parse_options(fmt[i], flag);
		else if (ft_isdigit(fmt[i]))
		{
			flag->width = ft_atoi(&fmt[i]);
			i = ft_skip_digit(fmt, i);
		}
		else if (fmt[i] == '*')
		{
			flag->width = va_arg(ap, int);
			if (flag->width < 0)
				flag->minus = 1;
			flag->width = (flag->width < 0) ? -flag->width : flag->width;
		}
		else if (fmt[i] == '.')
			i = ft_parse_precision(fmt, flag, i, ap);
		else if (fmt[i] == 'h' || fmt[i] == 'l' || fmt[i] == 'L')
			i = ft_parse_lenght(fmt, flag, i);
		else
			return (i - 1);
		i++;
	}
	return (i - 1);
}

void		ft_parse_options(char c, t_arg *flag)
{
	if (c == '-')
		flag->minus = 1;
	else if (c == '+')
		flag->plus = 1;
	else if (c == '#')
		flag->diese = 1;
	else if (c == '0')
		flag->zero = 1;
	else if (c == ' ')
		flag->espace = 1;
}

int			ft_parse_precision(const char *fmt, t_arg *flag, int i,
	va_list ap)
{
	if (fmt[i + 1] == '*')
	{
		flag->precision = va_arg(ap, int);
		if (flag->precision < 0)
			flag->precision = -1;
		return (i + 1);
	}
	if (!ft_isdigit(fmt[i + 1]))
	{
		flag->precision = -5;
		return (i);
	}
	while (fmt[i] == '.')
		i++;
	flag->precision = ft_atoi(&fmt[i]);
	i = ft_skip_digit(fmt, i);
	return (i);
}

int			ft_parse_lenght(const char *fmt, t_arg *flag, int i)
{
	if (fmt[i] == 'h')
	{
		if (fmt[i + 1] == 'h')
		{
			i++;
			flag->lenght = -2;
		}
		else
			flag->lenght = -1;
	}
	else if (fmt[i] == 'l')
	{
		if (fmt[i + 1] == 'l')
		{
			i++;
			flag->lenght = 2;
		}
		else
			flag->lenght = 1;
	}
	else if (fmt[i] == 'L')
		flag->lenght = 3;
	return (i);
}
