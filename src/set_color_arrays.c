/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_arrays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 11:07:25 by mporzier          #+#    #+#             */
/*   Updated: 2019/02/13 12:40:11 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int				check_lscolors(char *lc)
{
	int i;

	i = 0;
	if (ft_strlen(lc) != 22)
		return (1);
	while (lc[i])
	{
		if (lc[i] != 'a' && lc[i] != 'b' && lc[i] != 'c' && lc[i] != 'd'
				&& lc[i] != 'e' && lc[i] != 'f' && lc[i] != 'g' && lc[i] != 'h'
				&& lc[i] != 'A' && lc[i] != 'B' && lc[i] != 'C' && lc[i] != 'D'
				&& lc[i] != 'E' && lc[i] != 'F' && lc[i] != 'G' && lc[i] != 'H'
				&& lc[i] != 'x')
			return (1);
		i++;
	}
	return (0);
}

static	void	set_colors_fg2(char fg[34])
{
	fg[1] = 30;
	fg[3] = 31;
	fg[5] = 32;
	fg[7] = 33;
	fg[9] = 34;
	fg[11] = 35;
	fg[13] = 36;
	fg[15] = 37;
	fg[17] = 90;
	fg[19] = 91;
	fg[21] = 92;
	fg[23] = 93;
	fg[25] = 94;
	fg[27] = 95;
	fg[29] = 96;
	fg[31] = 97;
	fg[33] = 39;
}

void			set_colors_fg(char fg[34])
{
	fg[0] = 'a';
	fg[2] = 'b';
	fg[4] = 'c';
	fg[6] = 'd';
	fg[8] = 'e';
	fg[10] = 'f';
	fg[12] = 'g';
	fg[14] = 'h';
	fg[16] = 'A';
	fg[18] = 'B';
	fg[20] = 'C';
	fg[22] = 'D';
	fg[24] = 'E';
	fg[26] = 'F';
	fg[28] = 'G';
	fg[30] = 'H';
	fg[32] = 'x';
	set_colors_fg2(fg);
}

static	void	set_colors_bg2(char bg[34])
{
	bg[1] = 40;
	bg[3] = 41;
	bg[5] = 42;
	bg[7] = 43;
	bg[9] = 44;
	bg[11] = 45;
	bg[13] = 46;
	bg[15] = 47;
	bg[17] = 100;
	bg[19] = 101;
	bg[21] = 102;
	bg[23] = 103;
	bg[25] = 104;
	bg[27] = 105;
	bg[29] = 106;
	bg[31] = 107;
	bg[33] = 49;
}

void			set_colors_bg(char bg[34])
{
	bg[0] = 'a';
	bg[2] = 'b';
	bg[4] = 'c';
	bg[6] = 'd';
	bg[8] = 'e';
	bg[10] = 'f';
	bg[12] = 'g';
	bg[14] = 'h';
	bg[16] = 'A';
	bg[18] = 'B';
	bg[20] = 'C';
	bg[22] = 'D';
	bg[24] = 'E';
	bg[26] = 'F';
	bg[28] = 'G';
	bg[30] = 'H';
	bg[32] = 'x';
	set_colors_bg2(bg);
}
