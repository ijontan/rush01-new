/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vantage_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:22:02 by itan              #+#    #+#             */
/*   Updated: 2023/02/18 23:30:56 by itan             ###   ########.fr       */
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
	while (++i < size)
	{
		if (hold < table[i][j])
		{
			hold = table[i][j];
			val++;
		}
	}
	return (val == table[0][j]);
}

int	vc_bot(int **table, int j, int size)
{
	int	val;
	int	hold;
	int	i;

	i = size + 2;
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
	return (val == table[0][j]);
}

int	vc_left(int **table, int i, int size)
{
	int	val;
	int	hold;
	int	j;

	j = 0;
	hold = 0;
	val = 0;
	while (++j < size)
	{
		if (hold < table[i][j])
		{
			hold = table[i][j];
			val++;
		}
	}
	return (val == table[i][0]);
}

int	vc_right(int **table, int i, int size)
{
	int	val;
	int	hold;
	int	j;

	j = size + 2;
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
	return (val == table[i][0]);
}

int	vantage_checker(int **table, int size)
{
	int	i;
	int	j;
	int	val;

	val = 0;
	i = 0;
	while (++i < size + 2)
	{
		val += vc_left(table, i, size);
		val += vc_right(table, i, size);
	}
	j = 0;
	while (++j < size + 2)
	{
		val += vc_top(table, j, size);
		val += vc_bot(table, j, size);
	}
	return (val == size * size);
}
