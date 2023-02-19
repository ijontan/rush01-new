/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:32:21 by itan              #+#    #+#             */
/*   Updated: 2023/02/19 16:29:54 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	back_track(int **table, int size, int new_i, int new_j);

int	check_val(int **table, int size, int i, int j)
{
	int	val;

	val = 0;
	if (table[i + 1][j + 1])
		return (0);
	while (++val <= size)
	{
		table[i + 1][j + 1] = val;
		if (!get_possible(table, i + 1, j + 1, size))
		{
			table[i + 1][j + 1] = 0;
			continue ;
		}
		if (i + 1 == size && j + 1 == size)
			if (vantage_checker(table, size))
				return (1);
		if (back_track(table, size, i, j + 1))
			return (1);
		table[i + 1][j + 1] = 0;
	}
	return (-1);
}

int	back_track(int **table, int size, int new_i, int new_j)
{
	int	i;
	int	j;
	int	handle;

	i = new_i - 1;
	j = new_j - 1;
	while (++i < size)
	{
		while (++j < size)
		{
			handle = check_val(table, size, i, j);
			if (handle == 1)
				return (1);
			else if (handle == -1)
				return (0);
		}
		if (!vc_left(table, i + 1, size) || !vc_right(table, i + 1, size))
			return (0);
		j = -1;
	}
	return (0);
}
