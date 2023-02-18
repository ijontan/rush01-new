/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vantage_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:22:02 by itan              #+#    #+#             */
/*   Updated: 2023/02/19 02:46:36 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	vc_top(int **table, int j, int size)
{
	int	val;
	int	hold;
	int	i;

	i = 0;
	hold = 0;
	val = 0;
	while (++i < size + 1)
	{
		if (hold < table[i][j])
		{
			hold = table[i][j];
			val++;
		}
	}
	if (val > table[0][j])
		return (-1);
	return (val == table[0][j]);
}

int	vc_bot(int **table, int j, int size)
{
	int	val;
	int	hold;
	int	i;

	i = size + 1;
	hold = 0;
	val = 0;
	while (--i > 0)
	{
		if (hold < table[i][j])
		{
			hold = table[i][j];
			val++;
		}
	}
	if (val > table[size + 1][j])
		return (-1);
	return (val == table[size + 1][j]);
}

int	vc_left(int **table, int i, int size)
{
	int	val;
	int	hold;
	int	j;

	j = 0;
	hold = 0;
	val = 0;
	while (++j < size + 1)
	{
		if (hold < table[i][j])
		{
			hold = table[i][j];
			val++;
		}
	}
	if (val > table[i][0])
		return (-1);
	return (val == table[i][0]);
}

int	vc_right(int **table, int i, int size)
{
	int	val;
	int	hold;
	int	j;

	j = size + 1;
	hold = 0;
	val = 0;
	while (--j > 0)
	{
		if (hold < table[i][j])
		{
			hold = table[i][j];
			val++;
		}
	}
	if (val > table[i][size + 1])
		return (-1);
	return (val == table[i][size + 1]);
}

int	vantage_checker(int **table, int size)
{
	int	i;
	int	j;
	int	val;

	val = 0;
	i = 0;
	while (++i < size + 1)
	{
		val += vc_left(table, i, size);
		val += vc_right(table, i, size);
	}
	j = 0;
	while (++j < size + 1)
	{
		val += vc_top(table, j, size);
		val += vc_bot(table, j, size);
	}
	if (table[1][3] == 3 && table[1][2] == 4)
		ft_printf("");
	return (val == size * 4);
}
